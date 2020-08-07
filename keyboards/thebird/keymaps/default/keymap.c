/* Copyright 2020 Michael S.
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _ADJUST
};

#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT( \
        KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC ,       KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , \
        KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC ,       KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , \
        KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC ,       KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , \
        KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC ,       KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , \
        ADJUST , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC ,       KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC , KC_SPC  \
    ),


    [_ADJUST] = LAYOUT( \
        RESET  , _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
    ),
/*
    [_BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
    ),
*/
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}
