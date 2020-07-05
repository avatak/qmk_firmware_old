 /* Copyright 2019 Michael Shultz
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
#include "avatak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_wrapper( \
      KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC, \
      KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_BSLS, \
      NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT, \
      KC_LSFT, __COLEMAK_L3_______________________________, _______, _______, __COLEMAK_R3_______________________________, KC_RSFT, \
      ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUM_TAP, SYMENT , TEXSPC , KC_HYPR, CTLSHFT, ALTCTL , ALTSHFT, ADJUST  \
      ),

    [_NAV] = LAYOUT_wrapper( \
        _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, KC_APP , \
        _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12  \
    ),

    [_TEX] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, MO(_SYM),_______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __FUNC_L___________________________________,                   __FUNC_R___________________________________, KC_F11 , \
        KC_TILD, __SYM_L____________________________________,                   __SYM_R____________________________________, KC_F12 , \
        KC_GRV , __NUMBER_L_________________________________, _______, _______, __NUMBER_R_________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_NUM] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_ADJUST] = LAYOUT( \
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, CK_UP  , _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG , MUV_DE , CK_DOWN, MUV_IN , _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
};


// Encoder stuff
#ifdef ENCODER_ENABLE

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
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LCTL);
                } else {
                    register_code(KC_LSFT);
                    register_code(KC_LCTL);
                    tap_code(KC_Z);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LSFT);
                }
            }
            // ADJUST layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
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
                rgblight_step();
            } else {
                rgblight_step_reverse();
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



void matrix_init_keymap(void) {
}

void matrix_scan_keymap(void) {}

void led_set_user(uint8_t usb_led) {}

// Will be used for maintaining same shortcuts in defferent operating systems



uint16_t key_timer;
bool key_triggered = false;



// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_270;
    else if (!is_keyboard_master())
        return OLED_ROTATION_180;
    else
        return rotation;
}

// Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };


void render_layer_state(void) {
    oled_write_P(PSTR("\nLayer"), false);
    oled_write_P(PSTR("-----"), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _COLEMAK:
            oled_write_P(PSTR("COLMK"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("  NAV"), false);
            break;
        case _TEX:
            oled_write_P(PSTR("LaTeX"), false);
            break;
        case _MNAV:
            oled_write_P(PSTR(" MNAV"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBL"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMPD"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("  ADJ"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
        }
    oled_write_P(PSTR("\n"), false);
}

void render_keylock_status(uint8_t led_usb_state) {
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("Locks"), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("N") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("C") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("S") : PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods "), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
}

static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(sol_icon, false);
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
        //oled_scroll_left();
    }
}

#endif
