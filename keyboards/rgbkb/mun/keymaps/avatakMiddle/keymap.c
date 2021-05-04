#include QMK_KEYBOARD_H

enum keymap_layers {
    _COLEMAK = 0,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _MEDIA,
    _MOUSE,
    _ADJUST
};

/* Layer shifting */
#define ADJUST TT(_ADJUST)
#define NAVSPC LT(_NAV, KC_SPC)
#define NAVESC LT(_NAV, KC_ESC)
#define NUMTAP TT(_NUM)
#define NUMTOG TG(_NUM)
#define SYMENT LT(_SYM, KC_ENT)
#define TEXSPC LT(_TEX, KC_SPC)
#define MOUSE  TG(_MOUSE)
#define MEDIA MO(_MEDIA)

/* Mod tap keys */
#define ALTCOMM ALT_T(KC_COMM)
#define CTLSCLN CTL_T(KC_SCLN)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUIDOT GUI_T(KC_DOT)
#define GUISCLN GUI_T(KC_SCLN)
#define GUISLSH GUI_T(KC_SLASH)

/* Custom combos */
#define ALT_F2  LALT(KC_F2)
#define ALT_F3  LALT(KC_F3)
#define ALT_F4  LALT(KC_F4)
#define ALTCTL  LALT(KC_LCTL)
#define ALTCTLS S(LALT(KC_LCTL))
#define ALTSHFT LALT(KC_LSFT)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL  LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLSHFT LCTL(KC_LSFT)
#define CTLZERO LCTL(KC_0)
#define CTRLSZR S(LCTL(KC_0))
#define GUILEFT LGUI(KC_LEFT)
#define GUIRIGHT LGUI(KC_RIGHT)
#define SCLEFT S(LCTL(KC_LEFT))
#define SCRIGHT S(LCTL(KC_RIGHT))
#define TABLEFT LCTL(KC_PGUP)
#define TABRGHT LCTL(KC_PGDN)
#define UNDOIT  LCTL(KC_Z)
#define WINQUIT LALT(KC_F4)
#define RENAME  LALT(KC_F2)


enum keymap_custom_keycodes {
    ALIGN = SAFE_RANGE,
    ARRAY,
    COLEMAK,
    COLEMAC,
    DISPMTH,
    ENUM,
    ITEM,
    ITEMIZE,
    LINEMTH,
    RGBRST,
    TCH_TOG
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5   , XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , KC_BSPC,
        KC_TAB , KC_Q,    KC_W,    KC_F,    KC_P,    KC_B   , XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    GUISCLN, KC_BSLS,
        NAVESC , KC_A,    KC_R,    KC_S,    KC_T,    KC_G   , _______, _______, KC_K,    KC_N,    KC_E,    KC_I,    KC_O   , KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V   , ADJUST , UNDOIT , KC_M,    KC_H,    ALTCOMM, GUIDOT,  CTLSLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NAVSPC , NUMTAP , SYMENT , TEXSPC , _______, _______, _______, _______, MEDIA  
    ),

    [_NAV] = LAYOUT(
        _______, _______, RENAME , _______, WINQUIT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, CTLPGUP, KC_PGUP, CTLPGDN, _______, _______, _______, _______, TABLEFT, KC_UP,   TABRGHT, _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, KC_APP ,
        _______, CTRLSZR, KC_SLCK, KC_CAPS, KC_INS,  _______, _______, _______, CTLBSPC, KC_BSPC, KC_DEL,  CTLDEL,  CTLZERO, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_TEX] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, ENUM,    ITEMIZE, _______, _______, _______, _______, KC_LBRC, KC_RBRC, DISPMTH, LINEMTH, _______,
        _______, ALIGN,   _______, _______, ITEM,    _______, _______, _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, KC_PLUS, KC_EQL,  KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5  , _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_F11 ,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_NLCK, KC_PAST, KC_PSLS, KC_BSPC, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,S(KC_ENT), KC_P1  , KC_P2  , KC_P3  , KC_PEQL, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,  KC_PENT, KC_P0  , KC_PDOT, _______, KC_TAB , S(KC_TAB), _______
    ),      

    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS]  = {
    [_COLEMAK] = TOUCH_ENCODER_LAYOUT( \
        KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
        KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
    ),
    [_NAV] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_SYM] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_ADJUST] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS][ENCODER_OPTIONS]  = {
    [_COLEMAK] = ENCODER_LAYOUT( \
        KC_DOWN, KC_UP  ,
        LCTL(KC_LEFT),LCTL(KC_RIGHT),
        KC_LEFT, KC_RGHT,
        KC_PGDN, KC_PGUP
    ),
    [_NAV] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#if defined(OLED_DRIVER_ENABLE)
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case _TEX:
            oled_write_ln_P(PSTR("LaTeX"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
