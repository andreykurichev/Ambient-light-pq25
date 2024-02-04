#include "action_led.h"
#include "custom_module.h"
#include "avr_util.h"
#include "passive_timer.h"
#include "Adafruit_NeoPixel.h"
#include <avr/power.h>

namespace action_led
{
  Adafruit_NeoPixel rgb_leds = Adafruit_NeoPixel(1, RGB_PIN, NEO_GRB + NEO_KHZ800);
  Possible_States current_state;

  uint8 White_Brigh;
  uint8 Red_Brigh;
  uint8 light_Brigh;

  boolean Red_States_Flag;

  void setup()
  {
    DDRD |= H(PWR_RGB_PIN);
    PORTD |= H(PWR_RGB_PIN);
    DDRD |= H(WHITE_LED_PIN);
    PORTD &= ~H(WHITE_LED_PIN);
    White_Brigh = 0;
    Red_Brigh = 0;
    Red_States_Flag = false;
    rgb_leds.begin();
  }

  // Периодически вызывается из основного цикла() для выполнения переходов между состояниями.
  void loop()
  {
    switch (current_state)
    {
    case Possible_States::ALL_OFF:
      White_Brigh = 0;
      Red_Brigh = 0;
      break;

    case Possible_States::WRITE_ON:
      static PassiveTimer white_update_on_timer;
      if (white_update_on_timer.timeMillis() >= WHITE_UPDATE_PERIOD / WHITE_BRIGH_MAX)
      {
        white_update_on_timer.restart();
        if (White_Brigh < WHITE_BRIGH_MAX)
        {
          White_Brigh++;
        }
        uint8 bright = GammaCorrection(White_Brigh);
        rgb_leds.setPixelColor(0, WHITE_COLOR);
        rgb_leds.setBrightness(bright);
        analogWrite(WHITE_LED_PIN, bright);
        rgb_leds.show();
        Red_States_Flag = false;
      }
      break;

    case Possible_States::WRITE_OFF:
      static PassiveTimer white_update_off_timer;
      if (white_update_off_timer.timeMillis() >= WHITE_UPDATE_PERIOD / WHITE_BRIGH_MAX)
      {
        white_update_off_timer.restart();
        if (White_Brigh > WHITE_BRIGH_MIN)
        {
          White_Brigh--;
        }
        uint8 bright = GammaCorrection(White_Brigh);
        rgb_leds.setPixelColor(0, WHITE_COLOR);
        rgb_leds.setBrightness(bright);
        analogWrite(WHITE_LED_PIN, bright);
        rgb_leds.show();
      }
      break;

    case Possible_States::RED_ON: // плавно включаем
      static PassiveTimer red_update_on_timer;
      if (red_update_on_timer.timeMillis() >= RED_UPDATE_PERIOD / RED_BRIGH_MAX)
      {
        red_update_on_timer.restart();
        if (Red_Brigh < light_Brigh)
        {
          Red_Brigh++;
          if (Red_Brigh == light_Brigh)
          {
            Red_States_Flag = true;
          }
        }
        uint8 bright = GammaCorrection(Red_Brigh);
        rgb_leds.setPixelColor(0, RED_COLOR);
        rgb_leds.setBrightness(bright);
        rgb_leds.show();
      }
      break;

    case Possible_States::RED_OFF: // плавно выключаем
      static PassiveTimer red_update_off_timer;
      if (red_update_off_timer.timeMillis() >= RED_UPDATE_PERIOD / RED_BRIGH_MAX)
      {
        red_update_off_timer.restart();
        if (Red_Brigh > RED_BRIGH_OFF)
        {
          Red_Brigh--;
          if (Red_Brigh == RED_BRIGH_OFF)
          {
            Red_States_Flag = false;
          }
        }
        uint8 bright = GammaCorrection(Red_Brigh);
        rgb_leds.setPixelColor(0, RED_COLOR);
        rgb_leds.setBrightness(bright);
        rgb_leds.show();
      }
      break;

    case Possible_States::RED_FAST_UP: // быстро прибовляем
      if (Red_Brigh < light_Brigh)
      {
        Red_Brigh = light_Brigh;
        uint8 bright = GammaCorrection(Red_Brigh);
        rgb_leds.setPixelColor(0, RED_COLOR);
        rgb_leds.setBrightness(bright);
        rgb_leds.show();
      }
      break;

    case Possible_States::RED_FAST_DOWN: // быстро убовляем
      if (Red_Brigh > light_Brigh)
      {
        Red_Brigh = light_Brigh;
        uint8 bright = GammaCorrection(Red_Brigh);
        rgb_leds.setPixelColor(0, RED_COLOR);
        rgb_leds.setBrightness(bright);
        rgb_leds.show();
      }
      break;

    case Possible_States::RED_FAST_OFF: // быстро выключаем
      Red_Brigh = RED_BRIGH_OFF;
      rgb_leds.setPixelColor(0, OFF);
      rgb_leds.show();
      break;
    }
  }

  void action(boolean door_states, uint8 light_states)
  {
    if (door_states == false && light_states == 0) // все офф
    {
      if (White_Brigh == WHITE_BRIGH_MIN && Red_Brigh == RED_BRIGH_OFF)
      {
        current_state = Possible_States::ALL_OFF;
        return;
      }
    }

    if (door_states == true) // дверь открыта
    {
      if (Red_Brigh > RED_BRIGH_OFF)
      {
        current_state = Possible_States::RED_FAST_OFF;
        return;
      }
      if (White_Brigh < WHITE_BRIGH_MAX)
      {
        current_state = Possible_States::WRITE_ON;
        return;
      }
    }
    if (door_states == false) // дверь закрыта
    {
      light_Brigh = light_states;
      if (White_Brigh > WHITE_BRIGH_MIN)
      {
        current_state = Possible_States::WRITE_OFF;
        return;
      }

      else if (light_Brigh >= RED_BRIGH_MIN)
      {
        if (Red_Brigh < light_Brigh)
        {
          if (Red_States_Flag == false)
          {
            current_state = Possible_States::RED_ON;
            return;
          }
          else
          {
            current_state = Possible_States::RED_FAST_UP;
            return;
          }
        }
        else if (Red_Brigh > light_Brigh)
        {
          current_state = Possible_States::RED_FAST_DOWN;
          return;
        }
        else
        {
          return;
        }
      }
      else if (light_Brigh == 0)
      {
        if (Red_Brigh > RED_BRIGH_OFF)
        {
          current_state = Possible_States::RED_OFF;
        }
      }
    }
  }

  // функция возвращает скорректированное по CRT значение
  byte GammaCorrection(byte val)
  {
    return pgm_read_byte(&(CRTgamma8[val]));
  }
} // пространство имен action_led
