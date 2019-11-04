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


   /*  COLEMAK MOD-DH
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |  '    |  1    |  2    |  3    |  4    |  5    |               |   6   |   7   |   8   |   9   |   0   | BSPC  |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  | Tab   |  Q    |  W    |   F   |  P    |   B   |               |   J   |   L   |   U   |   Y   | ;-GUI |   \   |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |ESC/NAV|  A    |  R    |   S   |  T    |   G   |               |   K   |   N   |   E   |   I   |   O   |   '   |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |SHIFT  |  Z    |   X   |   C   |  D    |   V   |       |       |   M   |   H   |   ,   |   .   | /-CTL | SHIFT |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |ADJUST | CTRL  |       | GUI   | ALT   |SPC/NAV|NUMPAD |SYM/ENT|TEX/SPC|ALTCTL |ALTSHFT|       |       |MEDIA  |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_COLEMAK] = LAYOUT_wrapper(/* Base */
        KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC,
        KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_BSLS,
        NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT,
        KC_LSFT, __COLEMAK_L3_______________________________, _______, _______, __COLEMAK_R3_______________________________, KC_RSFT,
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUMPAD , SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, ADJUST
    ),


    [_COLEMAC] = LAYOUT_wrapper( /* Variation of above with shifted codes more appropriate for using a mac */
        KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC,
        KC_TAB , __COLEMAC_L1_______________________________,                   __COLEMAC_R1_______________________________, KC_BSLS,
        MNAVESC, __COLEMAC_L2_______________________________,                   __COLEMAC_R2_______________________________, KC_QUOT,
        KC_LSFT, __COLEMAC_L3_______________________________, _______, _______, __COLEMAC_R3_______________________________, KC_RSFT,
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, MNAVSPC, NUMPAD , SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, ADJUST
    ),

    /* NAVIGATION
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |ALT+F4 |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |CTL+PUP| PG UP |CTL+PDN|       |               |       |TABLEFT|  UP   |TABRGHT|       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       | HOME  | PG DN | END   |       |               |CTL+ <-| LEFT  |  DOWN | RIGHT |CTL+ ->|       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |CAPSLCK| INSERT|       |       |       |CTLBSPC| BKSPC |  DEL  |CTL+DEL|CTL+0  |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       | ENTER |       |       |       |       | F12   |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_NAV] = LAYOUT_wrapper(
        _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, S(LCTL(LALT(KC_S))), \
        _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, S(KC_F10), \
        _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________. _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 \
    ),

    [_MNAV] = LAYOUT_wrapper(
        _______, _______, _______, _______,LGUI(KC_Q), _______,                 _______, _______, _______, _______, _______, _______, \
        MACWIN , __MNAV_L1__________________________________,                   __MNAV_R1__________________________________, _______, \
        _______, __MNAV_L2__________________________________,                   __MNAV_R2__________________________________, _______, \
        _______, __MNAV_L3__________________________________, _______, _______, __MNAV_R3__________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, S(LALT(KC_T)) \
    ),

    /* LaTeX and math,
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |SECTION| ENUM  |ITEMIZE|LFT/RGT|       |               |       |   [   |   ]   | \( \) | \[ \] |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |ALIGN* | ARRAY |       | \ITEM |       |               |       |   {   |   }   |   (   |   )   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       | LEMMA |THEOREM|       |       |       |       |       |   -   |   _   |   +   |   =   |   \   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |MO(_SYM|       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______
    ),

   /* Symbols, numbers, and function keys
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |  F1   |   F2  |   F3  |   F4  |  F5   |               |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |   ~   |   !   |   @   |   #   |   $   |   %   |               |   ^   |   &   |  *    |   (   |   )   |  F12  |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |   `   |   1   |   2   |   3   |    4  |   5   |       |       |   6   |   7   |  8    |   9   |   0   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
        KC_GRV , KC_1   ,  KC_2  , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


   /* Layer for moving windows with magnet on osx
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |L 1/3  |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |FULL SC|       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */


    [_MWIN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   MW_L13 , MW_ULFT, MW_UPPR, MW_URIT, MW_R13 , _______,
        _______, _______, _______, _______, _______, _______,                   MW_LEFT, MW_L23 , MW_CENT, MW_R23 , MW_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, MW_L13 , MW_LLFT, MW_LOWR, MW_LRIT, MW_R13 , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, MW_FULL, _______, _______, _______, _______, _______
    ),


   /* Media control
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |NUMLCK |  *    |   /   |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |   7   |   8   |   9   |   -   |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |SFT+TAB|   4   |   5   |   6   |   +   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       | TAB   |   1   |   2   |   3   |   =   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |SFT+ENT|ENTER  |   0   |   ,   |   .   |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, KC_NLCK, KC_PAST, KC_PSLS, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______,                 S(KC_TAB), KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB , KC_P1  , KC_P2  , KC_P3  , KC_EQL , _______,
        _______, _______, _______, _______, _______, _______,_______,S(KC_ENT), KC_ENT , KC_P0  , KC_COMM, KC_PDOT, _______, _______
    ),

   /* Adjustment layer
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______,                   RGB_TOG, _______, _______, _______, _______, RGBRST ,
        _______, _______, _______, RGB_VAI, _______, _______,                   RGB_SPI, RGB_HUI, _______, _______, _______, _______,
        _______, _______, RGB_SAD, RGB_VAD, RGB_SAI, _______,                   RGB_SPD, RGB_HUD, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,RGB_RMOD, RGB_MOD, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, KC_MUTE, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

// Will be used for maintaining same shortcuts in defferent operating systems

int os_status = 0;

bool os_undo(void) {
    if (os_status == 1) {
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
    } else {
        register_code(KC_LCTL);
        tap_code(KC_Z);
        unregister_code(KC_LCTL);
    }
    return false;
}

bool os_redo(void) {
    if (os_status == 1) {
        register_code(KC_LSFT);
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
    } else {
        register_code(KC_LSFT);
        register_code(KC_LCTL);
        tap_code(KC_Z);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
    return false;
}



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
                    os_redo();
                }
                else {
                    os_undo();
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
    case _COLEMAK:
        oled_write_P(PSTR("COLMK"), false);
        break;
    case _COLEMAC:
        oled_write_P(PSTR("CLMAC"), false);
        break;
    case _TEX:
        oled_write_P(PSTR("LaTeX"), false);
        break;
    case _SYM:
        oled_write_P(PSTR("SYM  "), false);
        break;
    case _NAV:
        oled_write_P(PSTR("NAV  "), false);
        break;
    case _MNAV:
        oled_write_P(PSTR("MNAV "), false);
        break;
    case _NUM:
        oled_write_P(PSTR("NUM  "), false);
        break;
    case _MWIN:
        oled_write_P(PSTR("MWIN "), false);
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



