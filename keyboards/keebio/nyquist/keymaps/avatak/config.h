/*
Copyright 2017 Danny Nguyen <danny@hexwire.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define USE_SERIAL

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define TAPPING_TOGGLE 2

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { B2 }
#define ENCODER_RESOLUTION 4

#define QMK_ESC_OUTPUT D2 // usually COL
#define QMK_ESC_INPUT E6 // usually ROW
#define QMK_LED B0
#define QMK_SPEAKER C6
// sudo avrdude -c usbtiny -p m32u4 -P usb -U flash:w:"keebio_nyquist_rev2_avatak.hex":a -U lfuse:w:0x5E:m -U hfuse:w:0xD9:m -U efuse:w:0xC3:m -U lock:w:0x3F:m

//#define AUDIO_VOICES
#define C6_AUDIO
//#define AUDIO_CLICKY
#define NO_MUSIC

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
  #define RGBLED_NUM 14
  #define RGBLED_SPLIT {7, 7}
  // #define RGBLIGHT_ANIMATIONS
  // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif
