#pragma once

// Таблица поиска яркости гаммы <https://victornpb.github.io/gamma-table-generator>
// гамма = 1,80 шагов = 251 диапазон = 0-250
const uint8_t CRTgamma_White[251] PROGMEM = {
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
    23,
    24,
    25,
    25,
    26,
    27,
    27,
    28,
    29,
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
    37,
    38,
    39,
    40,
    41,
    41,
    42,
    43,
    44,
    45,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
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
    77,
    78,
    79,
    80,
    81,
    82,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    93,
    94,
    95,
    96,
    97,
    98,
    100,
    101,
    102,
    103,
    105,
    106,
    107,
    108,
    109,
    111,
    112,
    113,
    114,
    116,
    117,
    118,
    120,
    121,
    122,
    124,
    125,
    126,
    128,
    129,
    130,
    132,
    133,
    134,
    136,
    137,
    138,
    140,
    141,
    143,
    144,
    145,
    147,
    148,
    150,
    151,
    153,
    154,
    155,
    157,
    158,
    160,
    161,
    163,
    164,
    166,
    167,
    169,
    170,
    172,
    173,
    175,
    176,
    178,
    180,
    181,
    183,
    184,
    186,
    187,
    189,
    191,
    192,
    194,
    195,
    197,
    199,
    200,
    202,
    204,
    205,
    207,
    208,
    210,
    212,
    213,
    215,
    217,
    219,
    220,
    222,
    224,
    225,
    227,
    229,
    231,
    232,
    234,
    236,
    238,
    239,
    241,
    243,
    245,
    246,
    248,
    250,
};

// Таблица поиска яркости гаммы <https://victornpb.github.io/gamma-table-generator>
// гамма = 1,80 шагов = 65 диапазон = 0-64
const uint8_t CRTgamma_Red[65] PROGMEM = {
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    1,
    2,
    2,
    2,
    3,
    3,
    4,
    4,
    5,
    5,
    6,
    7,
    7,
    8,
    9,
    9,
    10,
    11,
    12,
    13,
    14,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    22,
    23,
    24,
    25,
    26,
    27,
    29,
    30,
    31,
    33,
    34,
    35,
    37,
    38,
    40,
    41,
    43,
    44,
    46,
    47,
    49,
    50,
    52,
    54,
    55,
    57,
    59,
    60,
    62,
    64,
};