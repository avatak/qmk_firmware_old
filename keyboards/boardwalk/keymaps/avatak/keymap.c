/*
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

#define LAYOUT_wrap(...) LAYOUT_ortho_5x14(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 1uGrid
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | FN     | LALT   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | RIGHT  | DOWN   | UP     | RIGHT  |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_COLEMAK] = LAYOUT_wrap(
    KC_GRV , __NUMBER_L_________________________________, KC_MINS, KC_EQL,  __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB , __COLEMAK_L1_______________________________, KC_INS , KC_RBRC, __COLEMAK_R1_______________________________, KC_BSLS, \
    NAVESC , __COLEMAK_L2_______________________________, _______, _______, __COLEMAK_R2_______________________________, KC_QUOT,  \
    KC_LSFT, __COLEMAK_L3_______________________________, KC_CAPS, NUM_TOG, __COLEMAK_R3_______________________________, KC_RSFT, \
    ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUM_TAP, SYMENT , TEXSPC , _______, _______, _______, _______, ADJUST  \
 ),

[_COLEMAC] = LAYOUT_wrap(
    KC_GRV , __NUMBER_L_________________________________, KC_MINS, KC_EQL,  __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB , __COLEMAC_L1_______________________________, KC_INS , MACMENU, __COLEMAC_R1_______________________________, KC_BSLS, \
    MNAVESC, __COLEMAC_L2_______________________________, _______, _______ , __COLEMAC_R2_______________________________, KC_QUOT,  \
    KC_LSFT, __COLEMAC_L3_______________________________, KC_CAPS, NUM_TOG, __COLEMAC_R3_______________________________, KC_RSFT, \
    ADJUST , KC_LCTL, _______, KC_LALT, KC_LGUI, MNAVSPC, NUM_TAP, SYMENT , TEXSPC , _______, _______, _______, _______, ADJUST  \
),

[_NAV] = LAYOUT_wrap(
    NUM_TOG, _______, _______, _______, WINQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, __NAV_L1___________________________________, _______, _______, __NAV_R1___________________________________, _______, \
    _______, __NAV_L2___________________________________, _______, _______, __NAV_R2___________________________________, _______, \
    _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12
 ),

[_MNAV] = LAYOUT_wrap(
    NUM_TOG, _______, MACMENU, _______, MACQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    MACWIN , __MNAV_L1__________________________________, _______, _______, __MNAV_R1__________________________________, _______, \
    _______, __MNAV_L2__________________________________, _______, _______, __MNAV_R2__________________________________, _______, \
    _______, __MNAV_L3__________________________________, _______, _______, __MNAV_R3__________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, S(LALT(KC_T)) \
 ),

[_TEX] = LAYOUT_wrap(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, __TEX_L1___________________________________, _______, _______, __TEX_R1___________________________________, _______, \
    _______, __TEX_L2___________________________________, _______, _______, __TEX_R2___________________________________, _______, \
    _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______, \
    _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______
),

[_SYM] = LAYOUT_wrap(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, __FUNC_L___________________________________, _______, _______, __FUNC_R___________________________________, KC_F11 , \
    KC_TILD, __SYM_L____________________________________, _______, _______, __SYM_R____________________________________, KC_F12 , \
    KC_GRV , __NUMBER_L_________________________________, _______, _______, __NUMBER_R_________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT_wrap(
   TG(_NUM), _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_TAB , S(KC_TAB), _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_COMM, KC_PDOT, KC_PENT, S(KC_ENT)   , _______
),

[_MWIN] = LAYOUT_wrap(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, __MWIN_R1__________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, __MWIN_R2__________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, __MWIN_R3__________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, MW_FULL, _______, _______, _______, _______, _______ \
),

/* FUNCTION
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


[_ADJUST] = LAYOUT_wrap(
    RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
    _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, KC_MUTE, _______, _______ \
)

};
