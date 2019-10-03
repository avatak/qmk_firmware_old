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

// Defines the keycodes used by our macros in process_record_user

enum layer_names{
    _COLEMAK = 0,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _ADJUST
};

#define ADJUST MO(_ADJUST)

#define KC_ADJ MO(_ADJUST)
#define KC_____ _______
#define KC_NESC LT(_NAV, KC_ESC)
#define KC_NSPC LT(_NAV, KC_SPC)
#define KC_NUMP TT(_NUM)
#define KC_TSPC LT(_TEX, KC_SPC)
#define KC_SYME LT(_SYM, KC_ENT)
#define KC_GSLN GUI_T(KC_SCLN)
#define KC_CSLH CTL_T(KC_SLSH)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_kc(
    /* Base */
        GRV , 1   , 2   , 3   , 4   , 5   ,                   6   , 7   , 8   , 9   , 0   , BSPC,\
        TAB , Q   , W   , F   , P   , B   ,                   J   , L   , U   , Y   , GSLN, BSLS,\
        NESC, A   , R   , S   , T   , G   ,                   K   , N   , E   , I   , O   , QUOT,\
        LSFT, Z   , X   , C   , D   , V   ,                   M   , H   , COMM, DOT , CSLH, RSFT,\
        ADJ , LCTL, LGUI, LALT,       NSPC,                   TSPC,       ____, ____, ____, ADJ ,\
                                      NUMP,                   SYME\
     ),

    [_NAV] = LAYOUT(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_TEX] = LAYOUT(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_SYM] = LAYOUT(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_NUM] = LAYOUT(/* Base */
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),

    [_ADJUST] = LAYOUT(/* Base */
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, _______,\
                                                             _______,   _______\
     ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }        
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }        
    }
}