#pragma once
#include QMK_KEYBOARD_H

//#include "encoder_custom.h"
#include "layouts.h"
//#include "oled_custom.h"
#include "process_records.h"
#include "quantum.h"

//#ifdef ENCODER_ENABLE
//#   include "encoder_custom.h"
//#endif

enum userspace_layers {
    _COLEMAK = 0,
    _COLEMAC,
    _QWERTY,
    _NAV,
    _MNAV,
    _TEX,
    _SYM,
    _NUM,
    _MEDIA,
    _MOUSE,
    _MWIN,
    _UTIL,
    _ADJUST
};

/* Layer shifting */
#define ADJUST TT(_ADJUST)
#define NAVSPC LT(_NAV, KC_SPC)
#define MNAVSPC LT(_MNAV, KC_SPC)
#define NAVESC LT(_NAV, KC_ESC)
#define MNAVESC LT(_MNAV, KC_ESC)
#define NUMTAP TT(_NUM)
#define NUMTOG TG(_NUM)
#define SYMENT LT(_SYM, KC_ENT)
#define TEXSPC LT(_TEX, KC_SPC)
#define TOGUTIL TG(_UTIL)
#define MOUSE  TG(_MOUSE)

/* OSX Specific */
#define MACTERM S(LALT(KC_T))
#define MACEND LGUI(KC_RIGHT)
#define MACHOME LGUI(KC_LEFT)
#define MACMENU LCTL(KC_F2)
#define MACWIN MO(_MWIN)

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


/* Mod tap keys */
#define ALTCOMM ALT_T(KC_COMM)
#define CTLSCLN CTL_T(KC_SCLN)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUIDOT GUI_T(KC_DOT)
#define GUISCLN GUI_T(KC_SCLN)
#define GUISLSH GUI_T(KC_SLASH)

/* Custom combos */
#define ALT_F2  LALT(KC_F2)
#define ALT_F3  LALT(KC_F3)
#define ALT_F4  LALT(KC_F4)
#define ALTCTL  LALT(KC_LCTL)
#define ALTCTLS S(LALT(KC_LCTL))
#define ALTSHFT LALT(KC_LSFT)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL  LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLSHFT LCTL(KC_LSFT)
#define CTLZERO LCTL(KC_0)
#define CTRLSZR S(LCTL(KC_0))
#define GUILEFT LGUI(KC_LEFT)
#define GUIRIGHT LGUI(KC_RIGHT)
#define SCLEFT S(LCTL(KC_LEFT))
#define SCRIGHT S(LCTL(KC_RIGHT))
#define TABLEFT LCTL(KC_PGUP)
#define TABRGHT LCTL(KC_PGDN)
#define UNDOIT  LCTL(KC_Z)
#define REDOIT LCTL(KC_Y)
