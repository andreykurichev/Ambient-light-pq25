#pragma once

// Таблица поиска яркости гаммы <https://victornpb.github.io/gamma-table-generator>
// гамма = 1,80 шагов = 251 диапазон = 0-250
const uint8_t CRTgamma_White[224] PROGMEM = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    5,
    5,
    5,
    6,
    6,
    6,
    7,
    7,
    8,
    8,
    8,
    9,
    9,
    10,
    10,
    11,
    11,
    12,
    12,
    13,
    13,
    14,
    14,
    15,
    15,
    16,
    16,
    17,
    17,
    18,
    19,
    19,
    20,
    20,
    21,
    22,
    22,
    23,
    24,
    24,
    25,
    26,
    26,
    27,
    28,
    28,
    29,
    30,
    31,
    31,
    32,
    33,
    34,
    34,
    35,
    36,
    37,
    38,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    86,
    87,
    88,
    89,
    90,
    92,
    93,
    94,
    95,
    96,
    98,
    99,
    100,
    101,
    103,
    104,
    105,
    107,
    108,
    109,
    111,
    112,
    113,
    115,
    116,
    117,
    119,
    120,
    121,
    123,
    124,
    125,
    127,
    128,
    130,
    131,
    133,
    134,
    135,
    137,
    138,
    140,
    141,
    143,
    144,
    146,
    147,
    149,
    150,
    152,
    153,
    155,
    156,
    158,
    159,
    161,
    162,
    164,
    166,
    167,
    169,
    170,
    172,
    174,
    175,
    177,
    178,
    180,
    182,
    183,
    185,
    187,
    188,
    190,
    192,
    193,
    195,
    197,
    198,
    200,
    202,
    204,
    205,
    207,
    209,
    211,
    212,
    214,
    216,
    218,
    219,
    221,
    223,
};

// Таблица поиска яркости гаммы <https://victornpb.github.io/gamma-table-generator>
// гамма = 1,80 шагов = 65 диапазон = 0-64
const uint8_t CRTgamma_Red[86] PROGMEM = {
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    2,
    2,
    3,
    3,
    3,
    4,
    4,
    5,
    5,
    6,
    6,
    7,
    7,
    8,
    9,
    9,
    10,
    11,
    12,
    12,
    13,
    14,
    15,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    32,
    33,
    34,
    35,
    36,
    38,
    39,
    40,
    41,
    43,
    44,
    45,
    47,
    48,
    50,
    51,
    52,
    54,
    55,
    57,
    58,
    60,
    61,
    63,
    65,
    66,
    68,
    69,
    71,
    73,
    75,
    76,
    78,
    80,
    81,
    83,
    85,
};