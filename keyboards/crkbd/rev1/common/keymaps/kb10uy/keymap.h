/*
Copyright 2021 Yu Kobayashi <@kb10uy>

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

#include QMK_KEYBOARD_H
#include "transport_ex.h"

enum kb10uy_layers {
    _DEFAULT = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum kb10uy_key_code {
    K1_OLED = SAFE_RANGE,
    K1_WIMA,
    K1_JPN,
    K1_ENG,
};

enum kb10uy_tap_dance {
    KB10UY_TD_FN1 = 0,
};

enum kb10uy_sync_bit {
    KB10UY_SY_NUMLOCK = 0,
    KB10UY_SY_CAPSLOCK,
    KB10UY_SY_SCROLLLOCK,
    KB10UY_SY_RECORDING,
    KB10UY_SY_MACOS,
};

#define TD_FN1 (TD(KB10UY_TD_FN1))

void oled_render_master(void);
void oled_render_slave(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
void update_lighting_layers(layer_state_t state);
void toggle_recording(void);
void dance_fn1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_fn1_reset(qk_tap_dance_state_t *state, void *user_data);

