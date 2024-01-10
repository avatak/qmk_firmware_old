/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#include QMK_KEYBOARD_H

// LAYERS
enum sol_layers {
    _COLEMAK,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _FN,
    _ADJUST
};

// KEYCODES
enum sol_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE,
    MENU_BTN,
    MENU_UP,
    MENU_DN,
    RGB_RST
};

// Momentary Layers
#define ADJUST MO(_ADJUST)
#define NAV    MO(_NAV)
#define NUM    MO(_NUM)
#define FUNC   MO(_FN)
#define TEX    MO(_TEX)

// TAPTOGGLE
#define NUMPAD TT(_NUM)

// Custom
#define ALTF2   LALT(KC_F2)
#define ALTF4   LALT(KC_F4)
#define ALTCTL  LALT(KC_LCTL)

#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL  LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLRGHT LCTL(KC_RIGHT)
#define CTLSTAB S(LCTL(KC_TAB))
#define CTLTAB  LCTL(KC_TAB)
#define CTLZERO LCTL(KC_0)


// Multifunction keys

// Layers
#define BSPCFN  LT(_FN,KC_BSPC)
#define NAVESC  LT(_NAV, KC_ESC)
#define NAVSPC  LT(_NAV, KC_SPC)
#define TEXSPC  LT(_TEX, KC_SPC)
#define SYMENT  LT(_SYM, KC_ENT)

// command keys
#define ALTCOMM   RALT_T(KC_COMM)
#define CTLSLSH   RCTL_T(KC_SLSH)
#define GUIDOT    RGUI_T(KC_DOT)
#define GUISCLN   RGUI_T(KC_SCLN)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* Base Layout
  * ,------------------------------------------------.  ,------------------------------------------------.
  * |   `  |      |      |      |      |      |      |  |      |      |      |      |      |      | BkSp |
  * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
  * | Tab  |      |      |      |      |      |      |  |      |      |      |      |      |      |   \  |
  * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
  * | Esc  |      |      |      |      |      |      |  |      |      |      |      |      |      |   '  |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  * | Sft( |      |      |      |      |      |      |  |      |      |      |      |      |      | Sft) |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  * | Ctrl |  Win |  Win |  Alt |  FN  | Space|  RGB |  |  FN  |  FN  |   -  |   =  | Down | PgUp | PgDn |
  * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
  *                                    | Space| Bksp |  | Enter| Space|
  *                                    `-------------'  `--------=----'
  */

    [_COLEMAK] = LAYOUT(
        KC_GRV ,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , RGB_TOG,                          XXXXXXX, KC_6   , KC_7   , KC_8   , KC_9  , KC_0   , KC_BSPC,
        KC_TAB ,  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , _______,                          XXXXXXX, KC_J   , KC_L   , KC_U   , KC_Y  , GUISCLN, KC_BSLS,
        NAVESC ,  KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , XXXXXXX,                          XXXXXXX, KC_K   , KC_N   , KC_E   , KC_I  , KC_O   , KC_QUOT,
        KC_LSFT,  KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , XXXXXXX,                          XXXXXXX, KC_M   , KC_H   , ALTCOMM, GUIDOT, CTLSLSH, KC_RSFT,
        ADJUST ,  KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, NAVSPC , LGUI(KC_TAB), KC_DEL,     SYMENT, BSPCFN , TEXSPC , KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_RCTL,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                      KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MPRV
    ),

    [_NAV] = LAYOUT( 
        _______, _______, ALTF2  , _______, ALTF4  , _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, CTLPGUP, KC_PGUP, CTLPGDN, _______, _______,                   _______, _______, CTLSTAB, KC_UP  , CTLTAB , _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______,                   _______, CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, KC_APP ,
        _______, _______, KC_SCRL, KC_CAPS, KC_INS , _______, _______,                   _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , CTLZERO, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_TEX] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,
        _______, MENU_BTN, MENU_DN, MENU_UP, _______, _______, _______,                   _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______,                   _______, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5  , _______,                   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_F11 ,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5   , _______,                   _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),


    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,                   _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_PGDN,
        _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
        _______, CK_TOGG,   CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,

    //  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, QK_BOOT,   _______, _______,                   _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, RGB_RST, _______, DM_REC1,                   _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, DM_RSTP,                   _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
        _______, RGB_RMOD,RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NUM,  _______, _______,

//        RGB_MOD,RGB_RMOD, _______, _______, _______, _______,                                     RGB_HUI, RGB_HUD, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______,                                                       RGB_VAD, RGB_VAI, _______, _______, _______
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
        case RGB_RST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
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

void render_layer_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmak"), false);
            break;
        case _TEX:
            oled_write_ln_P(PSTR("TEX  "), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbl"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav  "), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("Func "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK]  = { ENCODER_CCW_CW(KC_UP  , KC_DOWN), ENCODER_CCW_CW(KC_UP  , KC_DOWN), ENCODER_CCW_CW(KC_UP  , KC_DOWN),
                    ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_NAV]      = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_TEX]      = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SYM]      = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_FN]       = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_ADJUST]   = { ENCODER_CCW_CW(RGB_MOD,RGB_RMOD), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______),
                    ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif
