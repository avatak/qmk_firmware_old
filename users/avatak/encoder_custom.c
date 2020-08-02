#include "encoder_custom.h"


void encoder_update_user(uint8_t index, bool clockwise) {
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
        /*
            case _NAV:
                if (clockwise) {

                } else {

                }
                break;
        */
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
            case _ADJ:
                if (clockwise) {
                    tap_code16(KC_VOLU);
                } else {
                    tap_code16(KC_VOLD);
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
                    tap_code16(KC_PGDN);
                } else {
                    tap_code16(KC_PGUP);
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
            case _ADJ:
                if (clockwise) {
                    tap_code16(KC_MNXT);
                } else {
                    tap_code16(KC_MPRV);
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
}
