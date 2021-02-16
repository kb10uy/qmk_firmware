/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#pragma once

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2
#define LAYER_STATE_8BIT

#undef DEBOUNCE
#define DEBOUNCE 3
#define USB_POLLING_INTERVAL_MS 2
// #define DEBUG_MATRIX_SCAN_RATE

#undef RGBLED_NUM
// #define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define RGBLIGHT_LAYERS
#define LED_LAYOUT( \
    B01, B02, B03, B04, B05, B06,  \
    B07, B08, B09, B10, B11, B12,  \
    B13, B14, B15, B16, B17, B18,  \
                   B19, B20, B21,  \
         U01,      U02,      U03,  \
         U04,      U05,      U06 ) \
{ \
    U03, U02, U01, U04, U05, U06,  \
    B21, B18, B12, B06, B05, B11,  \
    B17, B20, B19, B16, B10, B04,  \
    B03, B09, B15, B14, B08, B02,  \
    B01, B07, B13                  \
}

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
     0,  1,  2,  3,  4,  5, \
     6,  7,  8,  9, 10, 11, \
    12, 13, 14, 15, 16, 17, \
                18, 19, 20, \
    21, 22, 23, 24, 25, 26 )

#define TAPPING_TERM 175
