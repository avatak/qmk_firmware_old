#include "encoder_custom.h"


bool encoder_update_user(uint8_t index, bool clockwise) {
    /* Left encoder */
    if (index == 0) {
        switch(get_highest_layer(layer_state)) {
            case _CLMK:
                if (clockwise) {
                    tap_code16(KC_DOWN);
                } else {
                    tap_code16(KC_UP);
                }
                break;
            case _NAV:
                if (clockwise) {
                    tap_code16(LGUI(KC_DOWN));
                } else {
                    tap_code16(LGUI(KC_UP));
                }
                break;
            case _TEX:
                if (clockwise) {
                    register_code16(KC_LCTL);
                    tap_code16(KC_Z);
                    unregister_code16(KC_LCTL);
                } else {
                    register_code16(S(KC_LCTL));
                    tap_code16(KC_Z);
                    unregister_code16(S(KC_LCTL));
                }
                break;
            case _SYM:
                if (clockwise) {
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
                break;
            /*
            case _NUM:
                if (clockwise) {

                } else {

                }
                break;
            */
            case _MOUSE:
                if (clockwise) {
                    tap_code16(KC_MS_DOWN);
                } else {
                    tap_code16(KC_MS_UP);
                }
                break;
            case _ADJ:
                if (clockwise) {
                    #if defined(RGBLIGHT_ENABLE)
                        rgblight_increase_hue();
                    #else
                        tap_code16(KC_VOLU);
                    #endif
                } else {
                    #if defined(RGBLIGHT_ENABLE)
                        rgblight_decrease_hue();
                    #else
                        tap_code16(KC_VOLD);
                    #endif
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(KC_DOWN);
                } else {
                    tap_code16(KC_UP);
                }
                break;
        }
    } else if (index == 1) { // Right hand encoder
        switch(get_highest_layer(layer_state)) {
            case _CLMK:
                if (clockwise) {
                    tap_code16(KC_RGHT);
                } else {
                    tap_code16(KC_LEFT);
                }
                break;
            case _NAV:
                if (clockwise) {
                    tap_code16(LGUI(KC_RGHT));
                } else {
                    tap_code16(LGUI(KC_LEFT));
                }
                break;
            /*
            case _TEX:
                if (clockwise) {

                } else {

                }
                break;
            case _SYM:
                if (clockwise) {

                } else {

                }
                break;
            */
            case _NUM:
                if (clockwise) {
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(S(KC_TAB));
                }
                break;
            case _MEDIA:
                if (clockwise) {
                    tap_code16(KC_MNXT);
                } else {
                    tap_code16(KC_MPRV);
                }
                break;
            case _MOUSE:
                if (clockwise) {
                    tap_code16(KC_MS_RIGHT);
                } else {
                    tap_code16(KC_MS_LEFT);
                }
                break;
            case _ADJ:
                if (clockwise) {
                    #if defined(RGBLIGHT_ENABLE)
                        rgblight_increase();
                    #else
                        tap_code16(KC_MNXT);
                    #endif
                } else {
                    #if defined(RGBLIGHT_ENABLE)
                        rgblight_decrease();
                    #else
                        tap_code16(KC_MPRV);
                    #endif
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(KC_DOWN);
                } else {
                    tap_code16(KC_UP);
                }
                break;
        }
    }
    return false;
}
