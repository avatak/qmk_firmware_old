#pragma once

/*
#define MARIO_THEME \
    Q__NOTE(_E5), \
    H__NOTE(_E5), \
    H__NOTE(_E5), \
    Q__NOTE(_C5), \
    H__NOTE(_E5), \
    W__NOTE(_G5), \
    Q__NOTE(_G4),

#define MARIO_GAMEOVER \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define MARIO_MUSHROOM \
    S__NOTE(_C5 ), \
    S__NOTE(_G4 ), \
    S__NOTE(_C5 ), \
    S__NOTE(_E5 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_C6 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_GS4), \
    S__NOTE(_C5 ), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_C6 ), \
    S__NOTE(_DS6), \
    S__NOTE(_GS6), \
    S__NOTE(_DS6), \
    S__NOTE(_AS4), \
    S__NOTE(_D5 ), \
    S__NOTE(_F5 ), \
    S__NOTE(_AS5), \
    S__NOTE(_D6 ), \
    S__NOTE(_F6 ), \
    S__NOTE(_AS6), \
    S__NOTE(_F6 ),


#define COIN_SOUND \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ONE_UP_SOUND \
    Q__NOTE(_E6  ),  \
    Q__NOTE(_G6  ),  \
    Q__NOTE(_E7  ),  \
    Q__NOTE(_C7  ),  \
    Q__NOTE(_D7  ),  \
    Q__NOTE(_G7  ),

#define SONIC_RING \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7),

#define ZELDA_PUZZLE \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),
*/
#undef ZELDA_TREASURE
#define ZELDA_TREASURE \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 ), \


/* Prelude music from Final Fantasy */
#define _FF_PRELUDE \
  M__NOTE(_C3, 20), M__NOTE(_D3, 20), M__NOTE(_E3, 20), M__NOTE(_G3, 20), \
  M__NOTE(_C4, 20), M__NOTE(_D4, 20), M__NOTE(_E4, 20), M__NOTE(_G4, 20), \
  M__NOTE(_C5, 20), M__NOTE(_D5, 20), M__NOTE(_E5, 20), M__NOTE(_G5, 20), \
  M__NOTE(_C6, 20), M__NOTE(_D6, 20), M__NOTE(_E6, 20), M__NOTE(_G6, 20), \
  M__NOTE(_C7, 20), M__NOTE(_G6, 20), M__NOTE(_E6, 20), M__NOTE(_D6, 20), \
  M__NOTE(_C6, 20), M__NOTE(_G5, 20), M__NOTE(_E5, 20), M__NOTE(_D5, 20), \
  M__NOTE(_C5, 20), M__NOTE(_G4, 20), M__NOTE(_E4, 20), M__NOTE(_D4, 20), \
  M__NOTE(_C4, 20), M__NOTE(_G3, 20), M__NOTE(_E3, 20), M__NOTE(_D3, 20), \
  M__NOTE(_A2, 20), M__NOTE(_B2, 20), M__NOTE(_C3, 20), M__NOTE(_E3, 20), \
  M__NOTE(_A3, 20), M__NOTE(_B3, 20), M__NOTE(_C4, 20), M__NOTE(_E4, 20), \
  M__NOTE(_A4, 20), M__NOTE(_B4, 20), M__NOTE(_C5, 20), M__NOTE(_E5, 20), \
  M__NOTE(_A5, 20), M__NOTE(_B5, 20), M__NOTE(_C6, 20), M__NOTE(_E6, 20), \
  M__NOTE(_A6, 20), M__NOTE(_E6, 20), M__NOTE(_C6, 20), M__NOTE(_B5, 20), \
  M__NOTE(_A5, 20), M__NOTE(_E5, 20), M__NOTE(_C5, 20), M__NOTE(_B4, 20), \
  M__NOTE(_A4, 20), M__NOTE(_E4, 20), M__NOTE(_C4, 20), M__NOTE(_B3, 20), \
  M__NOTE(_A3, 20), M__NOTE(_E3, 20), M__NOTE(_C3, 20), M__NOTE(_B2, 20),

/* Melody from the main themes of Star Trek TNG and the original series */
#define _TO_BOLDLY_GO \
  W__NOTE(_BF3),  \
  Q__NOTE(_EF4),  \
  WD_NOTE(_AF4),  \
  W__NOTE(_REST), \
  H__NOTE(_G4),   \
  Q__NOTE(_EF4),  \
  H__NOTE(_C4),   \
  W__NOTE(_REST), \
  QD_NOTE(_F4),   \
  M__NOTE(_BF4, 128 ),


/*
#define POP_GOES_THE_WEASLE \
    H__NOTE(_F3), Q__NOTE(_F3), H__NOTE(_G3), Q__NOTE(_G3), \
    Q__NOTE(_A3), Q__NOTE(_C4), Q__NOTE(_A3), H__NOTE(_F3), Q__NOTE(_C3), \
    H__NOTE(_F3), Q__NOTE(_F3), H__NOTE(_G3), Q__NOTE(_G3), \
    HD_NOTE(_A3), H__NOTE(_F3), Q__NOTE(_C3), \
    H__NOTE(_F3), Q__NOTE(_F3), H__NOTE(_G3), Q__NOTE(_G3), \
    Q__NOTE(_A3), Q__NOTE(_C4), Q__NOTE(_A3), HD_NOTE(_F3), \
    HD_NOTE(_D4), H__NOTE(_G3), Q__NOTE(_BF3), \
    HD_NOTE(_A3), HD_NOTE(_F3),
    */

#define HALL_OF_THE_MOUNTAIN_KING \
    Q__NOTE(_B2), Q__NOTE(_CS3), Q__NOTE(_D3), Q__NOTE(_E3), Q__NOTE(_FS3), Q__NOTE(_D3), H__NOTE(_FS3), \
    Q__NOTE(_F3), Q__NOTE(_CS3), H__NOTE(_F3), Q__NOTE(_E3), Q__NOTE(_C3), H__NOTE(_E3), \
    Q__NOTE(_B2), Q__NOTE(_CS3), Q__NOTE(_D3), Q__NOTE(_E3), Q__NOTE(_FS3), Q__NOTE(_D3), Q__NOTE(_FS3), Q__NOTE(_B3), \
    Q__NOTE(_A3), Q__NOTE(_F3), Q__NOTE(_D3), Q__NOTE(_F3), W__NOTE(_A3),
/*
#define HALL_OF_THE_MOUNTAIN_KING_SLOW \
    QD_NOTE(_B2), QD_NOTE(_CS3), QD_NOTE(_D3), QD_NOTE(_E3), QD_NOTE(_FS3), QD_NOTE(_D3), HD_NOTE(_FS3), \
    QD_NOTE(_F3), QD_NOTE(_CS3), HD_NOTE(_F3), QD_NOTE(_E3), QD_NOTE(_C3), HD_NOTE(_E3), \
    QD_NOTE(_B2), QD_NOTE(_CS3), QD_NOTE(_D3), QD_NOTE(_E3), QD_NOTE(_FS3), QD_NOTE(_D3), QD_NOTE(_FS3), QD_NOTE(_B3), \
    QD_NOTE(_A3), QD_NOTE(_F3), QD_NOTE(_D3), QD_NOTE(_F3), WD_NOTE(_A3),

#define JESU_JOY_SLOW \
    QD_NOTE(_B3), QD_NOTE(_G3), QD_NOTE(_A3), QD_NOTE(_B3), QD_NOTE(_D4), QD_NOTE(_C4), QD_NOTE(_C4), QD_NOTE(_E4), QD_NOTE(_D4), \
    QD_NOTE(_D4), QD_NOTE(_G4), QD_NOTE(_FS4), QD_NOTE(_G4), QD_NOTE(_D4), QD_NOTE(_B3), QD_NOTE(_G3), QD_NOTE(_A3), QD_NOTE(_B3), \
    QD_NOTE(_C4), QD_NOTE(_D4), QD_NOTE(_E4), QD_NOTE(_D4), QD_NOTE(_C4), QD_NOTE(_B3), QD_NOTE(_A3), QD_NOTE(_B3), QD_NOTE(_G3), \
    QD_NOTE(_F3), QD_NOTE(_G3), QD_NOTE(_A3), QD_NOTE(_D3), QD_NOTE(_F3), QD_NOTE(_A3), QD_NOTE(_C4), QD_NOTE(_B3), QD_NOTE(_A3), \
    QD_NOTE(_B3), QD_NOTE(_G3), QD_NOTE(_A3), QD_NOTE(_B3), QD_NOTE(_D4), QD_NOTE(_C4), QD_NOTE(_C4), QD_NOTE(_E4), QD_NOTE(_D4), \
    QD_NOTE(_D4), QD_NOTE(_G4), QD_NOTE(_FS4), QD_NOTE(_G4), QD_NOTE(_D4), QD_NOTE(_B3), QD_NOTE(_G3), QD_NOTE(_A3), QD_NOTE(_B3), \
    QD_NOTE(_C3), \
    QD_NOTE(_D4), QD_NOTE(_C4), QD_NOTE(_B3), QD_NOTE(_A3), QD_NOTE(_G3), QD_NOTE(_D3), QD_NOTE(_G3), QD_NOTE(_F3), \
    HD_NOTE(_G3),
    */

#define JESU_JOY \
    Q__NOTE(_B3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), Q__NOTE(_D4), Q__NOTE(_C4), Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_D4), \
    Q__NOTE(_D4), Q__NOTE(_G4), Q__NOTE(_FS4), Q__NOTE(_G4), Q__NOTE(_D4), Q__NOTE(_B3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), \
    Q__NOTE(_C4), Q__NOTE(_D4), Q__NOTE(_E4), Q__NOTE(_D4), Q__NOTE(_C4), Q__NOTE(_B3), Q__NOTE(_A3), Q__NOTE(_B3), Q__NOTE(_G3), \
    Q__NOTE(_F3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_D3), Q__NOTE(_F3), Q__NOTE(_A3), Q__NOTE(_C4), Q__NOTE(_B3), Q__NOTE(_A3), \
    Q__NOTE(_B3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), Q__NOTE(_D4), Q__NOTE(_C4), Q__NOTE(_C4), Q__NOTE(_E4), Q__NOTE(_D4), \
    Q__NOTE(_D4), Q__NOTE(_G4), Q__NOTE(_FS4), Q__NOTE(_G4), Q__NOTE(_D4), Q__NOTE(_B3), Q__NOTE(_G3), Q__NOTE(_A3), Q__NOTE(_B3), \
    Q__NOTE(_C3), \
    Q__NOTE(_D4), Q__NOTE(_C4), Q__NOTE(_B3), Q__NOTE(_A3), Q__NOTE(_G3), Q__NOTE(_D3), Q__NOTE(_G3), Q__NOTE(_F3), \
    H__NOTE(_G3),

#undef COIN_SOUND
#define COIN_SOUND \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),
