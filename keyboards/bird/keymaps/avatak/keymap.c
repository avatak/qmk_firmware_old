/* Copyright 2020 Michael S.
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
    /* Base */
    [_COLEMAK] = LAYOUT_wrapper(
        KC_GRV , __NUMBER_L_________________________________,                  __NUMBER_R_________________________________, KC_BSPC,\
        KC_TAB , __COLEMAK_L1_______________________________,                  __COLEMAK_R1_______________________________, KC_BSLS,\
        NAVESC , __COLEMAK_L2_______________________________,                  __COLEMAK_R2_______________________________, KC_QUOT,\
        KC_LSFT, __COLEMAK_L3_______________________________,                  __COLEMAK_R3_______________________________, KC_RSFT,\
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT,      NAVSPC ,    KC_SPC , SYMENT ,     TEXSPC ,      KC_SPC , KC_SPC , KC_SPC , ADJUST \
    ),

    [_NAV] = LAYOUT_wrapper(\
        _______, _______, _______, _______, WINQUIT, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, __NAV_L1___________________________________,                  __NAV_R1___________________________________, _______,\
        _______, __NAV_L2___________________________________,                  __NAV_R2___________________________________, KC_APP ,\
        _______, __NAV_L3___________________________________,                  __NAV_R3___________________________________, _______,\
        _______, _______, _______, _______,      _______,    _______, _______,     _______,      _______, _______, _______, KC_F12 \
    ),

    [_TEX] = LAYOUT_wrapper(\
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, __TEX_L1___________________________________,                  __TEX_R1___________________________________, _______,\
        _______, __TEX_L2___________________________________,                  __TEX_R2___________________________________, _______,\
        _______, __TEX_L3___________________________________,                  __TEX_R3___________________________________, _______,\
        _______, _______, _______, _______,      _______,    _______, _______,     _______,      _______, _______, _______, _______\
    ),

    [_SYM] = LAYOUT_wrapper(\
        _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, __FUNC_L___________________________________,                  __FUNC_R___________________________________, KC_F11 ,\
        KC_TILD, __NAV_L2___________________________________,                  __NAV_R2___________________________________, KC_F12 ,\
        KC_GRV , __NUMBER_L_________________________________,                  __NUMBER_R_________________________________, _______,\
        _______, _______, _______, _______,      _______,    _______, _______,     _______,      _______, _______, _______, _______\
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                  KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC, _______, _______,\
        _______, _______, _______, _______, _______, _______,                  KC_P7  , KC_P8  , KC_P8  , KC_PMNS, _______, _______,\
        _______, _______, _______, _______, _______, _______,                  KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______,\
        _______, _______, _______, _______, _______, _______,                  KC_P1  , KC_P2  , KC_P3  , KC_TAB , S(KC_TAB),_______,\
        _______, _______, _______, _______,      _______,    _______, KC_PENT,     KC_P0  ,      KC_PDOT, _______, _______, _______\
    ),

    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, RESET  ,\
        _______, _______, _______, CK_UP  , _______, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, AU_TOG , _______, CK_DOWN, _______, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, CK_TOGG, _______, _______,                  _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______,      _______,    _______, _______,     _______,      _______, _______, _______, _______\
    ),

};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
*/

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) // Left encoder
    {
        if (IS_LAYER_ON(_ADJUST))
        {
            if (clockwise)
            {
                tap_code16(KC_VOLD);
            }
            else
            {
                tap_code16(KC_VOLU);
            }
        }
        else if (IS_LAYER_ON(_SYM))
        {
            if (clockwise)
            {
                tap_code16(LCTL(KC_EQL));
            }
            else
            {
                tap_code16(LCTL(KC_MINS));
            }
        }
        else if (IS_LAYER_ON(_TEX))
        {
            if (clockwise)
            {
                tap_code16(LCTL(KC_Z));
            }
            else
            {
                tap_code16(S(LCTL(KC_Z)));
            }
        }
        else if (IS_LAYER_ON(_NAV))
        {
            if (clockwise)
            {
                tap_code16(KC_TAB);
            }
            else
            {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
        }
        else
        {
            if (clockwise)
            {
                tap_code16(KC_DOWN);
            }
            else
            {
                tap_code16(KC_UP);
            }
        }
    }
    else if (index == 1) // Left encoder
    {
        if (IS_LAYER_ON(_ADJUST))
        {
            if (clockwise)
            {
                tap_code16(KC_MNXT);
            }
            else
            {
                tap_code16(KC_MPRV);
            }

        }
        else if (IS_LAYER_ON(_NAV))
        {
            if (clockwise)
            {
                tap_code16(KC_PGDN);
            }
            else
            {
                tap_code16(KC_PGUP);
            }
        }
        else
        {
            if (clockwise)
            {
                tap_code16(KC_RGHT);
            }
            else
            {
                tap_code16(KC_LEFT);
            }
        }
    }
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE

static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

// Render to mode icon
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_180;
    else if (!is_keyboard_master())
        return OLED_ROTATION_180;
    else
        return rotation;
}



void render_layer_state(void) {
    oled_write_P(PSTR("\nLayer: "), false);
    //oled_write_P(PSTR("-----"), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _COLEMAK:
            oled_write_P(PSTR("Colemak"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("    NAV"), false);
            break;
        case _TEX:
            oled_write_P(PSTR("  LaTeX"), false);
            break;
        case _SYM:
            oled_write_P(PSTR(" Symbol"), false);
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
    oled_write_P(PSTR("Locks: "), false);
    //oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR(" N ") : PSTR("   "), false);
    //oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR(" C ") : PSTR("   "), false);
    //oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR(" S ") : PSTR("   "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods: "), false);
    //oled_write_P(PSTR("-----"), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR(" S ") : PSTR("   "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR(" C ") : PSTR("   "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR(" A ") : PSTR("   "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR(" G ") : PSTR("   "), false);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(qmk_logo, false);
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
        //oled_scroll_left();
    }
}

#endif
