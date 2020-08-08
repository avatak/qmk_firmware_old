/* Copyright 2018 MechMerlin
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

#define KC_____ _______
#define KC_XXXX KC_NO
#define KC_CESC CTL_T(KC_ESC)

#define LAYOUT_kc( \
    k50, k52, k53, k54, k55, k60, k6A, k7A, k70, k5B, k5C, k5D, k5E, k1D, k2E, k0D, k76, k78, k79, \
    k40, k41, k42, k43, k44, k45, k61, k6B, k7B, k71, k4A, k4B, k4C, k4D, k4E, k46, k47, k48, k49, \
    k30, k31, k32, k33, k34, k35, k62, k6C, k7C, k72, k3A, k3B, k3C, k3D, k36, k37, k38, k39,      \
    k20, k21, k22, k23, k24, k25, k63, k6D, k7D, k73, k2A, k2B, k2C, k2D, k26, k27, k28, k29,      \
    k10, k03, k11, k12, k13, k14, k15, k64, k6E, k7E, k74, k1A, k1B, k68, k16, k17, k18, k19,      \
    k00, k01, k02, k65, k75, k0A, k0B, k66, k67, k69, k06, k08, k09                                \
) \
LAYOUT_all( \
    KC_##k50, KC_##k52, KC_##k53, KC_##k54, KC_##k55, KC_##k60, KC_##k6A, KC_##k7A, KC_##k70, KC_##k5B, KC_##k5C, KC_##k5D, KC_##k5E, KC_##k1D, KC_##k2E, KC_##k0D, KC_##k76, KC_##k78, KC_##k79, \
    KC_##k40, KC_##k41, KC_##k42, KC_##k43, KC_##k44, KC_##k45, KC_##k61, KC_##k6B, KC_##k7B, KC_##k71, KC_##k4A, KC_##k4B, KC_##k4C, KC_##k4D, KC_##k4E, KC_##k46, KC_##k47, KC_##k48, KC_##k49, \
    KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35, KC_##k62, KC_##k6C, KC_##k7C, KC_##k72, KC_##k3A, KC_##k3B, KC_##k3C, KC_##k3D, KC_##k36, KC_##k37, KC_##k38, KC_##k39,      \
    KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_##k63, KC_##k6D, KC_##k7D, KC_##k73, KC_##k2A, KC_##k2B, KC_##k2C, KC_##k2D, KC_##k26, KC_##k27, KC_##k28, KC_##k29,      \
    KC_##k10, KC_##k03, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_##k64, KC_##k6E, KC_##k7E, KC_##k74, KC_##k1A, KC_##k1B, KC_##k68, KC_##k16, KC_##k17, KC_##k18, KC_##k19,      \
    KC_##k00, KC_##k01, KC_##k02, KC_##k65, KC_##k75, KC_##k0A, KC_##k0B, KC_##k66, KC_##k67, KC_##k69, KC_##k06, KC_##k08, KC_##k09                                \
)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_kc( \
        ESC , F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , INS , DEL , HOME, END , PGUP, PGDN, \
        GRV , 1   , 2   , 3   , 4   , 5   , 6   , 7   , 8   , 9   , 0   , MINS, EQL , BSPC, BSPC, NLCK, PSLS, PAST, PMNS, \
        TAB ,       Q   , W   , E   , R   , T   , Y   , U   , I   , O   , P   , LBRC, RBRC, BSLS, P7  , P8  , P9  , ____,      \
        CESC,       A   , S   , D   , F   , G   , H   , J   , K   , L   , SCLN, XXXX, ENT , ____, P4  , P5  , P6  , ____,      \
        LSFT, XXXX, Z   , X   , C   , V   , B   , N   , M   , COMM, DOT , SLSH, RSFT, UP  , ____, P1  , P2  , P3  , ____,      \
        LCTL, LGUI, LALT, SPC , ____, ____, ____, ____, ____, ____, ____, ____, ____                                \
    ), \
    [0] = LAYOUT_kc( \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,      \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,      \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,      \
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____                                \
    ), \
};

