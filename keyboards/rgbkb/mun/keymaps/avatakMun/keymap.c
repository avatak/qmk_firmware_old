#include QMK_KEYBOARD_H

enum keymap_layers {
    _COLEMAK,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _MEDIA,
    _ADJUST
};

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE
};

// Default Layers
#define COLEMAK  DF(_COLEMAK)

// Momentary Layers
#define ADJUST   MO(_ADJUST)
#define FN       MO(_FN)
#define MEDIA    MO(_MEDIA)
#define NUMTAP   MO(_NUM)

#define NAVESC   LT(_NAV, KC_ESC)
#define NAVSPC   LT(_NAV, KC_SPC)
#define SYMENT   LT(_SYM, KC_ENT)
#define TEXSPC   LT(_TEX, KC_SPC)

// Custom keycodes - DEFAULT
#define ALTCOMM ALT_T(KC_COMM)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUIDOT  GUI_T(KC_DOT)
#define GUISCLN GUI_T(KC_SCLN)

// Custom keycodes - NAV
#define ALTF4   LALT(KC_F4)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL  LCTL(KC_DEL)
#define TABRGHT LCTL(KC_TAB)
#define TABLEFT S(LCTL(KC_TAB))



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , XXXXXXX, XXXXXXX, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        NAVESC , KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______, KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    ADJUST , _______, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSHT,
        KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NAVSPC , NUMTAP , SYMENT , TEXSPC , _______, _______, _______, _______, MEDIA  
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, ALTF4  , _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, TABLEFT, KC_UP  , TABRGHT, _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_APP ,
        _______, _______, _______, KC_CAPS, KC_INS , KC_SCLK, _______, _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ),

    [_TEX] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
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
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD,
        KC_PGDN, KC_PGUP,
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
