#include QMK_KEYBOARD_H
#include "avatak.h"

#define _COLEMAK _CLMK

enum keymap_custom_keycodes {
    TCH_TOG = NEW_SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
        KC_GRV , __NUM_L____________________________________, XXXXXXX,   TCH_TOG, __NUM_R____________________________________, KC_BSPC, \
        KC_TAB , __CLMK_L1__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R1__________________________________, KC_BSLS, \
        NAVESC , __CLMK_L2__________________________________, KC_INS ,   APPMENU, __CLMK_R2__________________________________, KC_QUOT, \
        KC_LSFT, __CLMK_L3__________________________________, KC_CAPS,   APPSRCH, __CLMK_R3__________________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NUMTAP ,   SYMENT , TEXSPC , _______, CTLSHFT, ALTCTL , ALTCTLS, MEDIA    \
    ),

  [_NAV] = LAYOUT_wrapper( \
        _______, __NAV_L0___________________________________, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________, _______,   _______, __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________, _______,   _______, __NAV_R2___________________________________, KC_APP , \
        _______, __NAV_L3___________________________________, _______,   _______, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_F12  \
    ),

    [_TEX] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, _______,   _______, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, _______,   _______, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______,   _______, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 , \
        KC_TILD, __SYM_L2___________________________________, _______, _______, __SYM_R2___________________________________, KC_F12 , \
        KC_GRV , __SYM_L3___________________________________, _______, _______, __SYM_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_NUM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_0____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_1____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_2____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_3____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_4____________________________ \
    ),

    [_MEDIA] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MUTE, _______, _______ \
    ),

    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______, _______,   _______, _______, RGB_VAD, _______, RGB_VAI, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, RGB_SPD, RGB_HUI, RGB_SPI, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, RGB_RMOD,RGB_HUD, RGB_MOD, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, RGB_SAD, _______, RGB_SAI, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______
    ),
};

// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS]  = {
    [_COLEMAK] = TOUCH_ENCODER_LAYOUT( \
        KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
        KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
    ),
    [_NAV] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_SYM] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_ADJUST] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS][ENCODER_OPTIONS]  = {
    [_COLEMAK] = ENCODER_LAYOUT( \
        KC_DOWN, KC_UP  ,
        LCTL(KC_LEFT),LCTL(KC_RIGHT),
        KC_LEFT, KC_RGHT,
        KC_PGDN, KC_PGUP
    ),
    [_NAV] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

/*
#if defined(OLED_DRIVER_ENABLE)
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _TEX:
            oled_write_ln_P(PSTR("LaTeX"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
*/
