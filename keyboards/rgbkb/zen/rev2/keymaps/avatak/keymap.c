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

[_COLEMAC] = LAYOUT_wrapper( \
    KC_GRV , __NUMBER_L_________________________________,                      __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB , __COLEMAC_L1_______________________________,                      __COLEMAC_R1_______________________________, KC_BSLS, \
    MNAVESC, __COLEMAC_L2_______________________________,                      __COLEMAC_R2_______________________________, KC_QUOT, \
    KC_LSFT, __COLEMAC_L3_______________________________, _______,    _______, __COLEMAC_R3_______________________________, KC_RSFT,  \
    ADJUST , KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, MNAVSPC, TT(_NUM),   SYMENT , TEXSPC , _______, _______, _______, _______, ADJUST , \
                                                 MNAVSPC, TT(_NUM),   SYMENT , TEXSPC \
),


[_NAV] = LAYOUT_wrapper( \
    _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, S(LCTL(LALT(KC_S))), \
    _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, S(KC_F10), \
    _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 , \
                                                 _______, _______, _______, KC_ENT  \
  ),

[_MNAV] = LAYOUT_wrapper( \
    _______, _______, _______,_______,LGUI(KC_Q), _______,                   _______, _______, _______, _______, _______, _______, \
    MACWIN , __MNAV_L1__________________________________,                   __MNAV_R1__________________________________, _______, \
    _______, __MNAV_L2__________________________________,                   __MNAV_R2__________________________________, _______, \
    _______, __MNAV_L3__________________________________, _______, _______, __MNAV_R3__________________________________, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, S(LALT(KC_T)), \
                                                 _______, _______, _______, KC_ENT  \
  ),

[_TEX] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, \
    _______, __TEX_L1___________________________________,                    __TEX_R1___________________________________, _______, \
    _______, __TEX_L2___________________________________,                    __TEX_R2___________________________________, _______, \
    _______, __TEX_L3___________________________________,  _______, _______, __TEX_R3___________________________________, _______,  \
    _______, _______, _______, _______, _______, MO(_SYM), _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 MO(_SYM), _______, _______, _______ \
  ),

[_SYM] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, __FUNC_L___________________________________,                   __FUNC_R___________________________________, KC_F11 , \
    _______, __SYM_L____________________________________,                   __SYM_R____________________________________, KC_F12 , \
    _______, __NUMBER_L_________________________________, _______, _______, __NUMBER_R_________________________________, _______,  \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

[_ADJUST] = LAYOUT_wrapper( \
    RESET  , _______, _______, _______, _______, RGBRST ,                   _______, _______, _______, _______, _______, _______, \
    _______, RGB_TOG, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,  \
    _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, KC_MUTE, _______, _______, \
                                                 COLEMAK, _______, _______, COLEMAC \
),
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  } else if (index == 1) { /* Second encoder from slave */
    if (clockwise) {
      tap_code(KC_RGHT);
    } else {
      tap_code(KC_LEFT);
    }
  }
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
