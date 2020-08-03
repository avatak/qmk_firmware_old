#pragma once
#include "avatak.h"

#ifdef OLED_DISPLAY_128X64
#   define OLED_RENDER_LAYER_NAME   "Layer:"
#   define OLED_RENDER_LAYER_CLMK   "Colemak"
#   define OLED_RENDER_LAYER_NAV    "    Nav"
#   define OLED_RENDER_LAYER_TEX    "  LaTeX"
#   define OLED_RENDER_LAYER_SYM    " Symbol"
#   define OLED_RENDER_LAYER_NUM    " Numpad"
#   define OLED_RENDER_LAYER_ADJ    " Adjust"
#else
#   define OLED_RENDER_LAYER_NAME  "Layer"
#   define OLED_RENDER_LAYER_CLMK  "COLMK"
#   define OLED_RENDER_LAYER_NAV   "  NAV"
#   define OLED_RENDER_LAYER_TEX   "LATEX"
#   define OLED_RENDER_LAYER_SYM   "  SYM"
#   define OLED_RENDER_LAYER_NUM   "NUMPD"
#   define OLED_RENDER_LAYER_ADJ   "ADJST"
#endif

