#include QMK_KEYBOARD_H
#include "avatak.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

enum keymap_keycodes {
  RGB_MENU = NEW_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrapper( \
        KC_GRV , __NUM_L____________________________________, _______,   MOUSE  , __NUM_R____________________________________, KC_BSPC, \
        KC_TAB , __CLMK_L1__________________________________, _______,   NUMTOG , __CLMK_R1__________________________________, KC_BSLS, \
        NAVESC , __CLMK_L2__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R2__________________________________, KC_QUOT, \
        KC_LSFT, __CLMK_L3__________________________________, XXXXXXX,   XXXXXXX, __CLMK_R3__________________________________, KC_RSFT, \
        ADJUST , KC_LCTL, KC_LGUI, KC_LALT, _______, NAVSPC , NUMTAP ,   SYMENT , TEXSPC , _______, CTLSHFT, ALTCTL , ALTSHFT, MO(_MEDIA)  , \
                                                     NAVSPC , NUMTAP ,   SYMENT , TEXSPC \
    ),
      [_NAV] = LAYOUT_wrapper( \
        _______, __NAV_L0___________________________________, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________, _______,   _______, __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________, XXXXXXX,   XXXXXXX, __NAV_R2___________________________________, KC_APP , \
        _______, __NAV_L3___________________________________, XXXXXXX,   XXXXXXX, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, KC_F12 , \
                                                     _______, _______,   _______, _______ \
    ),

    [_TEX] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, __TEX_L1___________________________________, _______,   _______, __TEX_R1___________________________________, _______, \
        _______, __TEX_L2___________________________________, XXXXXXX,   XXXXXXX, __TEX_R2___________________________________, _______, \
        _______, __TEX_L3___________________________________, XXXXXXX,   XXXXXXX, __TEX_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______,   _______, _______ \
    ),

    [_SYM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, __SYM_L1___________________________________, _______, _______, __SYM_R1___________________________________, KC_F11 , \
        KC_TILD, __SYM_L2___________________________________, XXXXXXX, XXXXXXX, __SYM_R2___________________________________, KC_F12 , \
        KC_GRV , __SYM_L3___________________________________, XXXXXXX, XXXXXXX, __SYM_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______, _______, _______ \
    ),

    [_NUM] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_0____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_1____________________________, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, __NP_2____________________________, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, __NP_3____________________________, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, __NP_4____________________________, \
                                                     _______, _______,   _______, _______ \
    ),

    [_MEDIA] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, KC_MPLY, KC_VOLU, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MUTE, _______, _______, \
                                                     _______, _______,   _______, _______ \
    ),

    [_MOUSE] = LAYOUT_wrapper( \
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______,   _______, _______, _______, KC_WH_U, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, KC_WH_D, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   KC_BTN2, KC_BTN1, _______, _______, _______, _______, _______, \
                                                     _______, _______,   KC_BTN2, KC_BTN1 \
    ),

    [_UTIL] = LAYOUT_wrapper( \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______,   _______, _______ \
    ),

    [_ADJUST] = LAYOUT_wrapper( \
        RESET  , _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, RGB_SAD, RGB_VAI, RGB_SAI, RGBRST , _______,  _______, __ADJ_R1___________________________________, _______, \
        _______, _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, XXXXXXX,  XXXXXXX, __ADJ_R2___________________________________, _______, \
        _______, _______, RGB_SPD, _______, RGB_SPI, _______, XXXXXXX,  XXXXXXX, __ADJ_R3___________________________________, _______, \
        _______, _______, _______, _______, RGB_MOD, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
                                                     _______, _______,  _______, _______ \
    )
};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

#ifdef RGB_OLED_MENU
uint8_t rgb_encoder_state = 4;

typedef void (*rgb_matrix_f)(void);

const rgb_matrix_f rgb_matrix_functions[6][2] = {
    { rgb_matrix_increase_hue, rgb_matrix_decrease_hue },
    { rgb_matrix_increase_sat, rgb_matrix_decrease_sat },
    { rgb_matrix_increase_val, rgb_matrix_decrease_val },
    { rgb_matrix_increase_speed, rgb_matrix_decrease_speed },
    { rgb_matrix_step, rgb_matrix_step_reverse },
    { rgb_matrix_increase_flags, rgb_matrix_decrease_flags }
};
#endif

#ifdef ENCODER_ENABLE

static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(pin_t))

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2]  = {
    [_COLEMAK] = ENCODER_LAYOUT( \
        KC_UP  , KC_DOWN,
        KC_LEFT, KC_RGHT
    ),
    [_NAV] = ENCODER_LAYOUT( \
        _______, _______,
        KC_VOLD, KC_VOLU
    ),
    [_SYM] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_TEX] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_UTIL] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_MEDIA] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (!is_keyboard_master())
    return true;

#ifdef RGB_OLED_MENU
  if (index == RGB_OLED_MENU) {
    (*rgb_matrix_functions[rgb_encoder_state][clockwise])();
  } else
#endif
  {
    uint8_t layer = biton32(layer_state);
    uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    while (keycode == KC_TRANSPARENT && layer > 0)
    {
      layer--;
      if ((layer_state & (1 << layer)) != 0)
          keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    }
    if (keycode != KC_TRANSPARENT)
      tap_code16(keycode);
  }
    return true;
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case RGBRST:
//#if defined(RGBLIGHT_ENABLE)
//        if (record->event.pressed) {
//          eeconfig_update_rgblight_default();
//          rgblight_enable();
//        }
#if defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
    case RGB_MENU:
#ifdef RGB_OLED_MENU
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          rgb_encoder_state = (rgb_encoder_state - 1);
          if (rgb_encoder_state > 5) {
            rgb_encoder_state = 5;
          }
        } else {
          rgb_encoder_state = (rgb_encoder_state + 1) % 6;
        }
      }
#endif
      return false;
  }
  return true;
}

// OLED Driver Logic
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return OLED_ROTATION_180;
}

static void render_logo(void) {
  static const char PROGMEM sol_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(sol_logo, false);
}

static void render_status(void) {
  // Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  // Define layers here
  oled_write_P(PSTR("Layer"), false);
  uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
  switch (layer) {
    case _COLEMAK:
      oled_write_P(PSTR("CLMK "), false);
      break;
    case _NAV:
      oled_write_P(PSTR("NAV  "), false);
      break;
    case _TEX:
      oled_write_P(PSTR("TEX  "), false);
      break;
    case _SYM:
      oled_write_P(PSTR("SYM  "), false);
      break;
    //_NUM,_MEDIA,_MOUSE,_UTIL
    case _MEDIA:
      oled_write_P(PSTR("MEDIA"), false);
      break;
    case _UTIL:
      oled_write_P(PSTR("UTIL "), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("ADJST"), false);
      break;
    default:
      oled_write_P(PSTR("UNDEF"), false);
  }

  // Host Keyboard LED Status
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("     "), false);

#ifdef RGB_OLED_MENU
    static char buffer[31] = { 0 };
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
    buffer[4 + rgb_encoder_state * 5] = '<';

    oled_write_P(PSTR("-----"), false);
    oled_write(buffer, false);
#endif
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
}

#endif
