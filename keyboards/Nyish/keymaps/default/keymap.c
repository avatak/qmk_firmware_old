/* Copyright 2019 avatak
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

enum layer_names {
    _COLEMAK = 0,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

#define ADJUST MO(_ADJUST)
#define NAVESC LT(_NAV, KC_ESC)
#define NAVSPC LT(_NAV, KC_SPC)
#define NUMPAD TT(_NUM)
#define SYMENT LT(_SYM, KC_ENT)
#define TEXSPC LT(_TEX, KC_SPC)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                       KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS, \
        NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                       KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                       KC_M   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT,          NAVSPC ,                       TEXSPC ,          KC_RALT, KC_RGUI, KC_RCTL, ADJUST , \
                                                                NUMPAD , SYMENT \
     ),

    [_NAV] = LAYOUT( /* Base */
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,          _______,                       _______,          _______, _______, _______, _______, \
                                                                _______, _______ \
     ),

    [_NUM] = LAYOUT( /* Base */
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,          _______,                       _______,          _______, _______, _______, _______, \
                                                                _______, _______ \
     ),

    [_SYM] = LAYOUT( /* Base */
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,          _______,                       _______,          _______, _______, _______, _______, \
                                                                _______, _______ \
     ),



    [_ADJUST] = LAYOUT( /* Base */
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,          _______,                       _______,          _______, _______, _______, _______, \
                                                                _______, _______ \
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
                SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
*/

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE 
    /*
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master())
            return OLED_ROTATION_270;
        else if (!is_keyboard_master())
            return OLED_ROTATION_180;
        else 
          return rotation;
    }
    */

/*
static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}
*/

static void render_status(void) {
  // Render to mode icon
  /*
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);
  */

  // Define layers here
  oled_write_P(PSTR("Layer: "), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _COLEMAK:
      oled_write_P(PSTR("COLEMAK\n"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("NAVIGATION\n"), false);
      break;
    case _TEX:
      oled_write_P(PSTR("LaTeX"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("SYM  "), false);
      break;
    case _NUM:
      oled_write_P(PSTR("NUM  "), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("ADJST"), false);
      break;
    default:
      oled_write_P(PSTR("UNDEF"), false);
  }

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("\n---------------\n"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLOCK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPSLOCK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

}

void oled_task_user(void) {
  //if (is_keyboard_master()) {
    render_status();
  //} else {
//    render_logo();
    //oled_scroll_left();
  //}
}

#endif