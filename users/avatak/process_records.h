#pragma once
#include "avatak.h"

enum userspace_custom_keycodes {
    COLEMAK = SAFE_RANGE,
    COLEMAC,
    RGBRST,
    // LATEX SPECIFIC
    ALIGN,
    ARRAY,
    DISPMATH,
    DCLICK,
    ENUMERATE,
    ITEM,
    ITEMIZE,
    LEFTRIGHT,
    LEMMA,
    LINEMATH,
    SECTION,
    THEOREM,
    NEW_SAFE_RANGE,
};

// Mod Combos
#define ALTBSPC LALT(KC_BSPC)
#define ALT_COM ALT_T(KC_COMM)
#define ALTCTL LALT(KC_LCTL)
#define ALTCTLS S(LALT(KC_LCTL))
#define ALTDEL LALT(KC_DEL)
#define ALTLEFT LALT(KC_LEFT)
#define ALTRIGHT LALT(KC_RIGHT)
#define ALTSHFT LALT(KC_LSFT)
#define ALT_Q ALT_T(KC_Q)

#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRIGHT LCTL(KC_RIGHT)
#define CTL_SCLN CTL_T(KC_SCLN)
#define CTL_SLSH CTL_T(KC_SLASH)
#define CTLSHIFT LCTL(KC_LSFT)
#define CTLSHFT LCTL(KC_LSFT)

#define GUIDOT  GUI_T(KC_DOT)
#define GUILEFT LGUI(KC_LEFT)
#define GUIRIGHT LGUI(KC_RIGHT)
#define GUI_SCLN GUI_T(KC_SCLN)
#define GUI_SLSH GUI_T(KC_SLASH)

#define WINQUIT LALT(KC_F4)
#define MACQUIT LGUI(KC_Q)

// Layer switching
#define ADJUST MO(_ADJUST)
#define LNXWIN MO(_LWIN)
#define MACWIN MO(_MWIN)
#define MEDIA MO(_MEDIA)
#define MNAVESC LT(_MNAV, KC_ESC)
#define NAVESC LT(_NAV, KC_ESC)
#define MNAVSPC LT(_MNAV, KC_SPC)
#define MOUSE TT(_MOUSE)
#define NAVSPC LT(_NAV, KC_SPC)
#define NUM_TAP TT(_NUM)
#define NUM_TOG TG(_NUM)
#define SYMENT LT(_SYM, KC_ENT)
#define SYMSPC LT(_SYM, KC_SPC)
#define TEXSPC LT(_TEX, KC_SPC)

#define MACTERM S(LALT(KC_T))
#define MACEND LGUI(KC_RIGHT)
#define MACHOME LGUI(KC_LEFT)
#define MACMENU LCTL(KC_F2)
#define TABRIGHT LCTL(KC_TAB)
#define TABLEFT S(LCTL(KC_TAB))

// Mac Window Adjustment with magnet
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

// Linux (Manjaro KDE) Window Adjustment using my own assigned shortcuts

#define LW_LEFT LGUI(KC_LEFT)
#define LW_RGHT LGUI(KC_RIGHT)
#define LW_UP   LGUI(KC_UP)
#define LW_DOWN LGUI(KC_DOWN)
#define LW_ULFT S(LGUI(KC_LEFT))
#define LW_LLFT S(LGUI(KC_HOME))
#define LW_URGT S(LGUI(KC_RIGHT))
#define LW_LRGT S(LGUI(KC_END))
#define LW_FULL LGUI(KC_PGUP)
#define LW_NXTW S(LGUI(KC_TAB))
