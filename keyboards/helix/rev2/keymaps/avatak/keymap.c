#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "avatak.h"

#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif

#ifdef AUDIO_ENABLE
    #include "audio.h"
#endif

#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif



#ifdef RGBLIGHT_ENABLE
  //Following line allows macro to read current RGB settings
  extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_wrapper( \
      KC_GRV , __NUMBER_L_________________________________,                   __NUMBER_R_________________________________, KC_BSPC, \
      KC_TAB , __COLEMAK_L1_______________________________,                   __COLEMAK_R1_______________________________, KC_BSLS, \
      NAVESC , __COLEMAK_L2_______________________________,                   __COLEMAK_R2_______________________________, KC_QUOT, \
      KC_LSFT, __COLEMAK_L3_______________________________, _______, _______, __COLEMAK_R3_______________________________, KC_RSFT, \
      ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUM_TAP, SYMENT , TEXSPC , KC_HYPR, CTLSHFT, ALTCTL , ALTSHFT, ADJUST  \
      ),

    [_NAV] = LAYOUT_wrapper( \
        _______, _______, _______, _______, WINQUIT, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, __NAV_L1___________________________________,                   __NAV_R1___________________________________, _______, \
        _______, __NAV_L2___________________________________,                   __NAV_R2___________________________________, _______, \
        _______, __NAV_L3___________________________________, _______, _______, __NAV_R3___________________________________, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
  
    [_TEX] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
    
    [_SYM] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_NUM] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_ADJUST] = LAYOUT( \
        RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
};



#ifdef AUDIO_ENABLE
    float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
    float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
    float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
    float tone_plover[][2]     = SONG(PLOVER_SOUND);
    float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
    float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

    void startup_user()
    {
        _delay_ms(20); // gets rid of tick
    }

    void shutdown_user()
    {
        _delay_ms(150);
        stop_all_notes();
    }

    void music_on_user(void)
    {
        music_scale_user();
    }

    void music_scale_user(void)
    {
        PLAY_SONG(music_scale);
    }

#endif


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_keymap(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_COLEMAK 0
#define L_NAV (1<<_NAV)
#define L_TEX (1<<_TEX)
#define L_SYM (1<<_SYM)
#define L_NUM (1<<_NUM)
#define L_ADJUST (1<<_ADJUST)

static void render_logo(struct CharacterMatrix *matrix) {

  static const char helix_logo[] PROGMEM ={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write_P(matrix, helix_logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}

static void render_rgbled_status(bool full, struct CharacterMatrix *matrix) {
#ifdef RGBLIGHT_ENABLE
  char buf[30];
  if (RGBLIGHT_MODES > 1 && rgblight_config.enable) {
      if (full) {
          snprintf(buf, sizeof(buf), " LED %2d: %d,%d,%d ",
                   rgblight_config.mode,
                   rgblight_config.hue/RGBLIGHT_HUE_STEP,
                   rgblight_config.sat/RGBLIGHT_SAT_STEP,
                   rgblight_config.val/RGBLIGHT_VAL_STEP);
      } else {
          snprintf(buf, sizeof(buf), "[%2d] ",rgblight_config.mode);
      }
      matrix_write(matrix, buf);
  }
#endif
}

static void render_layer_status(struct CharacterMatrix *matrix) {
  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[10];
  matrix_write_P(matrix, PSTR("Layer: "));
    switch (layer_state) {
        case L_COLEMAK:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_NAV:
           matrix_write_P(matrix, PSTR("Nav    "));
           break;
        case L_TEX:
           matrix_write_P(matrix, PSTR("LaTeX  "));
           break;
        case L_SYM:
           matrix_write_P(matrix, PSTR("Symbol "));
           break;
        case L_NUM:
           matrix_write_P(matrix, PSTR("Numpad "));
           break;
        case L_ADJUST:
           matrix_write_P(matrix, PSTR("Adjust "));
           break;
        default:
           matrix_write_P(matrix, PSTR("Undef-"));
           snprintf(buf,sizeof(buf), "%ld", layer_state);
           matrix_write(matrix, buf);
    }
}

void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static const char os_logo[][2][3] PROGMEM  ={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write_P(matrix, os_logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[0][1]);
  }else{
    matrix_write_P(matrix, os_logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write_P(matrix, os_logo[1][1]);
  }

  matrix_write_P(matrix, PSTR(" "));
  render_layer_status(matrix);
  matrix_write_P(matrix, PSTR("\n"));

  // Host Keyboard LED Status
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ?
                 PSTR("NUMLOCK") : PSTR("       "));
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ?
                 PSTR("CAPS") : PSTR("    "));
  matrix_write_P(matrix, (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ?
                 PSTR("SCLK") : PSTR("    "));
  matrix_write_P(matrix, PSTR("\n"));
  render_rgbled_status(true, matrix);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
    render_rgbled_status(false, &matrix);
    render_layer_status(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
