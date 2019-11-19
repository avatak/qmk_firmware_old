#include "avatak.h"

#ifdef AUDIO_ENABLE
//    float tone_puzzle[][2] = SONG(ZELDA_PUZZLE);
//    float tone_treasure[][2] = SONG(ZELDA_TREASURE);
/*
    float tone_mushroom[][2] = SONG(\
        S__NOTE(_C5 ), \
        S__NOTE(_G4 ), \
        S__NOTE(_C5 ), \
        S__NOTE(_E5 ), \
        S__NOTE(_G5 ), \
        S__NOTE(_C6 ), \
        S__NOTE(_G5 ), \
        S__NOTE(_GS4), \
        S__NOTE(_C5 ), \
        S__NOTE(_DS5), \
        S__NOTE(_GS5), \
        S__NOTE(_DS5), \
        S__NOTE(_GS5), \
        S__NOTE(_C6 ), \
        S__NOTE(_DS6), \
        S__NOTE(_GS6), \
        S__NOTE(_DS6), \
        S__NOTE(_AS4), \
        S__NOTE(_D5 ), \
        S__NOTE(_F5 ), \
        S__NOTE(_AS5), \
        S__NOTE(_D6 ), \
        S__NOTE(_F6 ), \
        S__NOTE(_AS6), \
        S__NOTE(_F6 ),
        );
*/
    float tone_coin[][2] = SONG(\
        E__NOTE(_A5  ), \
        HD_NOTE(_E6  ),
        );
/*
    float tone_mountain[][2] = SONG(\
        Q__NOTE(_B2), QD_NOTE(_DF3), Q__NOTE(_D3), QD_NOTE(_E3), \
        QD_NOTE(_GF3), QD_NOTE(_D3), H__NOTE(_GF3), MUSICAL_NOTE(NOTE_REST, ), \
        QD_NOTE(_F3), QD_NOTE(_DF3), H__NOTE(_F3), BD_NOTE(_REST), \
        QD_NOTE(_E3), QD_NOTE(_C3), H__NOTE(_E3), BD_NOTE(_REST), E__NOTE(_REST), \
        Q__NOTE(_B2), QD_NOTE(_DF3), Q__NOTE(_D3), QD_NOTE(_E3), \
        Q__NOTE(_GF3), QD_NOTE(_D3), Q__NOTE(_GF3), \
        QD_NOTE(_B3), QD_NOTE(_A3), Q__NOTE(_GF3), QD_NOTE(_D3), Q__NOTE(_GF3), W__NOTE(_A3),\

    );
*/
#endif

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_coin);
            #endif
            break;
        case COLEMAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAC);
            }
            #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_coin);
            #endif
            break;
        case DCLICK:
            if (record->event.pressed) {
                tap_code16(KC_BTN1);
                tap_code16(KC_BTN1);
            }
            break;
        case RGBRST:
            #if defined(RGBLIGHT_ENABLE)
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                }
            #endif
            break;
        // Latex specific keycodes
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
        case DISPMATH:
            if (record->event.pressed) {
                SEND_STRING("\\[\\]" SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_UP));
                tap_code(KC_TAB);
            }
            break;
        case ENUMERATE:
            if (record->event.pressed) {
                SEND_STRING("\\begin{enumerate}" SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{enumerate}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            }
            break;
        case ITEM:
            if (record->event.pressed) {
                SEND_STRING("\\item");
            }
            break;
        case ITEMIZE:
            if (record->event.pressed) {
                SEND_STRING("\\begin{itemize}"SS_TAP(X_ENTER) SS_TAP(X_ENTER) "\\end{itemize}" SS_TAP(X_UP) SS_TAP(X_TAB) "\\item ");
            `
            break;
        case LEFTRIGHT:
            if (record->event.pressed) {
                SEND_STRING("\\left(  \\right)" SS_LCTRL(SS_TAP(X_LEFT) SS_TAP(X_LEFT)) SS_TAP(X_LEFT));
            }
            break;
        case LEMMA:
            if (record->event.pressed) {
                SEND_STRING("\\begin{lemma}[]"SS_TAP(X_ENTER)SS_TAP(X_ENTER)"\\end{lemma}"SS_TAP(X_UP)SS_TAP(X_TAB));
            }
            break;
        case LINEMATH:
            if (record->event.pressed) {
                SEND_STRING("\\(\\)" SS_TAP(X_LEFT) SS_TAP(X_LEFT) "  " SS_TAP(X_LEFT));
            }
            break;
        case SECTION:
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
    return process_record_keymap(keycode, record);
}
