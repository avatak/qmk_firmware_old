#pragma once
#include "avatak.h"

#ifdef OLED_DISPLAY_128X64
// " CAPS NLCK SLCK"
#   define OLED_RENDER_LAYER_NAME   "Layer:"
#   define OLED_RENDER_LOCKS_NAME   "\nLocks:"
#   define OLED_RENDER_LAYER_CLMK   "   Colemak"
#   define OLED_RENDER_LAYER_NAV    "Navigation"
#   define OLED_RENDER_LAYER_TEX    "     LaTeX"
#   define OLED_RENDER_LAYER_SYM    "    Symbol"
#   define OLED_RENDER_LAYER_NUM    "    Numpad"
#   define OLED_RENDER_LAYER_MEDIA  "     Media"
#   define OLED_RENDER_LAYER_ADJ    "    Adjust"
#   define OLED_RENDER_LOCK_CAPS    "CAPS"
#   define OLED_RENDER_LOCK_NLCK    "NLCK"
#   define OLED_RENDER_LOCK_SLCK    "SLCK"
#else
#   define OLED_RENDER_LAYER_NAME  "Layer"
#   define OLED_RENDER_LOCKS_NAME  "Locks"
#   define OLED_RENDER_LAYER_CLMK  "COLMK"
#   define OLED_RENDER_LAYER_NAV   "  NAV"
#   define OLED_RENDER_LAYER_TEX   "LATEX"
#   define OLED_RENDER_LAYER_SYM   "  SYM"
#   define OLED_RENDER_LAYER_NUM   "NUMPD"
#   define OLED_RENDER_LAYER_MEDIA "MEDIA"
#   define OLED_RENDER_LAYER_ADJ   "ADJST"
#endif

