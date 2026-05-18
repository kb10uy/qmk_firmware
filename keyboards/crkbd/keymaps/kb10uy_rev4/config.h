/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2026 KOBAYASHI Yū <@kb10uy>

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

// Split Data Sync
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSACTION_IDS_USER KB10UY_SYNC_STATE

// Debounce
#define DEBOUNCE 3

// Bootmagic Lite (hold on startup to jump to bootloader)
#undef BOOTMAGIC_ROW
#undef BOOTMAGIC_COLUMN
#undef BOOTMAGIC_ROW_RIGHT
#undef BOOTMAGIC_COLUMN_RIGHT
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0
#define BOOTMAGIC_ROW_RIGHT 4
#define BOOTMAGIC_COLUMN_RIGHT 0

// Tapping
#define TAPPING_TERM 175
#define TAPPING_TOGGLE 5

// RGB Matrix
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

// #define USE_MATRIX_I2C
