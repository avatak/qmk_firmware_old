# MCU details

MCU = STM32F303CCT6

# Build Options
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
ENCODER_ENABLE = yes        # Rotary encoder (knob) support
NKRO_ENABLE = yes           # USB Nkey Rollover
MIDI_ENABLE = yes            # MIDI support
UNICODE_ENABLE = no         # Unicode
RGBLIGHT_ENABLE = no       # RGB on pin C5
AUDIO_ENABLE = yes          # Audio output on pin C4 and B7




# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   atmega32a    bootloadHID
# BOOTLOADER = qmk_dfu


# If you don't know the bootloader type, then you can specify the
# Boot Section Size in *bytes* by uncommenting out the OPT_DEFS line
#   Teensy halfKay      512
#   Teensy++ halfKay    1024
#   Atmel DFU loader    4096
#   LUFA bootloader     4096
#   USBaspLoader        2048
# OPT_DEFS += -DBOOTLOADER_SIZE=4096


