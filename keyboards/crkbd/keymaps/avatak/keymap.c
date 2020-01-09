#include QMK_KEYBOARD_H
#include "avatak.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_wrapper( \
    KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_BSPC,\
    NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT,\
    KC_LSFT, __COLEMAK_L3_______________________________,                   __COLEMAK_R3_______________________________, KC_RSFT,\
                                        _______, NAVSPC , _______, SYMENT , TEXSPC , _______ \
),

[_NAV] = LAYOUT_wrapper( \
    _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______,\
    _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, KC_APP ,\
    KC_F12 , __NAV_L3___________________________________,                   __NAV_R3___________________________________, _______,\
                                        _______, _______, _______, _______, KC_ENT , _______ \
),

[_TEX] = LAYOUT_wrapper( \
    _______, __TEX_L1___________________________________,                   __TEX_R1___________________________________, _______,\
    _______, __TEX_L2___________________________________,                   __TEX_R2___________________________________, _______,\
    _______, __TEX_L3___________________________________,                   __TEX_R3___________________________________, _______,\
                                        _______, _______,MO(_SYM), _______, _______, _______ \
),

[_SYM] = LAYOUT_wrapper( \
    _______, __FUNC_L___________________________________,                   __FUNC_R___________________________________, _______,\
    KC_TILD, __SYM_L____________________________________,                   __SYM_R____________________________________, _______,\
    KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, _______,\
                                        _______, _______, _______, _______, _______, _______ \
  ),

/*
[_] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
                                        _______, _______, _______, _______, _______, _______ \
  ),
*/

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
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
    //matrix_write_ln(matrix, read_keylogs());
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

  switch (keycode) {
    /*
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    */
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    // LEFT KNOB

    if (index == 0) {
        // NAV LAYER
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
        }
        // TEX Layer
        else if (IS_LAYER_ON(_TEX)) {
            if (clockwise) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            } else {
                register_code(KC_LCTL);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
            }
        }
        // ADJUST layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        }
        // MEDIA layer
        else if (IS_LAYER_ON(_MEDIA)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        // DEFAULT
        else {
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            } 
        }

    // RIGHT KNOB

    else if (index == 1) {
        //  NAV LAYER
        if (IS_LAYER_ON(_NAV)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        }
        // MEDIA layer
        else if (IS_LAYER_ON(_MEDIA)) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        // DEFAULT
        else {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
}