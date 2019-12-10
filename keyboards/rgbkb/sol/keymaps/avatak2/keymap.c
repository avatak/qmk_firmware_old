#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _COLEMAK = 0,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _MEDIA,
    _ADJUST
};

/*  Custom keycode definitions */

/* Layer changes */

    #define ADJUST MO(_ADJUST)
    #define MACWIN MO(_MWIN)
    #define MEDIA MO(_MEDIA)
    #define MNAVESC LT(_MNAV, KC_ESC)
    #define MNAVSPC LT(_MNAV, KC_SPC)
    #define NAVESC LT(_NAV, KC_ESC)
    #define NAVSPC LT(_NAV, KC_SPC)
    #define NUM_TAP TT(_NUM)
    #define SYMENT LT(_SYM, KC_ENT)
    #define SYMBOL MO(_SYM)
    #define TEXSPC LT(_TEX, KC_SPC)

/* Custom combination keycodes */

    #define ALTBSPC LALT(KC_BSPC)
    #define ALTCTL LALT(KC_LCTL)
    #define ALTCTLS S(LALT(KC_LCTL))
    #define ALTDEL LALT(KC_DEL)
    #define ALT_F4 LALT(KC_F4)
    #define ALTLEFT LALT(KC_LEFT)
    #define ALTRGHT LALT(KC_RGHT)
    #define ALTSHFT LALT(KC_LSFT)
    #define CTLBSPC LCTL(KC_BSPC)
    #define CTLDEL LCTL(KC_DEL)
    #define CTLLEFT LCTL(KC_LEFT)
    #define CTLPGDN LCTL(KC_PGDN)
    #define CTLPGUP LCTL(KC_PGUP)
    #define CTLRGHT LCTL(KC_RGHT)
    #define CTLZERO LCTL(KC_0)
    #define MACEND LGUI(KC_RIGHT)
    #define MACHOME LGUI(KC_LEFT)
    #define TABLEFT LCTL(LSFT(KC_TAB))
    #define TABRGHT LCTL(KC_TAB)
    
/* Dual function keys */

    #define CTLSCLN CTL_T(KC_SCLN)
    #define CTLSLSH CTL_T(KC_SLSH)
    #define GUISCLN GUI_T(KC_SCLN)
    #define GUISLSH GUI_T(KC_SLSH)

/* Keycodes for moving windows around on osx using magnet */
      /*
      #define MW_CENT LCTL(LALT(KC_F))
      #define MW_CSQR LCTL(LALT(KC_C))
      #define MW_FULL LCTL(LALT(KC_ENT))
      #define MW_LEFT LCTL(LALT(KC_LEFT))
      #define MW_LLFT LCTL(LALT(KC_J))
      #define MW_LOWR LCTL(LALT(KC_DOWN))
      #define MW_LRIT LCTL(LALT(KC_K))
      #define MW_L13 LCTL(LALT(KC_D))
      #define MW_L23 LCTL(LALT(KC_E))
      #define MW_RGHT LCTL(LALT(KC_RIGHT))
      #define MW_R13 LCTL(LALT(KC_G))
      #define MW_R23 LCTL(LALT(KC_T))
      #define MW_ULFT LCTL(LALT(KC_U))
      #define MW_UPPR LCTL(LALT(KC_UP))
      #define MW_URIT LCTL(LALT(KC_I))
    */

// Defines the keycodes used by our macros in process_record_user

enum custom_keycodes {
    ALIGN = SAFE_RANGE,
    ARRAY,
    COLEMAC,
    COLEMAK,
    DISPMTH,
    ENUM,
    ITEM,
    ITEMZ,
    LFTRGHT,
    LEMMA,
    LINEMTH,
    RGBRST,
    RGB_MENU,
    SECTN,
    THEOREM,
    QWERTY,
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |  |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   S  |   D  |   F  |   G  |   (  |  |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |   {  |  |   }  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space| DEL  | | Enter| Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_COLEMAK] = LAYOUT( \
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_INS ,         _______ , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_CAPS,         TG(_NUM), KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS, \
    NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , XXXXXXX,         XXXXXXX,  KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , XXXXXXX,         XXXXXXX,  KC_M   , KC_H   , KC_COMM, KC_DOT , CTLSLSH, KC_ENT , \
    ADJUST , KC_LCTL, _______, _______, _______,  KC_SPC, _______,         _______,  TEXSPC , _______, KC_HYPR, ALTSHFT, ALTCTL , MEDIA  ,
                                                  KC_SPC, NUM_TAP,         SYMENT ,  TEXSPC \
  ),


  /* FN
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | PGDN |  UP  | PGUP |      |      |      |  |      |      | PGDN |  UP  | PGUP | PRINT| HOME |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | LEFT | DOWN | RIGHT|      |      |      |  |      |      | LEFT | DOWN | RIGHT|INSERT| END  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |RGBMOD|      |      |      |  |      |      | PLAY | NEXT | MUTE | VOL- | VOL+ |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    |      |      |  |      |      |
   *                                    `-------------'  `-------------'
   */
  [_NAV] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

  [_TEX] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

  [_SYM] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

  [_NUM] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),

  [_ADJUST] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______ \
  ),


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
        KC_LEFT, KC_RIGHT
    ),
    [_NAV] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_SYM] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_TEX] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_NUM] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (!is_keyboard_master())
    return;

#ifdef RGB_OLED_MENU
  if (index == RGB_OLED_MENU) {
    (*rgb_matrix_functions[rgb_encoder_state][clockwise])();
  } else
#endif
  {
    uint8_t layer = biton32(layer_state);
    uint16_t keycode = encoders[layer][index][clockwise];
    while (keycode == KC_TRANSPARENT && layer > 0)
    {
      layer--;
      if ((layer_state & (1 << layer)) != 0)
          keycode = encoders[layer][index][clockwise];
    }
    if (keycode != KC_TRANSPARENT)
      tap_code16(keycode);
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t reset_timer;
    switch (keycode) {
        case RGBRST:
            #if defined(RGBLIGHT_ENABLE)
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                }
            #elif defined(RGB_MATRIX_ENABLE)
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

// For LaTeX specifically

        case ALIGN:
            if (record->event.pressed) {
                SEND_STRING("\\begin{align*}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{align*}" SS_TAP(X_UP) SS_TAP(X_TAB));
            }
            break;
        case ARRAY:
            if (record->event.pressed) {
                SEND_STRING("\\begin{array}{c c}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{array}" SS_TAP(X_UP) SS_TAP(X_TAB));
            }
            break;
        case DISPMTH:
            if (record->event.pressed) {
                SEND_STRING("\\[\n\\]" SS_TAP(X_UP) "    ");
            }
            break;
        case ENUM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{enumerate}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case ITEM:
            if (record->event.pressed) {
                SEND_STRING("\\item");
            }
            break;
        case ITEMZ:
            if (record->event.pressed) {
                SEND_STRING("\\begin{itemize}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case LFTRGHT:
            if (record->event.pressed) {
                SEND_STRING("\\left(  \\right)" SS_LCTRL(SS_TAP(X_LEFT) SS_TAP(X_LEFT)) SS_TAP(X_LEFT));
            }
            break;
        case LEMMA:
            if (record->event.pressed) {
                SEND_STRING("\\begin{lemma}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{lemma}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
        case LINEMTH:
            if (record->event.pressed) {
                tap_code(KC_BSLS);
                register_code(KC_LSFT);
                tap_code(KC_9);
                unregister_code(KC_LSFT);
                tap_code(KC_BSLS);
                register_code(KC_LSFT);
                tap_code(KC_0);
                unregister_code(KC_LSFT);
                tap_code(KC_LEFT);
                tap_code(KC_LEFT);
                tap_code(KC_SPC);
                tap_code(KC_LEFT);
                tap_code(KC_SPC);
                }
            break;
        case SECTN:
            if (record->event.pressed) {
                SEND_STRING("\\section{}"SS_TAP(X_LEFT));
            }
            break;
        case THEOREM:
            if (record->event.pressed) {
                SEND_STRING("\\begin{theorem}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{theorem}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
    }
    return true;
}

// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_270;
    return rotation;
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
      oled_write_P(PSTR("COLMK"), false);
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
