# project specific files
SRC = ../../../drivers/led/sn32/matrix_sn32f24xx.c
SRC += rand.c

# MCU name
MCU = SN32F268F

# Build Options
#   comment out to disable the options.
#
LTO_ENABLE = no
MAGIC_ENABLE = yes
MAGIC_KEYCODE_ENABLE = yes
BOOTMAGIC_ENABLE = yes  # Virtual DIP switch configuration
EXTRAKEY_ENABLE = no   # Audio control and System control
NKRO_ENABLE = yes       # USB Nkey Rollover
DIP_SWITCH_ENABLE = no

# Custom Key and LED matrix handling
CUSTOM_MATRIX = yes
LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = SN32F26x

# Reduce code size
USE_PROCESS_STACKSIZE    = 0x1C0
USE_EXCEPTIONS_STACKSIZE = 0xF0
