MOUSEKEY_ENABLE     = no     # Mouse keys
RGBLIGHT_ENABLE     = yes    # Enable WS2812 RGB underlight.
OLED_DRIVER_ENABLE  = yes
TAP_DANCE_ENABLE    = yes
LTO_ENABLE          = yes
CONSOLE_ENABLE      = no

SPLIT_TRANSPORT     = custom
QUANTUM_LIB_SRC    += serial.c
SRC                += transport_ex.c
