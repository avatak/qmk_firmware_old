# Default keymap does not have any overridden options from the rev1 / rev2 rules.mk files.
# Example:
#     if you wanted to disable EXTRAKEY_ENABLE, you would copy the line from the rev1/rules.mk file
#     and paste it in to this file, changing the yes to no. Like so:
# EXTRAKEY_ENABLE         = no       # Audio control and System control(+450)
#
# To keep things clean and tidy, as well as make upgrades easier, only place overrides from the defaults in this file.

OLED_DRIVER_ENABLE      = yes        # Enable the OLED Driver
ENCODER_ENABLE 			= yes
RGB_MATRIX_KEYPRESSES   = no
MOUSEKEY_ENABLE         = yes        # Mouse keys

# Special RGB Matrix, OLED, & Encoder Control Menu!
RGB_OLED_MENU           = no       # Enabled by setting this to the encoder index (0-5) you wish to use to control the menu.
                                    # Use the RGB_MENU keycode in the keymap for the encoder to advance the menu to the next option.

# Do not edit past here
include keyboards/$(KEYBOARD)/post_rules.mk
