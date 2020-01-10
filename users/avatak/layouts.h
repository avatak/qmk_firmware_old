#pragma once
#include "avatak.h"

#if (!defined(LAYOUT) && defined(KEYMAP))
#   define LAYOUT KEYMAP
#endif

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// COLEMAK MOD-DH
#define __COLEMAK_L1_______________________________ ALT_Q  , KC_W   , KC_F   , KC_P   , KC_B
#define __COLEMAK_L2_______________________________ KC_A   , KC_R   , KC_S   , KC_T   , KC_G
#define __COLEMAK_L3_______________________________ KC_Z   , KC_X   , KC_C   , KC_D   , KC_V

#define __COLEMAK_R1_______________________________ KC_J   , KC_L   , KC_U   , KC_Y   , GUI_SCLN
#define __COLEMAK_R2_______________________________ KC_K   , KC_N   , KC_E   , KC_I   , KC_O
#define __COLEMAK_R3_______________________________ KC_M   , KC_H   , ALT_COM, KC_DOT , CTL_SLSH

// COLEMAK MOD-DH FOR OSX
#define __COLEMAC_L1_______________________________ KC_Q   , KC_W   , KC_F   , KC_P   , KC_B
#define __COLEMAC_L2_______________________________ KC_A   , KC_R   , KC_S   , KC_T   , KC_G
#define __COLEMAC_L3_______________________________ KC_Z   , KC_X   , KC_C   , KC_D   , KC_V

#define __COLEMAC_R1_______________________________ KC_J   , KC_L   , KC_U   , KC_Y   , CTL_SCLN
#define __COLEMAC_R2_______________________________ KC_K   , KC_N   , KC_E   , KC_I   , KC_O
#define __COLEMAC_R3_______________________________ KC_M   , KC_H   , ALT_COM, KC_DOT , GUI_SLSH

// NAVIGATION LAYER
#define __NAV_L0___________________________________ S(LALT(KC_1)), S(LALT(KC_2)), S(LALT(KC_3)), LALT(KC_F4), _______
#define __NAV_L1___________________________________ _______, LCTL(KC_PGDN), KC_PGUP, LCTL(KC_PGUP),     _______
#define __NAV_L2___________________________________ LCTL(KC_HOME), KC_HOME, KC_PGDN, KC_END ,     LCTL(KC_END)
#define __NAV_L3___________________________________ _______, _______, KC_CAPS, KC_INS ,     KC_SLCK

#define __NAV_R0___________________________________ _______,       _______, _______, _______,      _______
#define __NAV_R1___________________________________ _______,       TABLEFT, KC_UP  , TABRIGHT,     _______
#define __NAV_R2___________________________________ LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT,      LCTL(KC_RGHT)
#define __NAV_R3___________________________________ LCTL(KC_BSPC), KC_BSPC, KC_DEL , LCTL(KC_DEL), LCTL(KC_0)

// NAVIGATION LAYER (FOR OSX)
#define __MNAV_L0__________________________________ LGUI(LALT(1)), LGUI(LALT(2)),       LGUI(LALT(3)), LGUI(KC_Q),    _______
#define __MNAV_L1__________________________________ _______, _______,       KC_PGUP, _______,       _______
#define __MNAV_L2__________________________________ _______, LGUI(KC_LEFT), KC_PGDN, LGUI(KC_RGHT), _______
#define __MNAV_L3__________________________________ _______, _______,       KC_CAPS, KC_INS ,       LCTL(KC_0)

#define __MNAV_R0__________________________________ _______,       _______, _______, _______,      _______
#define __MNAV_R1__________________________________ _______,       TABLEFT, KC_UP  , TABRIGHT,     _______
#define __MNAV_R2__________________________________ LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT,      LALT(KC_RGHT)
#define __MNAV_R3__________________________________ LALT(KC_BSPC), KC_BSPC, KC_DEL , LALT(KC_DEL), LCTL(KC_0)

// NUMBERS
#define __NUMBER_L_________________________________ KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define __NUMBER_R_________________________________ KC_6   , KC_7   , KC_8   , KC_9   , KC_0

// SYMBOLS
#define __SYM_L____________________________________ KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
#define __SYM_R____________________________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// FUNCTION ROW
#define __FUNC_L___________________________________ KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5
#define __FUNC_R___________________________________ KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10

// LATEX LAYER
#define __TEX_L1___________________________________ SECTION, ENUMERATE, ITEMIZE, LEFTRIGHT, _______
#define __TEX_L2___________________________________ ALIGN  , ARRAY    , _______, ITEM     , _______
#define __TEX_L3___________________________________ LEMMA  , THEOREM  , _______, _______  , _______

#define __TEX_R1___________________________________ _______, KC_LBRC  , KC_RBRC, LINEMATH , DISPMATH
#define __TEX_R2___________________________________ _______, KC_LCBR  , KC_RCBR, KC_LPRN  , KC_RPRN
#define __TEX_R3___________________________________ KC_MINS, KC_UNDS  , KC_PLUS, KC_EQL   , KC_BSLS

// MACWIN ADJUSTMENT

#define __MWIN_R1__________________________________  MW_L13 , MW_ULFT, MW_UPPR, MW_URIT, MW_R13
#define __MWIN_R2__________________________________  MW_LEFT, MW_L23 , MW_CENT, MW_R23 , MW_RGHT
#define __MWIN_R3__________________________________  MW_L13 , MW_LLFT, MW_LOWR, MW_LRIT, MW_R13

// LINUX WINDOW ADJUSTMENT
#define __LWIN_R1__________________________________  _______, LW_ULFT, LW_UP  , LW_URGT, _______
#define __LWIN_R2__________________________________  _______, LW_LEFT, LW_NXTW, LW_RGHT, _______
#define __LWIN_R3__________________________________  _______, LW_LLFT, LW_DOWN, LW_LRGT, _______
