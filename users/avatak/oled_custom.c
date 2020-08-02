#include "oled_custom.h"

void render_default_layer_state(void) {
    oled_write_P(PSTR(OLED_RENDER_LAYER_NAME), false);
    #ifndef OLED_DISPLAY_128X64
        oled_write_P(PSTR("-----"), false);
    #endif
    switch (get_highest_layer(default_layer_state)) {
        case _CLMK:
            oled_write_P(PSTR(OLED_RENDER_LAYER_CLMK), false);
            break;
        case _NAV:
            oled_write_P(PSTR(OLED_RENDER_LAYER_NAV), false);
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
        case _ADJ:
            oled_write_P(PSTR(OLED_RENDER_LAYER_ADJ), false);
            break;
    }
}



