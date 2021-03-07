/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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

#include "keymap.h"

// ----------------------------------------------------------------------------

qk_tap_dance_action_t tap_dance_actions[] = {
    /* Lower layer with "Double Tap to Shift" */
    [KB10UY_TD_FN1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fn1_finished, dance_fn1_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_INT1,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2),  TD_FN1, KC_LSFT,     KC_SPC,  KC_ENT, KC_RALT
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
                                            TT(3),  TD_FN1, KC_LGUI,    KC_RSFT,  K1_ENG,  K1_JPN
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, K1_WIMA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_HOME, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, XXXXXXX,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_END, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2), XXXXXXX, KC_LSFT,    KC_RSFT,  K1_ENG,  K1_JPN
                                      //`--------------------------'  `--------------------------'
                                      // NOTE: Layer move from Raise to Adjust is prohibited
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, K1_OLED,                      KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, RGB_TOG,                      KC_NLCK,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TT(3), XXXXXXX, XXXXXXX,    KC_PDOT,   KC_P0, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

const rgblight_segment_t PROGMEM rgb_layer_definitions[] = {
    /* Left fixed */
    { 0, 1, HSV_ORANGE }, { 6, 1, HSV_ORANGE }, { 12, 1, HSV_ORANGE }, { 18, 1, HSV_BLUE }, { 19, 1, HSV_RED }, RGBLIGHT_END_SEGMENTS,

    /* Left default */
    { 0, 1, HSV_ORANGE }, { 6, 1, HSV_ORANGE }, { 12, 1, HSV_ORANGE }, RGBLIGHT_END_SEGMENTS,

    /* Left, lower */
    { 1, 5, HSV_GREEN }, { 9, 3, HSV_BLUE }, { 15, 3, HSV_BLUE }, RGBLIGHT_END_SEGMENTS,

    /* Left raise */
    { 1, 1, HSV_ORANGE }, { 7, 1, HSV_ORANGE }, { 9, 3, HSV_BLUE }, { 13, 1, HSV_ORANGE }, { 15, 3, HSV_BLUE }, RGBLIGHT_END_SEGMENTS,

    /* Left adjust */
    { 7, 4, HSV_PURPLE }, { 11, 1, HSV_RED }, { 13, 4, HSV_PURPLE }, { 17, 1, HSV_PINK }, RGBLIGHT_END_SEGMENTS,

    /* Right fixed */
    RGBLIGHT_END_SEGMENTS,

    /* Right default */
    { 0, 1, HSV_ORANGE }, RGBLIGHT_END_SEGMENTS,

    /* Right lower */
    { 0, 1, HSV_ORANGE }, { 1, 5, HSV_GREEN }, { 10, 1, HSV_CYAN }, { 15, 3, HSV_CYAN }, RGBLIGHT_END_SEGMENTS,

    /* Right raise */
    { 0, 3, HSV_ORANGE }, { 6, 1, HSV_GOLDENROD }, { 7, 1, HSV_GOLD }, { 8, 1, HSV_YELLOW }, { 12, 1, HSV_GOLDENROD }, { 13, 1, HSV_GOLD }, { 14, 1, HSV_YELLOW }, RGBLIGHT_END_SEGMENTS,

    /* Right adjust */
    { 0, 1, HSV_ORANGE }, { 2, 3, HSV_GREEN }, { 8, 3, HSV_GREEN }, { 14, 3, HSV_GREEN }, { 17, 1, HSV_CHARTREUSE }, { 19, 2, HSV_GREEN }, RGBLIGHT_END_SEGMENTS,
};

const rgblight_segment_t* const PROGMEM rgb_layers[] = {
    /* Left layers */
    &rgb_layer_definitions[0],
    &rgb_layer_definitions[6],
    &rgb_layer_definitions[10],
    &rgb_layer_definitions[14],
    &rgb_layer_definitions[20],
    NULL,

    /* Right layers */
    &rgb_layer_definitions[25],
    &rgb_layer_definitions[26],
    &rgb_layer_definitions[28],
    &rgb_layer_definitions[33],
    &rgb_layer_definitions[41],
    NULL,
};

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

bool sync_statuses[] = {
    [KB10UY_SY_NUMLOCK] = false,
    [KB10UY_SY_CAPSLOCK] = false,
    [KB10UY_SY_SCROLLLOCK] = false,
    [KB10UY_SY_RECORDING] = true,
    [KB10UY_SY_MACOS] = false,
};

bool lower_locked = false;

kb10uy_persistent_t persistent = {};

// Common user actions --------------------------------------------------------

void eeconfig_init_user(void) {
    persistent.macos_enabled = false;
    save_persistent();
}

void keyboard_post_init_user(void) {
    if (is_master) {
        rgblight_layers = &rgb_layers[0];
        load_persistent();
    } else {
        rgblight_layers = &rgb_layers[6];
    }
    update_lighting_layers(layer_state);
}

void matrix_scan_user(void) {
    uint8_t sync = 0;
    sync |= sync_statuses[KB10UY_SY_NUMLOCK] << KB10UY_SY_NUMLOCK;
    sync |= sync_statuses[KB10UY_SY_CAPSLOCK] << KB10UY_SY_CAPSLOCK;
    sync |= sync_statuses[KB10UY_SY_SCROLLLOCK] << KB10UY_SY_SCROLLLOCK;
    sync |= sync_statuses[KB10UY_SY_RECORDING] << KB10UY_SY_RECORDING;
    sync |= sync_statuses[KB10UY_SY_MACOS] << KB10UY_SY_MACOS;
    transport_set_sync(sync);
}

void matrix_slave_scan_user(void) {
    uint8_t sync = transport_get_sync();
    sync_statuses[KB10UY_SY_NUMLOCK] = sync & (1 << KB10UY_SY_NUMLOCK);
    sync_statuses[KB10UY_SY_CAPSLOCK] = sync & (1 << KB10UY_SY_CAPSLOCK);
    sync_statuses[KB10UY_SY_SCROLLLOCK] = sync & (1 << KB10UY_SY_SCROLLLOCK);
    sync_statuses[KB10UY_SY_RECORDING] = sync & (1 << KB10UY_SY_RECORDING);
    sync_statuses[KB10UY_SY_MACOS] = sync & (1 << KB10UY_SY_MACOS);

    if (is_oled_paused() == sync_statuses[KB10UY_SY_RECORDING]) {
        // Keep consistency of flags
        toggle_recording();
        toggle_recording();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (sync_statuses[KB10UY_SY_RECORDING] && record->event.pressed) {
        set_keylog(keycode, record);
    }

    switch (keycode) {
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
        case K1_ENG:
            if (record->event.pressed) {
                register_code(sync_statuses[KB10UY_SY_MACOS] ? KC_LANG2 : KC_INT5);
            } else {
                unregister_code(sync_statuses[KB10UY_SY_MACOS] ? KC_LANG2 : KC_INT5);
            }
            break;
        case K1_JPN:
            if (record->event.pressed) {
                register_code(sync_statuses[KB10UY_SY_MACOS] ? KC_LANG1 : KC_INT4);
            } else {
                unregister_code(sync_statuses[KB10UY_SY_MACOS] ? KC_LANG1 : KC_INT4);
            }
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    update_lighting_layers(state);
    return state;
}

bool led_update_user(led_t led_state) {
    sync_statuses[KB10UY_SY_NUMLOCK] = led_state.num_lock;
    sync_statuses[KB10UY_SY_CAPSLOCK] = led_state.caps_lock;
    sync_statuses[KB10UY_SY_SCROLLLOCK] = led_state.scroll_lock;
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_master();
    } else {
        oled_render_slave();
    }
}

// OLED user actions ----------------------------------------------------------

void oled_render_master(void) {
    uint8_t highest_layer = get_highest_layer(layer_state);

    oled_write_char('[', false);
    oled_write_char(sync_statuses[KB10UY_SY_NUMLOCK] ? 'N' : ' ', false);
    oled_write_char(sync_statuses[KB10UY_SY_CAPSLOCK] ? 'C' : ' ', false);
    oled_write_char(sync_statuses[KB10UY_SY_SCROLLLOCK] ? 'S' : ' ', false);
    oled_write_char(']', false);

    if (sync_statuses[KB10UY_SY_MACOS]) {
        oled_write_P(PSTR(" mac "), false);
    } else {
        oled_write_P(PSTR(" Win "), false);
    }

    switch (highest_layer) {
        case _DEFAULT:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }

    oled_write(keylog_str, false);
}

void oled_render_slave(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';

    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
             record->event.key.row, record->event.key.col,
             keycode, name);
}

// User-defined functions -----------------------------------------------------

void load_persistent(void) {
    persistent.raw = eeprom_read_dword(EECONFIG_PERSISTENT);

    sync_statuses[KB10UY_SY_MACOS] = persistent.macos_enabled;
}

void save_persistent(void) {
    persistent.macos_enabled = sync_statuses[KB10UY_SY_MACOS];

    eeprom_update_dword(EECONFIG_PERSISTENT, persistent.raw);
}

void update_lighting_layers(layer_state_t state) {
    rgblight_set_layer_state(0, true);
    rgblight_set_layer_state(1, layer_state_cmp(state, 0) && !layer_state_cmp(state, 3));
    rgblight_set_layer_state(2, layer_state_cmp(state, 1) && !layer_state_cmp(state, 3));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2) && !layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 3));
}

void toggle_recording(void) {
    if (sync_statuses[KB10UY_SY_RECORDING]) {
        oled_pause();
        sync_statuses[KB10UY_SY_RECORDING] = false;
    } else {
        oled_resume();
        sync_statuses[KB10UY_SY_RECORDING] = true;
    }
}

void dance_fn1_finished(qk_tap_dance_state_t *state, void *user_data) {
    layer_on(1);

    switch (state->count) {
        case 2:
            register_code16(KC_LSFT);
            break;
        case TAPPING_TOGGLE:
            lower_locked = !lower_locked;
            break;
    }
}

void dance_fn1_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (!lower_locked) {
        layer_off(1);
    }

    switch (state->count) {
        case 2:
            unregister_code16(KC_LSFT);
            break;
        case TAPPING_TOGGLE:
            // Nothing needed
            break;
    }
}
