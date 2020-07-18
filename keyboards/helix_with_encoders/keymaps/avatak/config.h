/* Copyright 2019 Michael Shultz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here

#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/helix_with_encoders/glcdfont.c"

#define B7_AUDIO
//#define AUDIO_CLICKY
//#define NO_MUSIC_MODE

#define TAPPING_TERM 150

#define TAPPING_TOGGLE 2


#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

//#undef RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING

//#define NO_DEBUG
//#define NO_PRINT
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B

#define ENCODERS_PAD_A { B6 }
#define ENCODERS_PAD_B { B5 }

#define SPLIT_USB_DETECT

#define QMK_ESC_OUTPUT F4
#define QMK_ESC_INPUT D7
#define QMK_LED B0
#define QMK_SPEAKER B7
