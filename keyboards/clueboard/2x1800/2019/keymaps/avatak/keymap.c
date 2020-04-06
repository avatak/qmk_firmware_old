/* Copyright 2017 Zach White <skullydazed@gmail.com>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all( \
    ENC_BTN1, ENC_BTN2, ENC_BTN3, ENC_BTN4, \
    \
    _______, _______, _______, _______,                  KC_ESC ,    KC_F1  , KC_F2  , KC_F3  , KC_F4  ,     KC_F5  ,   KC_F6  ,   KC_F7  ,   KC_F8  ,     KC_F9  , KC_F10 ,   KC_F11 ,   KC_F12 ,          _______, _______, _______, KC_BSPC,  \
                                                                                                                                                                                                                      \
    _______, _______, _______, _______,                  KC_GRV , __NUMBER_L_________________________________, __NUMBER_R_________________________________, KC_MINS, KC_EQL ,         KC_BSPC,              KC_NLCK, _______, _______, _______, \
    _______, _______, _______, _______,                  KC_TAB , __COLEMAK_L1_______________________________, __COLEMAK_R1_______________________________, KC_LBRC, KC_RBRC, KC_BSLS,                      _______, _______, _______, _______,       \
             _______, _______, _______,                  NAVESC , __COLEMAK_L2_______________________________, __COLEMAK_R2_______________________________, KC_QUOT, KC_ENT , KC_ENT ,                      _______, _______, _______,                \
    _______, _______, _______, _______,      KC_PGUP,    KC_LSFT, __COLEMAK_L3_______________________________, __COLEMAK_R3_______________________________, KC_RSFT,           KC_UP  ,                     _______, _______, _______, _______,       \
             _______, _______,      KC_HOME, KC_PGDN, KC_END ,    KC_LCTL, KC_LGUI, KC_LALT, NAVSPC , SYMENT , TEXSPC , _______, _______, _______, _______, ADJUST ,  KC_LEFT, KC_DOWN, KC_RGHT,                              _______, _______               \
),

/*
[0] = LAYOUT_all( \
    ENC_BTN1, ENC_BTN2, ENC_BTN3, ENC_BTN4, \
    \
    _______, _______, _______, _______,                  _______,    _______, _______, _______, _______,     _______,   _______,   _______,   _______,     _______,   _______,   _______,  _______,         _______, _______, _______, _______,  \
                                                                                                                                                                                                                      \
    _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,              _______, _______, _______, _______, \
    _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______,       \
             _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______,                \
    _______, _______, _______, _______,      _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,                     _______, _______, _______, _______,       \
             _______, _______,      _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,                              _______, _______               \
)
*/
};
