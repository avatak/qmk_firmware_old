/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H 
#include "common_oled.h"

#include "avatak.h"

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = NEW_SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN
};

/* This keyboard is enabled with an RGB Menu Control system.
This functionality is enabled, but still requires a little configuration based on your exact setup.
The RGB Menu will appear on the Right Half's OLED and can be controlled by the MENU keycodes:
MENU_BTN - Triggers a button action for the menu
MENU_UP - Triggers an increase action for the menu
MENU_DN - Triggers a decrease action for the menu

To finish configuration for your board, you will want to change the default keycodes for an encoder on the right half.
Encoder press keycode should be set to MENU_BTN, Clockwise should be MENU_UP, and Counter Clockwise should be MENU_DN.
Depending on where you add an encoder to the right half will determin in the default keymap where you should put those keycodes.
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |   -    |  |    =   | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |   [    |  |    ]   | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | FN/Caps| A      | S      | D      | F      | G      |   (    |  |    )   | H      | J      | K      | L      | :      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shift  | Z      | X      | C      | V      | B      |   {    |  |    }   | N      | M      | ,      | .      | /      |Shft/Ent|
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl   | Win    | Alt    | RGBTOG | Adjust | Space  | Bksp   |  | Enter  | Space  | Left   | Down   | Up     | Right  | Ctrl   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * | VolUp  | VolDn  | VolUp  | VolDn  |                                                        | PgUp   | PgDn   | PgUp   | PgDn   |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * | VolDn  | VolUp  | Next   | Play   | Prev   | Touch Encoder          Touch Encoder | RgbHuI | RgbHuD | RgbMdD | RgbTog | RgbMdI |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */

    [_CLMK] = LAYOUT_wrapper(
        KC_GRV , __NUM_L____________________________________, _______, _______, __NUM_R____________________________________, KS_BSPC,
        KC_TAB , __CLMK_L1__________________________________, _______, _______, __CLMK_R1__________________________________, KC_BSLS,
        NAVESC , __CLMK_L2__________________________________, _______, _______, __CLMK_R2__________________________________, KC_QUOT,
        KC_LSFT, __CLMK_L3__________________________________, _______, _______, __CLMK_R3__________________________________, KC_RSFT,
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, NAVSPC , NAVSPC , NUMTAP , SYMENT , TEXSPC , TEXSPC , _______,S(KC_LALT),ALTCTL , MEDIA  ,

        _______, _______, KC_UP  , KC_DOWN,                                                       KC_LEFT, KC_RGHT, KC_LEFT, KC_RGHT,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, __NAV_L0___________________________________, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __NAV_L1___________________________________, _______, _______, __NAV_R1___________________________________, _______,
        _______, __NAV_L2___________________________________, _______, _______, __NAV_R2___________________________________, KC_APP ,
        _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12 ,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __TEX_L1___________________________________, _______, _______, __TEX_R1___________________________________, _______,
        _______, __TEX_L2___________________________________, _______, _______, __TEX_R2___________________________________, _______,
        _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 ,
        _______, __SYM_L2___________________________________, _______, _______, __SYM_R2___________________________________, KC_F12 ,
        _______, __SYM_L3___________________________________, _______, _______, __SYM_R3___________________________________, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),


    [_NUM] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    [_ADJ] = LAYOUT_wrapper(
        RESET  , _______, _______, _______, _______, _______, _______, _______, RGBRST , RGB_VAI, RGB_SAI, RGB_SPI, RGB_MOD, RGB_HUI, \
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_SPD,RGB_RMOD, RGB_HUD, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_P, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______,                                                       _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______
    ),

    
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case MENU_BTN:
            if (record->event.pressed) {
                rgb_menu_selection();
            }
            return false;
        case MENU_UP:
            if (record->event.pressed) {
                rgb_menu_action(true);
            }
            return false;
        case MENU_DN:
            if (record->event.pressed) {
                rgb_menu_action(false);
            }
            return false;
        case TCH_TOG:
            if (record->event.pressed) {
                touch_encoder_toggle();
            }
            return false;  // Skip all further processing of this key
        default:
            return true;
    }
}

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _CLMK:
            oled_write_ln_P(PSTR("Clmk "), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav   "), false);
            break;
        case _TEX: 
            oled_write_ln_P(PSTR("LaTeX"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbl"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numpd"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _ADJ:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

static void render_leds(void)
{
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLK")     : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK")    : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK")  : PSTR("     "), false);
}

static void render_touch(void)
{
    // Host Touch LED Status
    oled_write_P(!touch_encoder_toggled() ? PSTR("TOUCH")  : PSTR("     "), false);
    oled_write_P(touch_encoder_calibrating() ? PSTR("CLBRT")  : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_left()) {
        render_icon();
        oled_write_P(PSTR("     "), false);
        render_layer();
        oled_write_P(PSTR("     "), false);
        render_leds();
        oled_write_P(PSTR("     "), false);
        render_touch();
    }
    else {
        render_icon();
        oled_write_P(PSTR("     "), false);
        render_rgb_menu();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
