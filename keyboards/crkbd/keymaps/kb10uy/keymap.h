/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2025 KOBAYASHI Yū <@kb10uy>

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

#include QMK_KEYBOARD_H

// Enums ----------------------------------------------------------------------

enum kb10uy_layer {
    _DEFAULT = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum kb10uy_key_code {
    K1_CHOS = SAFE_RANGE,
    K1_JPN,
    K1_ENG,
};

enum kb10uy_tap_dance {
    KB10UY_TD_FN1 = 0,
};

enum kb10uy_os_mode {
    K1_WINDOWS = 0,
    K1_MACOS,
    K1_LINUX,
    K1_ANDROID,
    K1_OS_MAX,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t os_mode;
    };
} kb10uy_config_t;

// Keycode Macros -------------------------------------------------------------

#define TD_FN1 (TD(KB10UY_TD_FN1))
#define MO_RAI (MO(_RAISE))
#define TT_ADJ (TT(_ADJUST))

// Function Declarations ------------------------------------------------------

void            keyboard_post_init_user(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool            process_record_user(uint16_t keycode, keyrecord_t *record);
void            change_next_os_mode(void);
void            update_os_mode_setting(void);
void            load_sync_config(void);
void            sync_save_config(void);
void            dance_fn1_finished(tap_dance_state_t *state, void *user_data);
void            dance_fn1_reset(tap_dance_state_t *state, void *user_data);
bool            oled_task_user(void);
bool            oled_render_info(void);
bool            oled_render_logo(void);
