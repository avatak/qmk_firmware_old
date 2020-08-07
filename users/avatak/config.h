#pragma once


#ifdef AUDIO_ENABLE

#endif

#ifdef OLED_DRIVER_ENABLE
#   ifdef OLED_FONT_H
#       undef OLED_FONT_H
#   endif
#   define OLED_FONT_H "users/avatak/glcdfont_custom.c"
//#   define OLED_FONT_WIDTH 8
#endif


#ifndef TAPPING_TERM
#   define TAPPING_TERM 150
#endif
#ifndef TAPPING_TOGGLE
#   define TAPPING_TOGGLE 2
#endif


// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
