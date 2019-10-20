#include QMK_KEYBOARD_H
#include "avatak.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.              .-----------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|              |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|              |------+------+------+------+------+------|
   * |CAPS(NAV)|A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+------..------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |RGBPrv||RGBNxt|   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------||------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter |Space |  NAV |   -  |   =  | PGUP | PGDN |
   * `----------------------------------+-------------''------------------------------------------------'
   *                                    |Space |Delete||Enter |Space |
   *                                    '-------------''-------------'
   */
  [_COLEMAK] = LAYOUT_wrapper( \
    KC_GRV , __NUMBER_L_________________________________,                      __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB , __COLEMAK_L1_______________________________,                      __COLEMAK_R1_______________________________, KC_BSLS, \
    NAVESC , __COLEMAK_L2_______________________________,                      __COLEMAK_R2_______________________________, KC_QUOT, \
    KC_LSFT, __COLEMAK_L3_______________________________, _______,    _______, __COLEMAK_R3_______________________________, KC_RSFT,  \
    ADJUST , KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, NAVSPC , TT(_NUM),   SYMENT , TEXSPC , _______, _______, _______, _______, ADJUST , \
                                                 NAVSPC , TT(_NUM),   SYMENT , TEXSPC \
  ),

[_NAV] = LAYOUT_wrapper( \
    _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, \
    _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, _______, \
    _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 , \
                                                 _______, _______, _______, KC_ENT  \
  ),

[_SYM] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, \
    _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, _______, \
    _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

[_ADJUST] = LAYOUT_wrapper( \
    RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
),
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(1UL<<_QWERTY);
      }
      return false;
      break;
    //case COLEMAK:
      //if (record->event.pressed) {
        //set_single_persistent_default_layer(1UL<<_COLEMAK);
      //}
      //return false;
      //break;
  }
  return true;
}


#if OLED_DRIVER_ENABLE
const char* layer_name_user(uint32_t layer) {
  switch (layer) {
    case _QWERTY:
      return PSTR("QWRTY");
    case _NAV:
      return PSTR("NAV\n");
    default:
      return PSTR("UNDEF");
  }
}
#endif
