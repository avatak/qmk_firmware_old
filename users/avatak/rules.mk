SRC	+=	avatak.c \
		process_records.c \

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_custom.c
endif
ifdef CUSTOM_OLED
	SRC += oled_custom.c
endif

LINK_TIME_OPTIMIZATION_ENABLE = yes
