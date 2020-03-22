#include QMK_KEYBOARD_H
#include "avatak.h"

enum keymap_keycodes{
    ROCYCLE = NEW_SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrapper(
        KC_GRV ,    __NUMBER_L_________________________________,          __NUMBER_R_________________________________, KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,               ROCYCLE, \
        KC_TAB ,    __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_LBRC, KC_RBRC, KC_BSLS,               ADJUST,  \
        NAVESC ,    __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT,     KC_ENT ,                    S(LALT(LCTL(KC_S))), \
        KC_LSFT,    __COLEMAK_L3_______________________________,          KC_MINS, __COLEMAK_R3_______________________________,              KC_RSFT,               KC_UP  ,               \
    KC_LCTL, KC_LGUI,        KC_LALT,     NAVSPC ,    TT(_NUM) ,                          TEXSPC ,         S(KC_LCTL),          ALTCTL ,                   KC_LEFT, KC_DOWN, KC_RGHT           \
  ),

  [_COLEMAC] = LAYOUT_wrapper(
        KC_GRV ,    __NUMBER_L_________________________________,          __NUMBER_R_________________________________, KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,               ROCYCLE,        \
        KC_TAB ,    __COLEMAC_L1_______________________________,                   __COLEMAC_R1_______________________________, KC_LBRC, KC_RBRC, KC_BSLS,               _______,        \
        MNAVESC,    __COLEMAC_L2_______________________________,                   __COLEMAC_R2_______________________________, KC_QUOT,     KC_ENT ,                    KC_INS ,        \
        KC_LSFT,    __COLEMAC_L3_______________________________,          SYMENT , __COLEMAC_R3_______________________________,              KC_RSFT,               KC_UP  ,             \
        KC_LCTL, KC_LALT,        KC_LGUI,     MNAVSPC,    TT(_NUM) ,                          TEXSPC ,         S(KC_LCTL),          ALTCTL ,                   KC_LEFT, KC_DOWN, KC_RGHT \
  ),



  [_NAV] = LAYOUT_wrapper(
        _______,    _______, _______, _______, WINQUIT, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        _______,    __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, _______, _______,               _______,  \
        _______,    __NAV_L2___________________________________,                   __NAV_R2___________________________________, KC_APP ,     KC_APP ,                    _______, \
        _______,    __NAV_L3___________________________________,          KC_F12 , __NAV_R3___________________________________,              KC_MPLY,           KC_VOLU,                   \
    _______, _______,        _______,     _______,      _______,                        KC_ENT ,          S(LCTL(LALT(KC_S))),          KC_F12 ,       KC_MPRV, KC_VOLD, KC_MNXT           \
  ),

  [_MNAV] = LAYOUT_wrapper(
        _______,    _______, _______, _______, LGUI(KC_Q), _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        MACWIN ,    __MNAV_L1__________________________________,                   __MNAV_R1__________________________________, _______, _______, _______,               _______,  \
        _______,    __MNAV_L2__________________________________,                   __MNAV_R2__________________________________, KC_APP ,     KC_APP ,                    _______, \
        _______,    __MNAV_L3__________________________________,          MACTERM , __MNAV_R3__________________________________,              _______,          MACMENU,                   \
    _______, _______,        _______,     _______,      _______,                        KC_ENT ,          _______,          MACTERM,                   _______, _______, _______           \
  ),

    [_TEX] = LAYOUT_wrapper(
        _______,    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        _______,    __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______, _______, _______,               _______,  \
        _______,    __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______,     _______,                    _______, \
        _______,    __TEX_L3___________________________________,          _______, __TEX_R3___________________________________,              _______,           _______,                   \
    _______, _______,        _______,     MO(_SYM),     _______,                              _______,          _______,          ADJUST,                   _______, _______, _______           \
  ),

  [_SYM] = LAYOUT_wrapper(
        _______,    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        _______,    __FUNC_L___________________________________,                   __FUNC_R___________________________________, KC_F11 , KC_F12 , _______,               _______,  \
        KC_TILD,    __SYM_L____________________________________,                   __SYM_R____________________________________, _______,     _______,                    _______, \
        KC_GRV ,    __NUMBER_L_________________________________,          _______, __NUMBER_R_________________________________,              _______,           _______,                   \
    _______, _______,        _______,     _______,      _______,                        _______,          _______,          _______,                   _______, _______, _______           \
  ),

  [_MWIN] = LAYOUT_wrapper(
        _______,    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        _______,    _______, _______, _______, _______, _______,                   __MWIN_R1__________________________________, _______, _______, _______,               _______,  \
        _______,    _______, _______, _______, _______, _______,                   __MWIN_R2__________________________________, _______,     _______,                    _______, \
        _______,    _______, _______, _______, _______, _______,          _______, __MWIN_R3__________________________________,              _______,           _______,                   \
    _______, _______,        _______,     _______,      _______,                        MW_FULL,          _______,          _______,                   _______, _______, _______           \
  ),

  [_ADJUST] = LAYOUT_wrapper(
        RESET  ,    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,               _______, \
        _______,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______,               _______,  \
        _______,    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,     _______,                    _______, \
        _______,    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,              _______,           _______,                   \
    _______, _______,        _______,     COLEMAK,      _______,                        COLEMAC,          _______,          _______,                   _______, _______, _______           \
  ),

};

int encoder_state = 0;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ROCYCLE:
            if (record->event.pressed) {
                encoder_state = (encoder_state + 1) % 2;
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {

    // LEFT KNOB

        if (index == 0) {
            // NAV LAYER
            if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
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
                    tap_code16(LCTL(KC_Z));
                }
                else {
                    tap_code16(S(LCTL(KC_Z)));
                }
            }
            // ADJUST layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            // DEFAULT
            else {
                if (encoder_state == 0){
                    if (clockwise) {
                        tap_code(KC_DOWN);
                    } else {
                        tap_code(KC_UP);
                    }
                } else if (encoder_state == 1){
                    if (clockwise) {
                        tap_code(KC_RIGHT);
                    } else {
                        tap_code(KC_LEFT);
                    }
                }
            }
        }

// RIGHT KNOB

    else if (index == 1) {
        //  NAV LAYER
        if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
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
        // Adjust layer
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
