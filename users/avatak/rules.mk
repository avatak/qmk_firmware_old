SRC	+=	avatak.c \
		process_records.c \

# ifeq ($(strip $(ENCODER_ENABLE)), yes)
# 	SRC += encoder_custom.c
# endif
# ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
# # ifdef	STD_OLED
# 	SRC += oled_custom.c
# endif

LTO_ENABLE = yes
