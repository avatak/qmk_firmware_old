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

// Defines the keycodes used by our macros in process_record_user

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
    /* Base */
        KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC,\
        KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_BSLS,\
        NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT,\
        KC_LSFT, __COLEMAK_L3_______________________________,                   __COLEMAK_R3_______________________________, KC_RSFT,\
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT,          NAVSPC ,                   TEXSPC ,          KC_HYPR, ALTSHFT, ALTCTL , ADJUST ,\
                                                     TT(_NUM),                  SYMENT \
     ),

    [_NAV] = LAYOUT_wrapper(/* Base */
        _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______,\
        LNXWIN , __NAV_L1___________________________________,                   __NAV_R1___________________________________, S(LCTL(LALT(KC_S))),\,\ 
        _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, S(KC_F10), \,\
        _______, __NAV_L3___________________________________,                   __NAV_R3___________________________________, _______,\
        _______, _______, _______, _______,          _______,                   KC_ENT ,          _______, _______, _______, KC_F12 ,\
                                                             _______,   _______\
     ),

    [_TEX] = LAYOUT_wrapper(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______,\
        _______, __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______,\
        _______, __TEX_L3___________________________________,                   __TEX_R3___________________________________, _______,\
        _______, _______, _______, _______,          MO(_SYM),                  _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_SYM] = LAYOUT_wrapper(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, __FUNC_L___________________________________,                   __FUNC_R___________________________________, KC_F11 ,\
        KC_TILD, __SYM_L____________________________________,                   __SYM_R____________________________________, KC_F12 ,\
        KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_NUM] = LAYOUT_wrapper(/* Base */
        _______, _______, _______, _______, _______, _______,                   KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC, _______,   _______,\
        _______, _______, _______, _______, _______, _______,                   KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,   _______,\
        _______, _______, _______, _______, _______, _______,                   KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,   _______,\
        _______, _______, _______, _______, _______, _______,                   KC_P1  , KC_P2  , KC_P3  , KC_TAB , S(KC_TAB), _______,\
        _______, _______, _______, _______,          _______,                   KC_P0  ,          KC_PDOT, KC_ENT , S(KC_ENT),   _______,\
                                                             _______,   _______\
     ),

    [_ADJUST] = LAYOUT_wrapper(/* Base */
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, KC_UP  , _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, AU_TOG , _______, CK_TOGG, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, KC_DOWN, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),
};

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
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
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
            if (!clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (!clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (!clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        // DEFAULT
        else {
            if (!clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
#endif
