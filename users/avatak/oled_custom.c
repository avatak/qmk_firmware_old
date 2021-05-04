#include "oled_custom.h"

/* Rotation for vertical screens on split */
#ifndef OLED_DISPLAY_128X64
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (is_keyboard_master())
            return OLED_ROTATION_270;
        else if (!is_keyboard_master())
            return OLED_ROTATION_180;
        else
            return rotation;
    }
#else
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_180;
    }
#endif

/* Custom keymap icon */
static const char PROGMEM custom_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
};

void render_layer_state(void) {
//    #ifdef OLED_DISPLAY_128X64
    oled_write_P(PSTR("\n"), false);
//    #endif
    oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);
    #ifndef OLED_DISPLAY_128X64
        oled_write_P(PSTR("-----"), false);
    #endif
    switch (get_highest_layer(layer_state)) {
        case _CLMK:
            oled_write_P(PSTR(OLED_RENDER_LAYER_CLMK), false);
            break;
        case _CLMAC:
            oled_write_P(PSTR(OLED_RENDER_LAYER_CLMAC), false);
            break;
        case _NAV:
            oled_write_P(PSTR(OLED_RENDER_LAYER_NAV), false);
            break;
        case _MNAV:
            oled_write_P(PSTR(OLED_RENDER_LAYER_MNAV), false);
            break;
        case _TEX:
            oled_write_P(PSTR(OLED_RENDER_LAYER_TEX), false);
            break;
        case _SYM:
            oled_write_P(PSTR(OLED_RENDER_LAYER_SYM), false);
            break;
        case _NUM:
            oled_write_P(PSTR(OLED_RENDER_LAYER_NUM), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR(OLED_RENDER_LAYER_MEDIA), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR(OLED_RENDER_LAYER_MOUSE), false);
            break;
        case _MWIN:
            oled_write_P(PSTR(OLED_RENDER_LAYER_MWIN), false);
            break;
        case _ADJ:
            oled_write_P(PSTR(OLED_RENDER_LAYER_ADJ), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
}

void render_keylock_status(uint8_t led_usb_state) {
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR(OLED_RENDER_LOCKS_NAME), false);
    #ifdef OLED_DISPLAY_128X64
        oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR(" NLCK") : PSTR("     "), false);
        oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR(" CAPS") : PSTR("     "), false);
        oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR(" SLCK") : PSTR("     "), false);
    #else
        oled_write_P(PSTR("-----"), false);
        oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("N") : PSTR(" "), false);
        oled_write_P(PSTR(" "), false);
        oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("C") : PSTR(" "), false);
        oled_write_P(PSTR(" "), false);
        oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("S") : PSTR(" "), false);
    #endif
}

void render_mod_status(uint8_t modifiers) {
    #ifdef OLED_DISPLAY_128X64
        oled_write_P(PSTR("Mods:"), false);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("Shft") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR(" Ctl") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR(" Alt") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR(" Gui") : PSTR("    "), false);
    #else
        oled_write_P(PSTR("\nMods "), false);
        oled_write_P(PSTR("-----"), false);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
    #endif
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
}

/*
#ifdef OLED_DISPLAY_128X64
    static void render_logo(void) {
        static const char PROGMEM custom_logo[] = {
            0x00,0x00,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x00,0x88,0x89,0x8a,0x80,0x88,0x89,0x8a,0x9A,0x9B,0x9C,0x00,
            0x00,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0x00,0xa8,0xa9,0xaa,0x80,0xa8,0xa9,0xaa,0xBA,0xBB,0xBC,0x00,
            0x00,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0x00,0xc8,0xc9,0xca,0x80,0xc8,0xc9,0xca,0xDA,0xDB,0xDC,0x00,
            0x00,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9a,0x00,0x9b,0x8c,0x8d,0x80,0x8e,0x8f,0x90,0x9D,0x9E,0x9F,0x00,
            0x00,0xb3,0xb4,0xb5,0xb6,0xb7,0xb8,0xb9,0xba,0x00,0xbb,0xac,0xad,0x80,0xae,0xaf,0xb0,0xBD,0xBE,0xBF,0x00,
            0x00,0xd3,0xd4,0xd5,0xd6,0xd7,0xd8,0xd9,0xda,0x00,0xdb,0xcc,0xcd,0x80,0xce,0xcf,0xd0,0xDD,0xDE,0xDF,0x00,0
        };
        oled_write_P(custom_logo, false);
    }
#else
    static void render_logo(void) {
        static const char PROGMEM custom_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        };
        oled_write_P(custom_logo, false);
    }
#endif
*/


static void render_logo(void) {
        static const char PROGMEM custom_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
        };
        oled_write_P(custom_logo, false);
    }

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(custom_icon, false);
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
        //oled_scroll_left();
    }
}
