/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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

#include "keymap.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX,    XXXXXXX,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, XXXXXXX,    XXXXXXX,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|--------'  `--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_INT1,
    //`--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                             MO_RAI,  TD_FN1, KC_LSFT,     KC_SPC,  KC_ENT, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [_LOWER] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,    XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,    XXXXXXX, KC_COMM,   KC_UP,  KC_DOT, KC_MINS,  KC_EQL, KC_INT3,
    //|--------+--------+--------+--------+--------+--------|--------'  `--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,                      KC_LEFT, KC_DOWN,KC_RIGHT, KC_LBRC, KC_RBRC, KC_BSLS,
    //`--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                             TT_ADJ,  TD_FN1, KC_LGUI,    KC_RSFT,  K1_ENG,  K1_JPN
                                        //`--------------------------'  `--------------------------'
    ),

    [_RAISE] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _______, K1_CHOS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, KC_CAPS, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_HOME, KC_PGUP,
    //|--------+--------+--------+--------+--------+--------|--------'  `--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LALT, XXXXXXX,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_END, KC_PGDN,
    //`--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                             MO_RAI, XXXXXXX, KC_LSFT,    KC_RSFT,  K1_ENG,  K1_JPN
                                        //`--------------------------'  `--------------------------'
                                        // NOTE: Layer move from Raise to Adjust is prohibited
    ),

    [_ADJUST] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|--------'  `--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_NUM,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX,
    //`--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                             TT_ADJ, XXXXXXX, XXXXXXX,    KC_PDOT,   KC_P0, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};

// clang-format on

tap_dance_action_t tap_dance_actions[] = {
    [KB10UY_TD_FN1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fn1_finished, dance_fn1_reset),
};

kb10uy_config_t config = {0};

bool    lower_locked = false;
uint8_t lang_keys[]  = {KC_INTERNATIONAL_5, KC_INTERNATIONAL_4};

static void set_indicator_key_color(uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t index = g_led_config.matrix_co[row][col];
    if (index != NO_LED) {
        rgb_matrix_set_color(index, r, g, b);
    }
}

void keyboard_post_init_user(void) {
    load_sync_config();
    update_os_mode_setting();
}

void eeconfig_init_user(void) {
    config.config_version = KB10UY_CONFIG_VERSION;
    config.os_mode        = K1_WINDOWS;

    eeconfig_update_user(config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K1_CHOS:
            if (record->event.pressed) {
                change_next_os_mode();
            }
            break;
        case K1_ENG:
            if (record->event.pressed) {
                register_code(lang_keys[0]);
            } else {
                unregister_code(lang_keys[0]);
            }
            break;
        case K1_JPN:
            if (record->event.pressed) {
                register_code(lang_keys[1]);
            } else {
                unregister_code(lang_keys[1]);
            }
            break;
    }
    return true;
}

void change_next_os_mode(void) {
    config.os_mode = (config.os_mode + 1) % K1_OS_MAX;
    update_os_mode_setting();
    sync_save_config();
}

void update_os_mode_setting(void) {
    switch (config.os_mode) {
        case K1_WINDOWS:
            lang_keys[0] = KC_INTERNATIONAL_5;
            lang_keys[1] = KC_INTERNATIONAL_4;
            break;
        case K1_MACOS:
            lang_keys[0] = KC_LANGUAGE_2;
            lang_keys[1] = KC_LANGUAGE_1;
            break;
        case K1_LINUX:
            lang_keys[0] = KC_INTERNATIONAL_5;
            lang_keys[1] = KC_INTERNATIONAL_4;
            break;
        case K1_ANDROID:
            lang_keys[0] = KC_INTERNATIONAL_5;
            lang_keys[1] = KC_INTERNATIONAL_4;
            break;
    }
}

void load_sync_config(void) {
    config.raw = eeconfig_read_user();
    if (config.config_version < KB10UY_CONFIG_VERSION) {
        eeconfig_init_user();
    }
}

void sync_save_config(void) {
    eeconfig_update_user(config.raw);
}

void dance_fn1_finished(tap_dance_state_t *state, void *user_data) {
    layer_on(1);

    if (state->count >= 2 && state->count < TAPPING_TOGGLE) {
        register_code16(KC_LSFT);
    }

    if (state->count == TAPPING_TOGGLE) {
        lower_locked = !lower_locked;
    }
}

void dance_fn1_reset(tap_dance_state_t *state, void *user_data) {
    if (!lower_locked) {
        layer_off(1);
    }

    if (state->count >= 2) {
        unregister_code16(KC_LSFT);
    }
}

bool rgb_matrix_indicators_user(void) {
    led_t   led           = host_keyboard_led_state();
    uint8_t highest_layer = get_highest_layer(layer_state);

    // Left extra upper key: OS indicator ([0, 6])
    set_indicator_key_color(0, 6, 0, 0, 0);
    // Left extra lower key: Layer indicator ([1, 6])
    set_indicator_key_color(1, 6, 0, 0, 0);
    // Right extra lower key: Num Lock indicator ([5, 6])
    set_indicator_key_color(5, 6, 0, 0, 0);

    if (led.num_lock) {
        set_indicator_key_color(5, 6, 255, 180, 0);
    }

    switch (config.os_mode) {
        case K1_WINDOWS:
            set_indicator_key_color(0, 6, 0, 120, 255);
            break;
        case K1_MACOS:
            set_indicator_key_color(0, 6, 255, 255, 255);
            break;
        case K1_LINUX:
            set_indicator_key_color(0, 6, 255, 80, 0);
            break;
        case K1_ANDROID:
            set_indicator_key_color(0, 6, 0, 220, 80);
            break;
    }

    switch (highest_layer) {
        case _LOWER:
            set_indicator_key_color(1, 6, 255, 96, 96);
            break;
        case _RAISE:
            set_indicator_key_color(1, 6, 96, 144, 255);
            break;
        case _ADJUST:
            set_indicator_key_color(1, 6, 192, 128, 255);
            break;
        default:
            set_indicator_key_color(1, 6, 0, 0, 0);
            break;
    }

    return false;
}
