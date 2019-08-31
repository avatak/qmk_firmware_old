#include "avatak.h"

__attribute__ ((weak))
void matrix_init_keymap(void) {}

// Call user matrix init, then call the keymap's init function
void matrix_init_user(void) {
  #ifdef AUDIO_VOICES
      set_voice(duty_osc);
  #endif
  matrix_init_keymap();
}


__attribute__ ((weak))
void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) {
  matrix_scan_keymap();
} 