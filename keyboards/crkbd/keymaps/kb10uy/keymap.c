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

#include "keymap.h"

#define TD_FN1 (TD(KB10UY_TD_FN1))

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_INT1,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             MO_RAI,  TD_FN1, KC_LSFT,     KC_SPC,  KC_ENT, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,                      KC_COMM,   KC_UP,  KC_DOT, KC_MINS,  KC_EQL, KC_INT3,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,                      KC_LEFT, KC_DOWN,KC_RIGHT, KC_LBRC, KC_RBRC, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             TT_ADJ,  TD_FN1, KC_LGUI,    KC_RSFT,  K1_ENG,  K1_JPN
                                        //`--------------------------'  `--------------------------'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, K1_WIMA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_CAPS, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_HOME, KC_PGUP,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_LALT, XXXXXXX,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_END, KC_PGDN,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             MO_RAI, XXXXXXX, KC_LSFT,    KC_RSFT,  K1_ENG,  K1_JPN
                                        //`--------------------------'  `--------------------------'
                                        // NOTE: Layer move from Raise to Adjust is prohibited
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, K1_OLED,                      KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, RGB_TOG,                       KC_NUM,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             TT_ADJ, XXXXXXX, XXXXXXX,    KC_PDOT,   KC_P0, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};

static const char PROGMEM logo_text[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2,
    0x00,
};

// clang-format on

tap_dance_action_t tap_dance_actions[] = {
    /* Lower layer with "Double Tap to Shift" */
    [KB10UY_TD_FN1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fn1_finished, dance_fn1_reset),
};

// Per-side States ------------------------------------------------------------

bool is_left            = false;
bool is_parent          = false;
bool lower_locked       = false;
int  lang_keys[]        = {KC_INTERNATIONAL_5, KC_INTERNATIONAL_4};
char oled_status_text[] = "[_|_|_|_] _";

// Keyboard Events ------------------------------------------------------------

void keyboard_post_init_user(void) {
    is_left   = is_keyboard_left();
    is_parent = is_keyboard_master();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // is_left not initialized yet
    return is_keyboard_left() ? OLED_ROTATION_0 : OLED_ROTATION_180;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /*
        case K1_OLED:
            if (record->event.pressed) {
                toggle_recording();
            }
            break;
        case K1_WIMA:
            if (record->event.pressed) {
                sync_statuses[KB10UY_SY_MACOS] = !sync_statuses[KB10UY_SY_MACOS];
                save_persistent();
            }
            break;
        */
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

// Tap Dance ------------------------------------------------------------------

void dance_fn1_finished(tap_dance_state_t *state, void *user_data) {
    layer_on(1);

    // Shift to Double Tap
    if (state->count >= 2 && state->count < TAPPING_TOGGLE) {
        register_code16(KC_LSFT);
    }

    /// Manual Tapping Toggle control
    if (state->count == TAPPING_TOGGLE) {
        lower_locked = !lower_locked;
    }
}

void dance_fn1_reset(tap_dance_state_t *state, void *user_data) {
    if (!lower_locked) {
        layer_off(1);
    }

    // Shift to Double Tap
    if (state->count >= 2) {
        unregister_code16(KC_LSFT);
    }
}

// OLED -----------------------------------------------------------------------

bool oled_task_user(void) {
    if (is_parent) {
        return oled_render_info();
    } else {
        return oled_render_logo();
    }
}

bool oled_render_info(void) {
    uint8_t highest_layer = get_highest_layer(layer_state);
    led_t   led           = host_keyboard_led_state();

    // TODO: Windows / macOS で表示を分ける
    oled_status_text[1] = 'W';

    // Lock LEDs
    oled_status_text[3] = led.num_lock ? 'N' : '_';
    oled_status_text[5] = led.num_lock ? 'N' : '_';
    oled_status_text[7] = led.num_lock ? 'N' : '_';

    // Layer Symbols
    switch (highest_layer) {
        case _DEFAULT:
            oled_status_text[10] = 'D';
            break;
        case _LOWER:
            oled_status_text[10] = 'L';
            break;
        case _RAISE:
            oled_status_text[10] = 'R';
            break;
        case _ADJUST:
            oled_status_text[10] = 'A';
            break;
    }

    oled_write(oled_status_text, false);
    return false;
}

bool oled_render_logo(void) {
    oled_write(logo_text, false);
    return false;
}
