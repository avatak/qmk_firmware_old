/* Copyright 2019 avatak
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
#include QMK_KEYBOARD_H
#include "avatak.h"
#include "custom_songs.h"

enum KEYMAP_CUSTOM_KEYCODES {\
    VOICEUP = NEW_SAFE_RANGE,
    VOICEDN,
    HALL,
    JESU,
    POP,
    PRELUDE,
    WEASLE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrapper(\
  KC_GRV , __NUMBER_L_________________________________, KC_NLCK, _______, _______, __NUMBER_R_________________________________, KC_BSPC, \
  KC_TAB , __COLEMAK_L1_______________________________, KC_P7  , KC_P8  , KC_P9  , __COLEMAK_R1_______________________________, KC_BSLS, \
  NAVESC , __COLEMAK_L2_______________________________, KC_P4  , KC_P5  , KC_P6  , __COLEMAK_R2_______________________________, KC_QUOT, \
  KC_LSFT, __COLEMAK_L3_______________________________, KC_P1  , KC_P2  , KC_P3  , __COLEMAK_R3_______________________________, KC_RSFT, \
  ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , KC_P0  , KC_PDOT, SYMENT , TEXSPC , _______, _______, CTLSHIFT,ALTCTL , MEDIA \
  ),

  [_TEX] = LAYOUT_wrapper(\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, __TEX_L1___________________________________, _______, _______, _______, __TEX_R1___________________________________, _______, \
  _______, __TEX_L2___________________________________, _______, _______, _______, __TEX_R2___________________________________, _______, \
  _______, __TEX_L3___________________________________, _______, _______, _______, __TEX_R3___________________________________, _______, \
  _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_NAV] = LAYOUT_wrapper(\
  _______, _______, _______, _______, LALT(KC_F4), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, __NAV_L1___________________________________, _______, _______, _______, __NAV_R1___________________________________, _______, \
  _______, __NAV_L2___________________________________, _______, _______, _______, __NAV_R2___________________________________, _______, \
  _______, __NAV_L3___________________________________, _______, _______, _______, __NAV_R3___________________________________, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12  \
  ),


  [_SYM] = LAYOUT_wrapper(\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, __FUNC_L___________________________________, _______, _______, _______, __FUNC_R___________________________________, KC_F11 , \
  _______, __SYM_L____________________________________, _______, _______, _______, __SYM_R____________________________________, KC_F12 , \
  _______, __NUMBER_L_________________________________, _______, _______, _______, __NUMBER_R_________________________________, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),


  [_ADJUST] = LAYOUT_wrapper(\
  MU_TOG , PRELUDE, JESU   , HALL   , WEASLE , _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  , \
  _______, _______, _______, CK_UP  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  AU_ON  , AU_TOG , VOICEUP, CK_DOWN, VOICEDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  ),

  [_MEDIA] = LAYOUT_wrapper(\
  MU_TOG , PRELUDE, JESU   , HALL   , WEASLE , _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  , \
  _______, _______, _______, CK_UP  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  AU_ON  , AU_TOG , VOICEUP, CK_DOWN, VOICEDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (IS_LAYER_ON(_NAV)|IS_LAYER_ON(_MNAV)) {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
        }
        else if (IS_LAYER_ON(_TEX)) {
            if (clockwise) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
            }
        }
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
        }
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
        }
        else if (IS_LAYER_ON(_MEDIA)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        else
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
    }
// Second Encoder
    else if (index == 1) {
        if (IS_LAYER_ON(_NAV)|IS_LAYER_ON(_MNAV)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code16(KC_MNXT);
            } else {
                tap_code16(KC_MPRV);
            }
        }
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }

float tone_voice[][2] = SONG(VOICE_CHANGE_SOUND);
float tone_jesu[][2] = SONG(JESU_JOY);
float tone_ff[][2] = SONG(_FF_PRELUDE);
float tone_pop[][2] = SONG(POP_GOES_THE_WEASLE);
float tone_hall[][2] = SONG(HALL_OF_THE_MOUNTAIN_KING);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VOICEUP:
            if (record->event.pressed) {
                voice_iterate();
                PLAY_SONG(tone_voice);
            }
            break;
        case VOICEDN:
            if (record->event.pressed) {
                voice_deiterate();
                PLAY_SONG(tone_voice);
            }
            break;
        case JESU:
            if (record->event.pressed) {
                PLAY_SONG(tone_jesu);
            }
            break;
        case PRELUDE:
            if (record->event.pressed) {
                PLAY_SONG(tone_ff);
            }
            break;
        case HALL:
            if (record->event.pressed) {
                PLAY_SONG(tone_hall);
            }
            break;
        case WEASLE:
            if (record->event.pressed) {
                PLAY_SONG(tone_pop);
            }
            break;
    }
    return true;
}
