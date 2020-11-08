# Default keymap does not have any overridden options from the rev1 / rev2 rules.mk files.
# Example:
#     if you wanted to disable EXTRAKEY_ENABLE, you would copy the line from the rev1/rules.mk file
#     and paste it in to this file, changing the yes to no. Like so:
# EXTRAKEY_ENABLE         = no       # Audio control and System control
#
# To keep things clean and tidy, as well as make upgrades easier, only place overrides from the defaults in this file.
USER_NAME := avatak
DEFAULT_FOLDER = rev1/

# Keycode Options
BOOTMAGIC_ENABLE        = no        # Virtual DIP switch configuration
MOUSEKEY_ENABLE         = yes        # Mouse keys
EXTRAKEY_ENABLE         = yes       # Audio control and System control
UNICODE_ENABLE          = no        # Unicode keycodes
NKRO_ENABLE             = no        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

# Debug Options
CONSOLE_ENABLE          = no        # Console for debug
COMMAND_ENABLE          = no        # Commands for debug and configuration

# RGB Options
RGBLIGHT_ENABLE         = yes       # Enable global lighting effects. Do not enable with RGB Matrix
RGBLIGHT_ANIMATIONS     = yes       # LED animations
LED_MIRRORED            = yes       # Mirror LEDs across halves (enable DIP 1 on slave, and DIP 2 and 3 on master)

RGB_MATRIX_ENABLE       = no #WS2812	# Enable per-key coordinate based RGB effects. Do not enable with RGBlight
#RGB_MATRIX_ENABLE       = WS2812
RGB_MATRIX_KEYPRESSES   = no        # Enable reactive per-key effects.
RGB_MATRIX_FRAMEBUFFER_EFFECTS = no # Enable frame buffer effects like the typing heatmap.

RGBLIGHT_FULL_POWER     = no        # Allow maximum RGB brightness for RGBLIGHT or RGB_MATRIX. Otherwise, limited to a safe level for a normal USB-A port
IOS_DEVICE_ENABLE       = no        # Limit max brightness to connect to IOS device (iPad,iPhone)

# Misc
OLED_DRIVER_ENABLE      = yes        # Enable the OLED Driver

SWAP_HANDS_ENABLE       = no        # Enable one-hand typing
ENCODER_ENABLE = yes

# Do not edit past here
include keyboards/$(KEYBOARD)/post_rules.mk
