#pragma once
#include "avatak.h"

#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define __NUM_L____________________________________     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define __NUM_R____________________________________     KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define __CLMK_L1__________________________________     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define __CLMK_L2__________________________________     KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define __CLMK_L3__________________________________     KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define __CLMK_R1__________________________________     KC_J,    KC_L,    KC_U,    KC_Y,    GUISCLN
#define __CLMK_R2__________________________________     KC_K,    KC_N,    KC_E,    KC_I,    KC_O
#define __CLMK_R3__________________________________     KC_M,    KC_H,    ALTCOMM, GUIDOT,  CTLSLSH

#define __NAV_L0___________________________________     _______, LALT(KC_F2), _______, LALT(KC_F4), _______
#define __NAV_L1___________________________________    LALT(KC_F2),CTLPGUP, KC_PGUP, CTLPGDN, _______
#define __NAV_L2___________________________________     _______, KC_HOME, KC_PGDN, KC_END,  _______
#define __NAV_L3___________________________________     _______, KC_SLCK, KC_CAPS, KC_INS,  _______

#define __NAV_R1___________________________________     _______, TABLEFT, KC_UP,   TABRGHT, _______
#define __NAV_R2___________________________________     CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT
#define __NAV_R3___________________________________     CTLBSPC, KC_BSPC, KC_DEL,  CTLDEL,  CTLZERO

#define __TEX_L1___________________________________     _______, _______, ENUM,    ITEMIZE, _______
#define __TEX_L2___________________________________     ALIGN,   _______, _______, ITEM,    _______
#define __TEX_L3___________________________________     _______, _______, _______, _______, _______

#define __TEX_R1___________________________________     _______, KC_LBRC, KC_RBRC, DISPMTH, LINEMTH
#define __TEX_R2___________________________________     KC_PIPE, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN
#define __TEX_R3___________________________________     KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_BSLS

#define __SYM_L1___________________________________     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define __SYM_L2___________________________________     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define __SYM_L3___________________________________     KC_1,    KC_2,    KC_3,    KC_4,    KC_5

#define __SYM_R1___________________________________     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define __SYM_R2___________________________________     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define __SYM_R3___________________________________     KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define __NP_0____________________________              KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC
#define __NP_1____________________________              KC_P7,   KC_P8,   KC_P9,   KC_PMNS
#define __NP_2____________________________              KC_P4,   KC_P5,   KC_P6,   KC_PPLS
#define __NP_3____________________________              KC_P1,   KC_P2,   KC_P3,   KC_TAB
#define __NP_4____________________________              KC_P0,   KC_COMM, KC_PDOT, KC_PENT

#define __ADJ_L1___________________________________     RGB_TOG, _______, CK_UP  , _______, _______
#define __ADJ_L2___________________________________     AU_TOG , _______, CK_DOWN, _______, _______
#define __ADJ_L3___________________________________     _______, _______, CK_TOGG, _______, _______

#define __ADJ_R1___________________________________     _______, _______, _______, _______, _______
#define __ADJ_R2___________________________________     _______, _______, KC_MPLY, KC_VOLU, _______
#define __ADJ_R3___________________________________     _______, _______, KC_MPRV, KC_VOLD, KC_MNXT


// #define ___________________________________________
