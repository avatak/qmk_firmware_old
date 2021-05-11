#include QMK_KEYBOARD_H
#include "avatak.h"

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = NEW_SAFE_RANGE
};

#define APPSRCH LALT(KC_F3)
#define APPMENU LALT(KC_F1)
#define MEDIA MO(_MEDIA)


// Default Layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |   -    |  |    =   | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |   [    |  |    ]   | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | FN/Caps| A      | S      | D      | F      | G      |   (    |  |    )   | H      | J      | K      | L      | :      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shift( | Z      | X      | C      | V      | B      |   {    |  |    }   | N      | M      | ,      | .      | /      | )Shift |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl   | Win    | Alt    | RGBTOG | FN     | Space  | Bksp   |  | Enter  | Space  | Space  | FN     | Alt    | Win    | Ctrl   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     *      Encoder 1         Encoder 2                                                                  Encoder 3         Encoder 4
     * .-----------------------------------.                                                        .-----------------------------------.
     * | VolUp  | VolDn  | VolUp  | VolDn  |                                                        | PgUp   | PgDn   | PgUp   | PgDn   |
     * |--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
     * | VolDn  | VolUp  | Next   | Play   | Prev   | Touch Encoder          Touch Encoder | RgbHuI | RgbHuD | RgbMdD | RgbTog | RgbMdI |
     * '--------+--------+--------+--------+--------'                                      '--------+--------+--------+--------+--------'
     */
    [_CLMK] = LAYOUT_wrapper(
        KC_GRV , __NUM_L____________________________________, XXXXXXX,   XXXXXXX, __NUM_R____________________________________, KC_BSPC, \
        KC_TAB , __CLMK_L1__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R1__________________________________, KC_BSLS, \
        NAVESC , __CLMK_L2__________________________________, KC_INS ,   TCH_TOG, __CLMK_R2__________________________________, KC_QUOT, \
        KC_LSFT, __CLMK_L3__________________________________, KC_CAPS,   UNDOIT , __CLMK_R3__________________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LALT, _______, NAVSPC , NAVSPC , NUMTAP ,   SYMENT , TEXSPC , TEXSPC, CTLSHFT, ALTCTL , ALTCTLS, MEDIA  , \
//
//      |---- Upper ---|  |---  Lower ---|                                                           |---- Upper ---|  |---  Lower ---|
        KC_PGUP, KC_PGDN, KC_UP  , KC_DOWN,                                                          CTLLEFT, CTLRGHT, KC_LEFT, KC_RIGHT,
//      3 touch buttons, then swipe up and down
        KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV,                                        RGB_HUI, RGB_HUD, RGB_RMOD,RGB_TOG, RGB_MOD
    ),

    [_NAV] = LAYOUT_wrapper(
        _______, __NAV_L0___________________________________, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________, _______,   _______, __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________, _______,   _______, __NAV_R2___________________________________, KC_APP , \
        _______, __NAV_L3___________________________________, _______,   _______, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_F12 ,  \

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),

    [_TEX] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, _______,   _______, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, _______,   _______, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______,   _______, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,  \

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 , \
        KC_TILD, __SYM_L2___________________________________, _______, _______, __SYM_R2___________________________________, KC_F12 , \
        KC_GRV , __SYM_L3___________________________________, _______, _______, __SYM_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),



    [_NUM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),



    [_MEDIA] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MUTE, _______, _______, \

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),

    [_ADJ] = LAYOUT_wrapper( \
        RESET  , _______, _______, _______, _______, _______, _______,   _______, _______, RGB_VAD, _______, RGB_VAI, _______, RGBRST ,\
        _______, RGB_TOG, _______, _______, _______, _______, _______,   _______, _______, RGB_SPD, RGB_HUI, RGB_SPI, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, RGB_RMOD,RGB_HUD, RGB_MOD, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,   EEP_RST, _______, RGB_SAD, _______, RGB_SAI, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,\

        _______, _______, _______, _______,                                                         _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______
    ),

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {n
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#if defined(OLED_DRIVER_ENABLE)
static void render_icon(void) {
    static const char PROGMEM font_icon[] = {
        0x9b,0x9c,0x9d,0x9e,0x9f,
        0xbb,0xbc,0xbd,0xbe,0xbf,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
    oled_write_P(font_icon, false);
}

/*
static void render_rgb_menu(void) {
    static char buffer[53] = {0};
    snprintf(buffer, sizeof(buffer), "Hue   %3d Satur %3d Value %3d Speed %3d Mode  %3d ", 
    rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode);
    oled_write(buffer, false);
}
*/

static void render_layer(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer\n-----"), false);
    switch (get_highest_layer(layer_state)) {
        case _CLMK:
            oled_write_ln_P(PSTR("Clmk "), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV  "), false);
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
            oled_write_ln_P(PSTR("ADJ  "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

void render_mod_status(uint8_t modifiers) {
        oled_write_P(PSTR("\nMods "), false);
        oled_write_P(PSTR("-----"), false);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
}

/*
static void render_leds(void)
{
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLK")     : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK")    : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK")  : PSTR("     "), false);
}
*/

static void render_touch(void)
{
    // Host Touch LED Status
    oled_write_P(!touch_encoder_toggled() ? PSTR("TOUCH")  : PSTR("     "), false);
    oled_write_P(touch_encoder_calibrating() ? PSTR("CLBRT")  : PSTR("     "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer();
        oled_write_P(PSTR("     "), false);
        render_mod_status(get_mods());
        //render_leds();
        //oled_write_P(PSTR("     "), false);
        //render_touch();
        oled_set_cursor(0, 12);
        render_icon();
    }
    else {
        render_touch();
        //render_rgb_menu();
        oled_set_cursor(0, 12);
        render_icon();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
#endif
