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
    _COLEMAK = 0,
    _COLEMAC,
    _NAV,
    _MNAV,
    _TEX,
    _SYM,
    _NUM,
    _MWIN,
    _ADJUST,
    _LAST
};

/*  Custom keycode definitions */
/* Layer changes */

    #define ADJUST MO(_ADJUST)
    #define MACWIN MO(_MWIN)
    #define MEDIA MO(_MEDIA)
    #define MNAVESC LT(_MNAV, KC_ESC)
    #define MNAVSPC LT(_MNAV, KC_SPC)
    #define MO_NAV MO(_NAV)
    #define NAVESC LT(_NAV, KC_ESC)
    #define NAVSPC LT(_NAV, KC_SPC)
    #define NUM_TAP TT(_NUM)
    #define NUM_TOG TG(_NUM)
    #define SYMENT LT(_SYM, KC_ENT)
    #define SYMBOL MO(_SYM)
    #define TEXSPC LT(_TEX, KC_SPC)

    /* Custom combination keycodes */

    #define ALTBSPC LALT(KC_BSPC)
    #define ALTCTL LCTL(KC_LALT)
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
    #define CTLSHFT LCTL(KC_LSFT)
    #define CTLZERO LCTL(KC_0)
    #define MACEND LGUI(KC_RIGHT)
    #define MACHOME LGUI(KC_LEFT)
    #define TABLEFT LCTL(LSFT(KC_TAB))
    #define TABRGHT LCTL(KC_TAB)

    /* Dual function keys */

    #define ALT_COM ALT_T(KC_COMM)
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
    TIMETST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


   /*  COLEMAK MOD-DH
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

    [_COLEMAK] = LAYOUT(/* Base */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                     KC_J   , KC_L   , KC_U   , KC_Y   , GUISCLN, KC_BSLS,
        NAVESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                     KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_TAB , S(KC_TAB), KC_M   , KC_H   , ALT_COM, KC_DOT , CTLSLSH, KC_RSFT,
        ADJUST , KC_LCTL, _______, KC_LGUI, KC_LALT, NAVSPC , NUM_TAP,   SYMENT , TEXSPC , KC_HYPR, KC_SPC , ALTSHFT, ALTCTL , ADJUST
    ),


    [_COLEMAC] = LAYOUT( /* Variation of above with shifted codes more appropriate for using a mac */
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , CTLSCLN, KC_BSLS,
        MNAVESC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , _______, _______, KC_M   , KC_H   , ALT_COM, KC_DOT , GUISLSH, KC_RSFT,
        ADJUST , KC_LCTL, _______, KC_LALT, KC_LGUI, MNAVSPC, NUM_TAP, SYMENT , TEXSPC , ALTCTL , ALTSHFT, _______, _______, ADJUST
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
        _______, _______, CTLPGUP, KC_PGUP, CTLPGDN, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, S(LCTL(LALT(KC_S))), \
        _______, _______, KC_HOME, KC_PGDN, KC_END , _______,                   CTLLEFT, KC_LEFT, KC_DOWN, KC_RGHT, CTLRGHT, KC_APP , \
        _______, _______, _______, KC_CAPS, KC_INS , KC_SLCK, _______, _______, CTLBSPC, KC_BSPC, KC_DEL , CTLDEL , CTLZERO, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT , _______, _______, _______, _______, KC_F12 \
    ),

    [_MNAV] = LAYOUT(
        _______, _______, _______, _______,LGUI(KC_Q), _______,                 _______, _______, _______, _______, _______, _______, \
        MACWIN , _______, CTLPGUP, KC_PGUP, CTLPGDN, _______,                   _______, TABLEFT, KC_UP  , TABRGHT, _______, _______, \
        _______, _______, MACHOME, KC_PGDN, MACEND , _______,                   ALTLEFT, KC_LEFT, KC_DOWN, KC_RGHT, ALTRGHT, _______, \
        _______, _______, _______, KC_CAPS, KC_INS , KC_SLCK, _______, _______, ALTBSPC, KC_BSPC, KC_DEL , ALTDEL , CTLZERO, _______, \
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
        _______, _______, _______, _______, _______, _______,                   _______, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL , KC_P1  , KC_P2  , KC_P3  , KC_TAB , S(KC_TAB),
        _______, _______, _______, _______, _______, _______,_______,S(KC_ENT), KC_ENT , KC_P0  , KC_COMM, KC_PDOT, KC_ENT , S(KC_ENT)
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
        RESET  , _______, _______, _______, _______, _______,                   RGB_TOG, _______, _______, _______, _______, RGBRST ,
        _______, TIMETST, _______, RGB_VAI, _______, _______,                   RGB_SPI, RGB_HUI, _______, _______, _______, _______,
        _______, _______, RGB_SAD, RGB_VAD, RGB_SAI, _______,                   RGB_SPD, RGB_HUD, KC_MPLY, KC_VOLU, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,RGB_RMOD, RGB_MOD, KC_MPRV, KC_VOLD, KC_MNXT, _______,
        _______, _______, _______, _______, _______, COLEMAK, _______, _______, COLEMAC, _______, _______, KC_MUTE, _______, _______
    )
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

// Will be used for maintaining same shortcuts in defferent operating systems

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

uint16_t key_timer;
bool key_triggered = false;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                os_status = _COLEMAK;
            }
            break;
        case COLEMAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAC);
                os_status = _COLEMAC;
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
        case TIMETST:
            if (record->event.pressed) {
                key_timer = timer_read();
                key_triggered = true;
            } else {
                if ( key_triggered && ( timer_elapsed(key_timer) < 100 ) ) {
                    tap_code(KC_X);
                } else {
                    tap_code(KC_X);
                    tap_code(KC_X);
                }
                key_triggered = false;
            }
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
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
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
                rgblight_step();
            } else {
                rgblight_step_reverse();
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



// OLED Driver Logic
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_270;
    else if (!is_keyboard_master())
        return OLED_ROTATION_180;
    else
        return rotation;
}

// Render to mode icon
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };


void render_layer_state(void) {
    oled_write_P(PSTR("\nLayer"), false);
    oled_write_P(PSTR("-----"), false);
    uint8_t layer = layer_state ? biton(layer_state) : biton32(default_layer_state);
    switch (layer) {
        case _COLEMAK:
            oled_write_P(PSTR("COLMK"), false);
            break;
        case _COLEMAC:
            oled_write_P(PSTR("CLMAC"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("  NAV"), false);
            break;
        case _TEX:
            oled_write_P(PSTR("LaTeX"), false);
            break;
        case _MNAV:
            oled_write_P(PSTR(" MNAV"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMBL"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMPD"), false);
            break;
        case _MWIN:
            oled_write_P(PSTR(" MWIN"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("  ADJ"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
        }
    oled_write_P(PSTR("\n"), false);
}

void render_keylock_status(uint8_t led_usb_state) {
    uint8_t led_state = host_keyboard_leds();
    oled_write_P(PSTR("Locks"), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_NUM_LOCK) ? PSTR("N") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_CAPS_LOCK) ? PSTR("C") : PSTR(" "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(IS_LED_ON(led_state, USB_LED_SCROLL_LOCK) ? PSTR("S") : PSTR(" "), false);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods "), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("S") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
}

static void render_logo(void) {
    static const char PROGMEM sol_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(sol_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(sol_icon, false);
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
        //oled_scroll_left();
    }
}

#endif
