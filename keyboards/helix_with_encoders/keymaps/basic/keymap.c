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


/* Layers: For an overview see 
 * https://docs.qmk.fm/#/feature_advanced_keycodes?id=working-with-layers 
 */

enum custom_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

/* Custom keycode definitions */
  #define ADJUST MO(_ADJUST)


/* Defines the keycodes used by our macros in process_record_user (defined below the layer defines)
 * See https://docs.qmk.fm/#/feature_macros
 */

enum custom_keycodes {
    MACRO_1 = SAFE_RANGE,
    MACRO_2,
    MACRO_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Base
    *  ,-----------------------------------------------.                           ,-----------------------------------------------.
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------.           ,-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |           |       |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------|           |-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |           |       |       |       |       |       |       |       |
    *  `-------------------------------------------------------'           `-------------------------------------------------------'
    */


    [_QWERTY] = LAYOUT(/* Base */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, KC_SPC , _______, KC_ENT , KC_SPC , KC_RALT, KC_RGUI, _______, KC_RCTL, ADJUST
    ),





   /* Adjust
    *  ,-----------------------------------------------.                           ,-----------------------------------------------.
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|                           |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |                           |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------.           ,-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |           |       |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------|           |-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |           |       |       |       |       |       |       |       |
    *  `-------------------------------------------------------'           `-------------------------------------------------------'
    */

    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

//uint16_t key_timer;
bool key_triggered = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_1: 
            if (record->event.pressed) {
                SEND_STRING("\\item");
                tap_code(KC_SPC);
            }
            break;
        case MACRO_2: 
        /* Sort of pointless to do the second thing in two steps, but I just wanted to illustrate an action that takes place when the key is released:
         * Selects entire row of text when held, then when the key is released it cuts the text.
         */
        if (key_triggered) {
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_V);
                unregister_code(KC_LCTL);  
            }
            key_triggered = !key_triggered;
            break;
        } else { 
            if (record->event.pressed) {
                tap_code(KC_END);
                register_code(KC_LSFT);
                tap_code(KC_HOME);
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_X);
                unregister_code(KC_LCTL);
            }
            break;
        }
    }
    return true;
}


#ifdef ENCODER_ENABLE

/* Per layer encoder function */


    void encoder_update_user(uint8_t index, bool clockwise) {

    /* Left hand encoder */

        if (index == 0) {
                  /* Default, base layer: Down and Up */
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            }

/* Right hand encoder */

    else if (index == 1) {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
#endif



/* OLED Screen Driver Logic
 * To change what is shown on a specific layer, make modifications to the code under switch (get_highest_layer(layer_state)) {...
 * You can do a lot more with this thing that I understand, if curious check out the keyboard crkbd for some interesting things people have done.
 */

#ifdef OLED_DRIVER_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master())
            return OLED_ROTATION_270;
        else if (!is_keyboard_master())
            return OLED_ROTATION_180;
        else
          return rotation;
    }

static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);




// Define layers here
oled_write_P(PSTR("Layer\n"), false);

switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_P(PSTR("QWRTY"), false);
        break;    
    case _LOWER:
        oled_write_P(PSTR("LOWER"), false);
        break;
    case _RAISE:
        oled_write_P(PSTR("RAISE"), false);
        break;
    case _ADJUST:
        oled_write_P(PSTR("ADJST"), false);
        break;
    default:
        oled_write_P(PSTR("UNDEF"), false);
}

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("\n-----\n"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif



