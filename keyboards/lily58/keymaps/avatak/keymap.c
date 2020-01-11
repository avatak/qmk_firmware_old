#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif



#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_COLEMAK] = LAYOUT_wrapper( \
        KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC, \
        KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, _______, \
        NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, _______, \
        KC_LSFT, __COLEMAK_L3_______________________________, _______, _______, __COLEMAK_R3_______________________________, _______, \
                                   KC_LGUI, KC_LALT, NAVSPC , _______, SYMENT , TEXSPC , _______, _______ \
    ),


    [_NAV] = LAYOUT_wrapper( \
        _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, KC_APP , \
        KC_F12 , __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______, \
                                   _______, _______, _______, _______, _______, KC_ENT , _______, _______ \
    ),

    [_MNAV] = LAYOUT_wrapper( \
        _______, _______, _______, _______, LGUI(KC_Q), _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __MNAV_L1__________________________________,                   __MNAV_R1__________________________________, _______, \
        _______, __MNAV_L2__________________________________,                   __MNAV_R2__________________________________, KC_APP , \
        _______, __MNAV_L3__________________________________, _______, _______, __MNAV_R3__________________________________, _______, \
                                   _______, _______, _______, _______, _______, KC_ENT , _______, _______ \
    ),

    [_TEX] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, _______, _______, __TEX_R3___________________________________, ADJUST , \
                                   _______, _______, _______, _______, _______, KC_ENT , _______, _______ \
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __FUNC_L___________________________________,                   __FUNC_R___________________________________, KC_F11 , \
        KC_TILD, __SYM_L____________________________________,                   __SYM_R____________________________________, KC_F12 , \
        KC_GRV , __NUMBER_L_________________________________, _______, _______, __NUMBER_R_________________________________, _______, \
                                   _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_ADJUST] = LAYOUT_wrapper( \
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MPLY, KC_VOLU, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, \
                                   _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______ \
    ),

};

void matrix_init_keymap(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_keymap(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}


void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_DOWN);
    } else {
      tap_code(KC_UP);
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
} 
