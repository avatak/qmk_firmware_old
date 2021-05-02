#include QMK_KEYBOARD_H

#include "avatak.h"

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = NEW_SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CLMK] = LAYOUT_wrapper(
        KC_GRV , __NUM_L____________________________________, XXXXXXX, XXXXXXX, __NUM_R____________________________________, KC_BSPC,
        KC_TAB , __CLMAC_L1_________________________________, XXXXXXX, XXXXXXX, __CLMAC_R1_________________________________, KC_BSLS,
        NAVESC , __CLMAC_L2_________________________________, _______, _______, __CLMAC_R2_________________________________  KC_QUOT,
        KC_LSFT, __CLMAC_L3_________________________________, ADJUST , UNDOIT , __CLMAC_R3_________________________________, KC_RSHT,
        KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NAVSPC , NUMTAP , SYMENT , TEXSPC , _______, _______, _______, _______, MEDIA  
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, __NAV_L0___________________________________, _______, _______, __NAV_R0___________________________________, _______,
        _______, __NAV_L1___________________________________, _______, _______, __NAV_R1___________________________________, _______,
        _______, __NAV_L2___________________________________, _______, _______, __NAV_R2___________________________________, KC_APP ,
        _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __TEX_L1___________________________________, _______, _______, __TEX_R1___________________________________, _______,
        _______, __TEX_L2___________________________________, _______, _______, __TEX_R2___________________________________, _______,
        _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 ,
        _______, __SYM_L2___________________________________, _______, _______, __SYM_R2___________________________________, KC_F12 ,
        _______, __SYM_L3___________________________________, _______, _______, __SYM_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_NLCK, KC_PAST, KC_PSLS, KC_BSPC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,S(KC_ENT), KC_P1  , KC_P2  , KC_P3  , KC_PEQL, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  KC_PENT, KC_P0  , KC_PDOT, _______, KC_TAB , S(KC_TAB), _______
    ),      

    [_MEDIA] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

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
