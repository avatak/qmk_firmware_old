/* Copyright 2020 avatak
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
    _COLEMAK,
    _NAV,
    _TEX,
    _SYM,
    _NUMPAD,
    _ADJUST
    };

// Layer shifts
    #define NAVESC LT(_NAV,KC_ESC)
    #define NAVSPC LT(_NAV,KC_SPC)
    #define TEXSPC LT(_TEX,KC_SPC)
    #define SYMENT LT(_SYM,KC_ENT)
    #define ADJUST MO(_ADJUST)
    #define NUMPAD MO(_NUMPAD)

// Mod taps
    #define ALTCOMM LALT_T(KC_COMM)
    #define GUISCLN LGUI_T(KC_SCLN)
    #define CTLSLSH LCTL_T(KC_SLSH)

// Shortcuts
    #define ALTF4   LALT(KC_F4)
    #define CTLPGDN LCTL(KC_PGDN)
    #define CTLPGUP LCTL(KC_PGUP)
    #define CTLHOME LCTL(KC_HOME)
    #define CTLEND  LCTL(KC_END)

    #define CTLLEFT LCTL(KC_LEFT)
    #define CTLBSPC LCTL(KC_BSPC)
    #define CTLDEL  LCTL(KC_DEL)
    #define CTLRGHT LCTL(KC_RGHT)
    #define CTLZERO LCTL(KC_0)
    #define TABLEFT S(LCTL(KC_TAB))
    #define TABRGHT LCTL(KC_TAB)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
        ALIGN = SAFE_RANGE,
        ARRAY,
        DISPMTH,
        ENUM,
        ITEM,
        ITEMIZE,
        LFTRGHT,
        LINEMTH
    };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_COLEMAK] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,\
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS,\
        NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,\
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                   KC_M   , KC_H   , ALTCOMM, KC_DOT , CTLSLSH, KC_RSFT,\
        ADJUST , KC_LCTL, KC_LALT, _______,     NAVSPC ,      NUMPAD , SYMENT ,     TEXSPC ,      KC_SPC , KC_SPC , KC_SPC , ADJUST \
    ),

    /* ADJUST */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, ALTF4  , _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, CTLPGDN, KC_PGUP, CTLPGUP, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, _______,\
        _______, CTLHOME, KC_HOME, KC_PGDN, KC_END , CTLEND ,                   CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, _______,\
        _______, _______, _______, KC_CAPS, KC_INS , KC_SLCK,                   CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , CTLZERO, _______,\
        _______, _______, _______, _______,     _______,      _______, _______,     KC_ENT ,      _______, _______, _______, KC_F12 \
    ),

    /* ADJUST */
    [_TEX] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, ENUM   , ITEMIZE, LFTRGHT, _______,                   _______, KC_LBRC, KC_RBRC, LINEMTH, DISPMTH, _______,\
        _______, ALIGN  , ARRAY  , _______, ITEM   , _______,                   _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,\
        _______, _______, _______, _______, _______, _______,                   KC_MINS, KC_UNDS, KC_PLUS, KC_EQL , KC_BSLS, _______,\
        _______, _______, _______, _______,     _______,      _______, _______,     _______,      _______, _______, _______, _______\
    ),

    /* ADJUST */
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,\
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,\
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,\
        _______, _______, _______, _______,     _______,      _______, _______,     _______,      _______, _______, _______, _______\
    ),

    /* ADJUST */
    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,     _______,      _______, _______,     _______,      _______, _______, _______, _______\
    ),

    /* ADJUST */
    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MPLY, KC_VOLU, _______, _______,\
        _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,\
        _______, _______, _______, _______,     _______,      _______, _______,     _______,      _______, KC_MUTE, _______, _______\
    ),
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
}
*/

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
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
