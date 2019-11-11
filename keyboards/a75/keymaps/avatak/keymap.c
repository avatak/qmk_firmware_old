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

enum keyboard_custom_keycodes {
    
    HALLOFM = NEW_SAFE_RANGE,
    JESUJOY,
    PRELUDE,
    VOICEDN,
    VOICEUP,
    ZELDA_T,
};

float tone_prelude[][2] = SONG(_FF_PRELUDE);
float tone_mountain[][2] = SONG(HALL_OF_THE_MOUNTAIN_KING_SLOW);
float tone_jesu[][2] = SONG(JESU_JOY_SLOW);
float tone_treasure[][2] = SONG(ZELDA_TREASURE);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_COLEMAK] = LAYOUT_wrapper(
        KC_GRV , __NUMBER_L_________________________________, KC_NLCK, _______, _______, __NUMBER_R_________________________________, KC_BSPC, \
        KC_TAB , __COLEMAK_L1_______________________________, KC_P7  , KC_P8  , KC_P9  , __COLEMAK_R1_______________________________, KC_BSLS, \
        NAVESC , __COLEMAK_L2_______________________________, KC_P4  , KC_P5  , KC_P6  , __COLEMAK_R2_______________________________, KC_QUOT, \
        KC_LSFT, __COLEMAK_L3_______________________________, KC_P1  , KC_P2  , KC_P3  , __COLEMAK_R3_______________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , KC_P0  , KC_PDOT, SYMENT , TEXSPC , _______, CTLSHFT, ALTSHFT, ALTCTL , ADJUST  \
    ),

    [_COLEMAC] = LAYOUT_wrapper(
        KC_GRV , __NUMBER_L_________________________________, KC_NLCK, _______, _______, __NUMBER_R_________________________________, KC_BSPC, \
        KC_TAB , __COLEMAC_L1_______________________________, KC_P7  , KC_P8  , KC_P9  , __COLEMAC_R1_______________________________, KC_BSLS, \
        MNAVESC, __COLEMAC_L2_______________________________, KC_P4  , KC_P5  , KC_P6  , __COLEMAC_R2_______________________________, KC_QUOT, \
        KC_LSFT, __COLEMAC_L3_______________________________, KC_P1  , KC_P2  , KC_P3  , __COLEMAC_R3_______________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, MNAVSPC, KC_P0  , KC_PDOT, SYMENT , TEXSPC , _______, CTLSHFT, ALTSHFT, ALTCTL , ADJUST  \
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, _______, _______, _______, WINQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________, _______, _______, _______, __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________, _______, _______, _______, __NAV_R2___________________________________, _______, \
        _______, __NAV_L3___________________________________, _______, _______, _______, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12  \
    ),

    [_MNAV] = LAYOUT_wrapper(
        _______, _______, _______, _______, WINQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __MNAV_L1__________________________________, _______, _______, _______, __MNAV_R1__________________________________, _______, \
        _______, __MNAV_L2__________________________________, _______, _______, _______, __MNAV_R2__________________________________, _______, \
        _______, __MNAV_L3__________________________________, _______, _______, _______, __MNAV_R3__________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12  \
    ),

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, _______, _______, _______, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, _______, _______, _______, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______, _______, _______, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12  \
    ),

    [_SYM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __FUNC_L___________________________________, _______, _______, _______, __FUNC_R___________________________________, KC_F11 , \
        KC_TILD, __SYM_L____________________________________, _______, _______, _______, __SYM_R____________________________________, KC_F12 , \
        KC_GRV , __NUMBER_L_________________________________, _______, _______, _______, __NUMBER_R_________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_ADJUST] = LAYOUT_wrapper(
        RESET  , HALLOFM, PRELUDE, JESUJOY, ZELDA_T, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, CK_UP  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG , VOICEDN, CK_DOWN, VOICEUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, COLEMAK, _______, _______, _______, COLEMAC, _______, _______, _______, _______, _______ \
    ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HALLOFM:
            if (record->event.pressed) {
                PLAY_SONG(tone_mountain);
            }
            break;
        case JESUJOY:
            if (record->event.pressed) {
                PLAY_SONG(tone_jesu);
            }
            break;
        case PRELUDE:
            if (record->event.pressed) {
                PLAY_SONG(tone_prelude);
            }
            break;
        case VOICEDN:
            if (record->event.pressed) {
                voice_deiterate();
                PLAY_SONG(tone_treasure);
            }
            break;
        case VOICEUP:
            if (record->event.pressed) {
                voice_iterate();
                PLAY_SONG(tone_treasure);
            }
            break;
        case ZELDA_T:
            if (record->event.pressed) {
                PLAY_SONG(tone_treasure);
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {

    // LEFT KNOB

        if (index == 0) {
            // NAV LAYER
            if (IS_LAYER_ON(_NAV)) {
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            // TEX Layer
            else if (IS_LAYER_ON(_TEX)) {
                if (clockwise) {
                    register_code(KC_LSFT);
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_LCTL);
                }
                else {
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LSFT);
                }
            }
            // ADJUST layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            // DEFAULT
            else {
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            }
        }

// RIGHT KNOB

    else if (index == 1) {
        //  NAV LAYER
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        // DEFAULT
        else {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
#endif
