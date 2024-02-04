#pragma once
#include <arduino.h>
#include "settings.h"
#include "avr_util.h"
#include "crt_gamma8.h"

namespace action_led
{
  enum Possible_States
  {
    ALL_OFF,
    WRITE_ON,
    WRITE_OFF,
    RED_ON,
    RED_OFF,
    RED_FAST_UP,
    RED_FAST_DOWN,
    RED_FAST_OFF
  };

  extern uint8 White_Brigh;
  extern uint8 Red_Brigh;
  extern boolean Red_States_Flag;

  extern void setup();
  extern void loop();

  extern void action(boolean door_states, uint8 light_states);
  byte GammaCorrection(byte val);
} //