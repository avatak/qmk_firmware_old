#pragma once
#include QMK_KEYBOARD_H

#include "encoder_custom.h"
#include "layouts.h"
#include "oled_custom.h"
#include "process_records.h"
#include "quantum.h"

#ifdef ENCODER_ENABLE
#   include "encoder_custom.h"
#endif

enum userspace_layers {
    _CLMK = 0,
    _NAV,
    _TEX,
    _SYM,
    _NUM,
    _MEDIA,
    _ADJ
};

/* Layer shifting */
#define ADJUST TT(_ADJ)
#define NAVSPC LT(_NAV, KC_SPC)
#define NAVESC LT(_NAV, KC_ESC)
#define NUMTAP TT(_NUM)
#define SYMENT LT(_SYM, KC_ENT)
#define TEXSPC LT(_TEX, KC_SPC)


/* Mod tap keys */
#define ALTCOMM ALT_T(KC_COMM)
#define CTLSLSH CTL_T(KC_SLSH)
#define GUIDOT GUI_T(KC_DOT)
#define GUISCLN GUI_T(KC_SCLN)

/* Custom combos */
#define ALT_F2  LALT(KC_F2)
#define ALT_F3  LALT(KC_F3)
#define ALT_F4  LALT(KC_F4)
#define ALTCTL  LALT(KC_LCTL)
#define ALTSHFT LALT(KC_LSFT)
#define CTLBSPC LCTL(KC_BSPC)
#define CTLDEL  LCTL(KC_DEL)
#define CTLLEFT LCTL(KC_LEFT)
#define CTLRGHT LCTL(KC_RGHT)
#define CTLPGDN LCTL(KC_PGDN)
#define CTLPGUP LCTL(KC_PGUP)
#define CTLSHFT LCTL(KC_LSFT)
#define CTLZERO LCTL(KC_0)
#define TABLEFT LCTL(KC_PGUP)
#define TABRGHT LCTL(KC_PGDN)
