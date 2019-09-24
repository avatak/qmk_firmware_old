#include QMK_KEYBOARD_H
#include "avatak.h"

extern keymap_config_t keymap_config;

/*
 {\
    HALL = NEW_SAFE_RANGE,
    JESU,
    POP,
    PRELUDE,
    WEASLE
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_wrapper( \
    KC_GRV,  __NUMBER_L_________________________________, __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB,  __COLEMAK_L1_______________________________, __COLEMAK_R1_______________________________, KC_BSLS, \
    NAVESC,  __COLEMAK_L2_______________________________, __COLEMAK_R2_______________________________, KC_QUOT, \
    KC_LSFT, __COLEMAK_L3_______________________________, __COLEMAK_R3_______________________________, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NAVSPC , TEXSPC , TEXSPC , _______, ALTSHFT, ALTCTL , ADJUST \
),


[_COLEMAC] = LAYOUT_wrapper( \
    KC_GRV , __NUMBER_L_________________________________, __NUMBER_R_________________________________, KC_BSPC, \
    KC_TAB , __COLEMAC_L1_______________________________, __COLEMAC_R1_______________________________, KC_BSLS, \
    MNAVESC, __COLEMAC_L2_______________________________, __COLEMAC_R2_______________________________, KC_QUOT, \
    KC_LSFT, __COLEMAC_L3_______________________________, __COLEMAC_R3_______________________________, KC_RSFT, \
    KC_LCTL, KC_LALT, KC_LGUI, _______, MNAVSPC, MNAVSPC, TEXSPC , TEXSPC , _______, ALTSHFT, ALTCTL , ADJUST \
),

[_NAV] =  LAYOUT_wrapper( \
    TG(_NUM), __NAV_L0___________________________________, _______, _______, _______, _______, _______, _______,\
    _______, __NAV_L1___________________________________, __NAV_R1___________________________________, S(LCTL(LALT(KC_S))),\
    _______, __NAV_L2___________________________________, __NAV_R2___________________________________, S(KC_F10), \
    _______, __NAV_L3___________________________________, __NAV_R3___________________________________, _______, \
    ADJUST , _______, _______, _______, _______, _______, KC_ENT , KC_ENT , _______, _______, _______, KC_F12 \
),

[_MNAV] =  LAYOUT_wrapper( \
    TG(_NUM), _______, _______, _______, LGUI(KC_Q), _______, _______, _______, _______, _______, _______, _______,\
    MACWIN , __MNAV_L1__________________________________, __MNAV_R1__________________________________, LGUI(KC_SPC),\
    _______, __MNAV_L2__________________________________, __MNAV_R2__________________________________, _______, \
    _______, __MNAV_L3__________________________________, __MNAV_R3__________________________________, _______, \
    ADJUST , _______, _______, _______, _______, _______, KC_ENT , KC_ENT , _______, _______, _______, S(LALT(KC_T)) \
),

[_TEX] =  LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, __TEX_L1___________________________________, __TEX_R1___________________________________, _______,\
    _______, __TEX_L2___________________________________, __TEX_R2___________________________________, _______, \
    _______, __TEX_L3___________________________________, __TEX_R3___________________________________, _______, \
    _______, _______, _______, _______,MO(_SYM),MO(_SYM), _______, _______, _______, _______, _______, _______ \
),

[_SYM] =  LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12 ,\
    _______, __FUNC_L___________________________________, __FUNC_R___________________________________, KC_F11 ,\
    KC_GRV , __SYM_L____________________________________, __SYM_R____________________________________, _______, \
    _______, __NUMBER_L_________________________________, __NUMBER_R_________________________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_NUM] = LAYOUT_wrapper( \
    TG(_NUM), _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, _______, _______, KC_BSPC,\
    _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______, _______,\
    _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______,\
    _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_TAB , S(KC_TAB), _______,\
    _______, _______, _______, _______, KC_ENT , KC_ENT , KC_P0  , KC_P0  , _______, KC_PDOT, KC_EQL , KC_ENT  \
),

[_MWIN] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, __MWIN_R1__________________________________, _______,\
    _______, _______, _______, _______, _______, _______, __MWIN_R2__________________________________, _______,\
    _______, _______, _______, _______, _______, _______, __MWIN_R3__________________________________, _______,\
    _______, _______, _______, _______, _______, _______, MW_FULL, MW_FULL, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] =  LAYOUT( \
  //  RGBRST , PRELUDE, HALL   , JESU   , WEASLE, RGB_M_P, RGB_M_R, RGB_M_SW, RGB_M_G, _______, BL_STEP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, RGB_TOG, RGB_VAD, CK_UP  , RGB_VAI, _______, _______, _______, CK_UP  , _______, BL_TOGG, RESET  ,\
    _______, AU_TOG ,RGB_RMOD, CK_DOWN, RGB_MOD, _______, _______, _______, CK_DOWN, KC_VOLU, _______, RGBRST , \
    _______, _______, RGB_SAD, CK_TOGG, RGB_SAI, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
    _______, _______, _______, _______, COLEMAK, COLEMAK, COLEMAC, COLEMAC, _______, KC_MUTE, _______, _______ \
)


/*

/ * Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 / *

[_ADJUST] =  LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

*/

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (IS_LAYER_ON(_NAV)|IS_LAYER_ON(_MNAV)) {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
        }
        else if (IS_LAYER_ON(_TEX)) {
            if (clockwise) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LCTL);
            }
        }
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
        }
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        else
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
    }
// Second Encoder
    else if (index == 1) {
        if (IS_LAYER_ON(_NAV)|IS_LAYER_ON(_MNAV)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
/*
float tone_jesu[][2] = SONG(JESU_JOY);
float tone_ff[][2] = SONG(_FF_PRELUDE);
float tone_pop[][2] = SONG(POP_GOES_THE_WEASLE);
float tone_hall[][2] = SONG(HALL_OF_THE_MOUNTAIN_KING);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHENT:
            if (record->event.pressed) {
                register_code16(KC_SFTENT);
            } else {
                unregister_code16(KC_SFTENT);
            }
            break;
    }
    return true;
}
*/