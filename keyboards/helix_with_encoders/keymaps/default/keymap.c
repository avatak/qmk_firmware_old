/* Copyright 2019 Michael Shultz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


// Layers
enum custom_layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _COLEMAC_DH,
    _NAV,
    _MNAV,
    _TEX,
    _SYM,
    _NUM,
    _MWIN,
    _MEDIA,
    _ADJUST
};

/*  Custom keycode definitions */ 

/* Layer changes */

    #define ADJUST MO(_ADJUST)
    #define MEDIA MO(_MEDIA)
    #define MACWIN MO(_MWIN)
    #define MNAVESC LT(_MNAV, KC_ESC)
    #define MNAVSPC LT(_MNAV, KC_SPC)
    #define NAVESC LT(_NAV, KC_ESC)
    #define NAVSPC LT(_NAV, KC_SPC)
    #define NUMPAD TT(_NUM)
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
    SECTN,
    THEOREM,
    QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
   /*  QWERTY 
    *  ,-----------------------------------------------.                        ,-----------------------------------------------.
    *  |  '    |  1    |  2    |  3    |  4    |  5    |                        |   6   |   7   |   8   |   9   |   0   | BSPC  |
    *  |-------+-------+-------+-------+-------+-------|                        |-------+-------+-------+-------+-------+-------|
    *  | Tab   |  Q    |  W    |  E    |  R    |  T    |                        |   Y   |  U    |  I    |   O   |   P   |  \    |
    *  |-------+-------+-------+-------+-------+-------|                        |-------+-------+-------+-------+-------+-------|
    *  |ESC/NAV| A     |  S    |  D    |  F    |  G    |                        |   H   |   J   |   K   |   L   | ;-GUI |   '   |
    *  |-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------|
    *  |SHIFT  |  Z    |  X    |  C    |  V    |  B    |       |        |       |   N   |   M   |   ,   |   .   | /-CTL | SHIFT |
    *  |-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
    *  |ADJUST | CTRL  |       | GUI   | ALT   |SPC/NAV|       |        |SYM/ENT|TEX/SPC|ALTCTL |ALTSHFT|       |       |MEDIA  |
    *  `-------------------------------------------------------'        `-------------------------------------------------------'
    */
    
    [_QWERTY] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, 
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS, 
        NAVESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , GUISCLN, KC_QUOT, 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______, _______, KC_N   , KC_M   , KC_COMM, KC_DOT , CTLSLSH, KC_RSFT, 
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUMPAD , SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, MEDIA  
    ),

   /*  QWERTY 
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |  '    |  1    |  2    |  3    |  4    |  5    |               |   6   |   7   |   8   |   9   |   0   | BSPC  |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  | Tab   |  Q    |  W    |   F   |  P    |   B   |               |   J   |   L   |   U   |   Y   | ;-GUI |   \   |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |ESC/NAV|  A    |  R    |   S   |  T    |   G   |               |   K   |   N   |   E   |   I   |   O   |   '   |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |SHIFT  |  Z    |   X   |   C   |  D    |   V   |       |       |   M   |   H   |   ,   |   .   | /-CTL | SHIFT |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |ADJUST | CTRL  |       | GUI   | ALT   |SPC/NAV|NUMPAD |SYM/ENT|TEX/SPC|ALTCTL |ALTSHFT|       |       |MEDIA  |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_COLEMAK_DH] = LAYOUT(/* Base */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, 
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS, 
        NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______, _______, KC_M   , KC_H   , KC_COMM, KC_DOT , CTLSLSH, KC_RSFT, 
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUMPAD , SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, MEDIA  
    ),


    [_COLEMAC_DH] = LAYOUT( /* Variation of above with shifted codes more appropriate for using a mac */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, 
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , CTLSCLN, KC_BSLS, 
        MNAVESC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, 
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______, _______, KC_M   , KC_H   , KC_COMM, KC_DOT , GUISLSH, KC_RSFT, 
        ADJUST , KC_LCTL, _______, KC_LALT, KC_LGUI, MNAVSPC, NUMPAD , SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, MEDIA  
    ),

    /* NAVIGATION
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |ALT+F4 |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |CTL+PUP| PG UP |CTL+PDN|       |               |       |TABLEFT|  UP   |TABRGHT|       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       | HOME  | PG DN | END   |       |               |CTL+ <-| LEFT  |  DOWN | RIGHT |CTL+ ->|       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |CAPSLCK| INSERT|       |       |       |CTLBSPC| BKSPC |  DEL  |CTL+DEL|CTL+0  |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       | ENTER |       |       |       |       | F12   |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, ALT_F4 , _______,                   _______, _______, _______, _______, _______, _______, \
        _______, _______, CTLPGUP, KC_PGUP, CTLPGDN, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, _______, \
        _______, _______, KC_HOME, KC_PGDN, KC_END , _______,                   CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, _______, \
        _______, _______, _______, KC_CAPS, KC_INS , _______, _______, _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , CTLZERO, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 \
    ),

    [_MNAV] = LAYOUT(
        _______, _______, _______, _______,LGUI(KC_Q), _______,                 _______, _______, _______, _______, _______, _______, \
        MACWIN , _______, CTLPGUP, KC_PGUP, CTLPGDN, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, _______, \
        _______, _______, MACHOME, KC_PGDN, MACEND , _______,                   ALTLEFT, KC_LEFT, KC_DOWN, KC_RGHT, ALTRGHT, _______, \
        _______, _______, _______, KC_CAPS, KC_INS , _______, _______, _______, ALTBSPC, KC_BSPC, KC_DEL , ALTDEL , CTLZERO, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, S(LALT(KC_T)) \
    ),

    /* LaTeX and math, 
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |SECTION| ENUM  |ITEMIZE|LFT/RGT|       |               |       |   [   |   ]   | \( \) | \[ \] |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |ALIGN* | ARRAY |       | \ITEM |       |               |       |   {   |   }   |   (   |   )   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       | LEMMA |THEOREM|       |       |       |       |       |   -   |   _   |   +   |   =   |   \   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |MO(_SYM|       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_TEX] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, SECTN  , ENUM   , ITEMZ  , LFTRGHT, _______,                   _______, KC_LBRC, KC_RBRC, LINEMTH, DISPMTH, _______, \
        _______, ALIGN  , ARRAY  , _______, ITEM   , _______,                   _______, KC_LCBR, KC_RCBR, S(KC_9), S(KC_0), _______, \
        _______, LEMMA  , THEOREM, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS, S(KC_EQL),KC_EQL, KC_BSLS, _______, \
        _______, _______, _______, _______, _______, SYMBOL , _______, _______, _______, _______, _______, _______, _______, _______
    ),

   /* Symbols, numbers, and function keys
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |  F1   |   F2  |   F3  |   F4  |  F5   |               |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |   ~   |   !   |   @   |   #   |   $   |   %   |               |   ^   |   &   |  *    |   (   |   )   |  F12  |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |   `   |   1   |   2   |   3   |    4  |   5   |       |       |   6   |   7   |  8    |   9   |   0   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
        KC_TILD, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12 ,
        KC_GRV , KC_1   ,  KC_2  , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


   /* Layer for moving windows with magnet on osx
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |L 1/3  |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |FULL SC|       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */


    [_MWIN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   MW_L13 , MW_ULFT, MW_UPPR, MW_URIT, MW_R13 , _______,
        _______, _______, _______, _______, _______, _______,                   MW_LEFT, MW_L23 , MW_CENT, MW_R23 , MW_RGHT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, MW_L13 , MW_LLFT, MW_LOWR, MW_LRIT, MW_R13 , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, MW_FULL, _______, _______, _______, _______, _______
    ),

   /* Media  
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       | play  | vol up|       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       | prev  | vol dn|  next |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       | mute  |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______
    ),

   /* Media control 
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |NUMLCK |  *    |   /   |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |   7   |   8   |   9   |   -   |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |SFT+TAB|   4   |   5   |   6   |   +   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       | TAB   |   1   |   2   |   3   |   =   |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |SFT+ENT|ENTER  |   0   |   ,   |   .   |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, KC_NLCK, KC_PAST, KC_PSLS, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, _______, _______, _______, _______, _______,                 S(KC_TAB), KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_TAB , KC_P1  , KC_P2  , KC_P3  , KC_EQL , _______,
        _______, _______, _______, _______, _______, _______,_______,S(KC_ENT), KC_ENT , KC_P0  , KC_COMM, KC_PDOT, _______, _______
    ),

   /* Adjustment layer
    *  ,-----------------------------------------------.               ,-----------------------------------------------.
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------|               |-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |               |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    *  |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
    *  `---------------------------------------------------------------------------------------------------------------'
    */

    [_ADJUST] = LAYOUT(
        RESET  , _______, _______, _______, _______, _______,                   RGBRST , _______, _______, _______, _______, RGB_TOG,
        _______, QWERTY , _______, _______, _______, _______,                   _______, RGB_SAD, RGB_HUI, RGB_SAI, _______, _______,
        _______, AU_TOG , _______, _______, _______, _______,                   _______,RGB_RMOD, RGB_HUD, RGB_MOD, _______, _______,
        _______, _______, _______, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, _______, _______, _______
    )
};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

// Will be used for maintaining same shortcuts in defferent operating systems

bool os_undo(void);
bool os_redo(void);

int os_status = 0;

bool os_undo(void) {
    if (os_status == 1) {
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
    } else {
        register_code(KC_LCTL);
        tap_code(KC_Z);
        unregister_code(KC_LCTL);
    }
    return false;
}

bool os_redo(void) {
    if (os_status == 1) {
        register_code(KC_LSFT);
        register_code(KC_LGUI);
        tap_code(KC_Z);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
    } else {
        register_code(KC_LSFT);
        register_code(KC_LCTL);
        tap_code(KC_Z);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
    return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
                os_status = _COLEMAK_DH;
            }
            break;
        case COLEMAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAC_DH);
                os_status = _COLEMAC_DH;
            }
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                os_status = _COLEMAK_DH;
            }
            break;
        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                }
            #endif
            break;
    
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
                SEND_STRING("\\[" SS_TAP(X_ENTER) SS_TAP(X_ENTER)"\\]" SS_TAP(X_UP) SS_TAP(X_TAB));
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
                SEND_STRING("\\(\\)" SS_TAP(X_LEFT) SS_TAP(X_LEFT) "   " SS_TAP(X_LEFT));
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



#ifdef ENCODER_ENABLE
    void encoder_update_user(uint8_t index, bool clockwise) {

    // LEFT KNOB

        if (index == 0) {
            // NAV LAYER
            if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
            // TEX Layer
            else if (IS_LAYER_ON(_TEX)) {
                if (clockwise) {
                    os_redo();
                }
                else {
                    os_undo();
                }
            }
            // ADJUST layer
            else if (IS_LAYER_ON(_ADJUST)) {
                if (clockwise) {
                    tap_code16(RGB_HUI);
                } else {
                    tap_code16(RGB_HUD);
                }
            }
            else if (IS_LAYER_ON(_MEDIA)) {
                if (clockwise) {
                    tap_code16(KC_VOLD);
                } else {
                    tap_code16(KC_VOLU);
                }
            }
            // DEFAULT
            else {
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            }
        }

// RIGHT KNOB
    
    else if (index == 1) {
        //  NAV LAYER
        if (IS_LAYER_ON(_NAV) | IS_LAYER_ON(_MNAV)) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        // Symbol layer
        else if (IS_LAYER_ON(_SYM)) {
            if (clockwise) {
                tap_code(KC_SPC);
            } else {
                tap_code(KC_BSPC);
            }
        }
        // Adjust layer
        else if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                tap_code16(RGB_MOD);
            } else {
                tap_code16(RGB_RMOD);
            }
        }
        // Media layer
        else if (IS_LAYER_ON(_MEDIA)) {
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        // DEFAULT
        else {
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    }
  }
#endif

#ifdef OLED_DRIVER_ENABLE
    void oled_task_user(void) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Qwerty\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak\n"), false);
                break;
            case _COLEMAC_DH:
                oled_write_P(PSTR("Colemac\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _MNAV:
                oled_write_P(PSTR("Nav (OSX)\n"), false);
                break;
            case _TEX:
                oled_write_P(PSTR("LaTeX\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbol\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            case _MWIN:
                oled_write_P(PSTR("MacWin\n"), false);
                break;
            case _Media:
                oled_write_P(PSTR("Media\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        // Host Keyboard LED Status
        uint8_t led_usb_state = host_keyboard_leds();
        oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
    }

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (!is_keyboard_master())
            return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
        return rotation;
    }

    void oled_task_user(void) {
        if (is_keyboard_master()) {
            render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        } else {
            render_logo();       // Renders a statuc logo
            oled_scroll_left();  // Turns on scrolling
        }
    }
#endif






