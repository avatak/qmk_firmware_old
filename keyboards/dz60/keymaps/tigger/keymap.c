#include QMK_KEYBOARD_H

enum {
    _BASE = 0,
    _NAV,
    _ADJUST,
};

#define ADJUST TT(_ADJUST)
#define ALTCOMM ALT_T(KC_COMM)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUIDOT GUI_T(KC_DOT)
#define NAVESC LT(_NAV, KC_ESC)
#define TABLEFT S(LCTL(KC_TAB))
#define TABRGHT LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , XXXXXXX, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        NAVESC , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    ALTCOMM, GUIDOT,  CTLSLSH, KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RALT, XXXXXXX, XXXXXXX, ADJUST,   KC_RCTL
    ),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, KC_DEL,
        _______, _______, _______, KC_PGUP, _______, _______, _______, TABLEFT, KC_UP  , TABRGHT, KC_MPLY, KC_MPRV, KC_MNXT, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END , _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, _______, _______, _______, KC_CAPS, KC_INS, KC_SLCK, CTLBSPC, KC_BSPC, KC_DEL , _______, _______, _______, _______,
        _______, _______, _______,                   KC_ENT , KC_ENT , KC_ENT ,          _______, _______, _______, _______, _______
    ),

[_ADJUST] = LAYOUT(
        RESET , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
};