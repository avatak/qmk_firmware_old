#include QMK_KEYBOARD_H
<<<<<<< HEAD
#include "avatak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {



    [_COLEMAK] = LAYOUT_wrapper( \
        KC_TAB,  __CLMK_L1__________________________________, __CLMK_R1__________________________________, KC_BSPC, \
        NAVESC,  __CLMK_L2__________________________________, __CLMK_R2__________________________________, KC_QUOT, \
        KC_LSFT, __CLMK_L3__________________________________, __CLMK_R3__________________________________, KC_RSFT , \
        ADJUST,  KC_LCTL, KC_LGUI, KC_LALT, NAVSPC , NAVSPC , TEXSPC , TEXSPC , KC_RALT, ALTCTL , ALTSHFT, ADJUST \
    ),

    [_NAV] =  LAYOUT_wrapper( \
        NUMTAP , __NAV_L1___________________________________, __NAV_R1___________________________________, LALT(KC_F2), \
        _______, __NAV_L2___________________________________, __NAV_R2___________________________________, _______, \
        _______, __NAV_L3___________________________________, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, SYMENT , SYMENT , _______, _______, _______, _______ \
    ),

    [_TEX] =  LAYOUT_wrapper( \
        _______, __TEX_L1___________________________________, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______,MO(_SYM),MO(_SYM), _______, _______, _______, _______, _______, _______ \
    ),

    [_SYM] =  LAYOUT_wrapper( \
        _______, __SYM_L1___________________________________, __SYM_R1___________________________________, KC_F11 , \
        KC_TILD, __SYM_L2___________________________________, __SYM_R2___________________________________, KC_F12 , \
        KC_GRV , __SYM_L3___________________________________, __SYM_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_NUM] =  LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, KC_NLCK, __NP_1____________________________, _______, KC_BSPC, \
        _______, _______, _______, _______, _______, _______, __NP_2____________________________, _______, _______, \
        _______, _______, _______, _______, _______, _______, __NP_3____________________________, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_P0  , KC_COMM  , KC_PDOT, KC_PENT, _______, _______ \
    ),

    [_ADJUST] =  LAYOUT_wrapper( \
        RESET  , RGB_TOG, _______, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, RGBRST , \
        _______, AU_TOG ,RGB_RMOD, RGB_HUD, RGB_MOD, _______, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______ \
    ),
};
=======


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _COLEMAK,
    _NAV,
    _TEX,
    _SYM,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),



};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
>>>>>>> master
