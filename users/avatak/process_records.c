#include "avatak.h"
#include "process_records.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CLMK);
            }
            /*
            #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_coin);
            #endif
            */
            break;
        case COLEMAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CLMAC);
            }
            /*
            #ifdef AUDIO_ENABLE
                PLAY_SONG(tone_coin);
            #endif
            */
            break;
        case ALIGN:
            if (record->event.pressed)
            {
                SEND_STRING("\\begin{align*}\n\\end{align*}");
                tap_code16(KC_HOME);
                tap_code16(KC_ENT);
                tap_code16(KC_UP);
                tap_code16(KC_TAB);
            }
            return false;
        case DISPMTH:
            if (record->event.pressed)
            {
                SEND_STRING("\\[");
            }
            return false;
        case LINEMTH:
            if (record->event.pressed)
            {
                SEND_STRING("\\(");
            }
            return false;
        case RGBRST:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                #endif
            }
            return false;
    }
    process_record_keymap(keycode, record);
    return true;
}

