#include "avatak.h"
#include "process_records.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }


// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALIGN:
            if (record->event.pressed)
            {
                // TODO
            }
            return false;
            break;
    }

    process_record_keymap(keycode, record);
    return true;
}
