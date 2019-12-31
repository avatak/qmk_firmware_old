#include QMK_KEYBOARD_H
#include "avatak.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper(
        KC_GRV , __NUMBER_L_________________________________, __NUMBER_R_________________________________, KC_MINS, KC_EQL , KC_BSPC, KC_BSPC, \
        KC_TAB , __COLEMAK_L1_______________________________, __COLEMAK_R1_______________________________, KC_LBRC, KC_RBRC, KC_BSLS, \
        NAVESC , __COLEMAK_L2_______________________________, __COLEMAK_R2_______________________________, KC_QUOT, KC_ENT , \
        KC_LSFT, __COLEMAK_L3_______________________________, __COLEMAK_R3_______________________________, KC_RSFT, ADJUST , \
        KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NAVSPC ,          TEXSPC , TEXSPC , _______, CTLSHFT, ALTCTL , ADJUST
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, _______, _______, _______, WINQUIT, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, \
        _______, __NAV_L1___________________________________, __NAV_R1___________________________________, KC_MPRV, KC_MNXT, KC_MPLY, \
        _______, __NAV_L2___________________________________, __NAV_R2___________________________________, _______, KC_APP , \
        _______, __NAV_L3___________________________________, __NAV_R3___________________________________, _______, _______, \
        _______, _______, _______, _______, _______, _______,          KC_ENT , KC_ENT , _______, _______, _______, KC_F12
    ),

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, __TEX_R1___________________________________, _______, _______, _______, \
        _______, __TEX_L2___________________________________, __TEX_R2___________________________________, _______, _______, \
        _______, __TEX_L3___________________________________, __TEX_R3___________________________________, _______, _______, \
        _______, _______, _______, _______, _______, MO(_SYM),          _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __FUNC_L___________________________________, __FUNC_R___________________________________, _______, _______, _______, \
        KC_TILD, __SYM_L____________________________________, __SYM_R____________________________________, _______, _______, \
        KC_GRV , __NUMBER_L_________________________________, __NUMBER_R_________________________________, _______, _______, \
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  , RESET  , \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
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
            } else {
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
            }
        }
        // MEDIA layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
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
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // MEDIA layer
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
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
}
#endif
