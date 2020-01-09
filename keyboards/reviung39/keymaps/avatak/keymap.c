/* Copyright 2019 gtips
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

#define LAYOUT_rev_wrapper(...) LAYOUT_reviung39(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_rev_wrapper(
    KC_TAB , __COLEMAK_L1_______________________________,          __COLEMAK_R1_______________________________, KC_BSPC,
    NAVESC , __COLEMAK_L2_______________________________,          __COLEMAK_R2_______________________________, KC_QUOT,
    KC_LSFT, __COLEMAK_L3_______________________________,          __COLEMAK_R3_______________________________, KC_RSFT,
                                                 NAVSPC , SYMENT , TEXSPC 
  ),

[_COLEMAC] = LAYOUT_rev_wrapper(
    KC_TAB , __COLEMAC_L1_______________________________,          __COLEMAC_R1_______________________________, KC_BSPC,
    MNAVESC, __COLEMAC_L2_______________________________,          __COLEMAC_R2_______________________________, KC_QUOT,
    KC_LSFT, __COLEMAC_L3_______________________________,          __COLEMAC_R3_______________________________, KC_RSFT,
                                                 MNAVSPC, SYMENT , TEXSPC 
),

[_NAV] = LAYOUT_rev_wrapper(
    _______, __NAV_L1___________________________________,          __NAV_R1___________________________________, WINQUIT,
    _______, __NAV_L2___________________________________,          __NAV_R2___________________________________, KC_APP ,
    KC_F12 , __NAV_L3___________________________________,          __NAV_R3___________________________________, _______,
                                                 _______, _______ , KC_ENT 
),

[_MNAV] = LAYOUT_rev_wrapper(
    MACWIN , __MNAV_L1__________________________________,          __MNAV_R1__________________________________, LGUI(KC_Q),
    _______, __MNAV_L2__________________________________,          __MNAV_R2__________________________________, KC_APP ,
    S(LALT(KC_T)), __MNAV_L3__________________________________,          __MNAV_R3__________________________________, _______,
                                                 _______, _______, KC_ENT 
),

[_TEX] = LAYOUT_rev_wrapper(
    _______, __TEX_L1___________________________________,          __TEX_R1___________________________________, _______,
    _______, __TEX_L2___________________________________,          __TEX_R2___________________________________, KC_APP ,
    _______, __TEX_L3___________________________________,          __TEX_R3___________________________________, ADJUST ,
                                                 MO(_SYM),_______, _______ 
),

[_MWIN] = LAYOUT_rev_wrapper(
    _______, _______, _______, _______, _______, _______,          __MWIN_R1__________________________________, _______,
    _______, _______, _______, _______, _______, _______,          __MWIN_R2__________________________________, KC_APP ,
    _______, _______, _______, _______, _______, _______,          __MWIN_R3__________________________________, ADJUST ,
                                                 _______, _______, MW_FULL 
),

[_SYM] = LAYOUT_rev_wrapper(
    _______, __FUNC_L___________________________________,          __FUNC_R___________________________________, _______,
    KC_TILD, __SYM_L____________________________________,          __SYM_R____________________________________, KC_APP ,
    KC_GRV , __NUMBER_L_________________________________,          __NUMBER_R_________________________________, _______,
                                                 _______, _______, _______ 
),
  
[_ADJUST] = LAYOUT_rev_wrapper(
    RESET  , _______, _______, _______, _______, _______,          _______, KC_MPLY, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, _______, _______, _______,
                                                 COLEMAK, _______, COLEMAC
),

};