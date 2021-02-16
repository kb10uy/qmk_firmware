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

#include QMK_KEYBOARD_H
#include "transport_ex.h"

#define TD_FN1 (TD(KB10UY_TD_FN1))
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

enum kb10uy_key_code {
    K1_OLED = SAFE_RANGE,
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
};

void oled_render_lock_state(void);
void oled_render_layer_state(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
void oled_render_keylog(void);
void render_bootmagic_status(bool status);
void oled_render_logo(void);
void update_lighting_layers(layer_state_t state);
void toggle_recording(void);
void dance_fn1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_fn1_reset(qk_tap_dance_state_t *state, void *user_data);

// ----------------------------------------------------------------------------

qk_tap_dance_action_t tap_dance_actions[] = {
    [KB10UY_TD_FN1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fn1_finished, dance_fn1_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
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

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,                      XXXXXXX,   KC_UP, XXXXXXX, KC_MINS,  KC_EQL, KC_INT3,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,                      KC_LEFT, KC_DOWN,KC_RIGHT, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(3),  TD_FN1, KC_LGUI,    KC_RSFT,  K1_ENG,  K1_JPN
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS, KC_HOME, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LALT, XXXXXXX,  KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,  KC_END, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(2),   MO(3), KC_LSFT,    KC_RSFT, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, K1_OLED,                      KC_PSLS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, RGB_TOG,                      KC_NLCK,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(3),   MO(3), XXXXXXX,    KC_PDOT,   KC_P0, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

const rgblight_segment_t PROGMEM rgb_fixed_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_ORANGE },
    { 6, 1, HSV_ORANGE },
    { 12, 1, HSV_ORANGE },
    { 18, 1, HSV_BLUE },
    { 19, 1, HSV_RED }
);

const rgblight_segment_t PROGMEM rgb_default_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_ORANGE },
    { 6, 1, HSV_ORANGE },
    { 12, 1, HSV_ORANGE }
);

const rgblight_segment_t PROGMEM rgb_lower_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
    { 1, 5, HSV_GREEN },
    { 9, 3, HSV_BLUE },
    { 15, 3, HSV_BLUE }
);

const rgblight_segment_t PROGMEM rgb_raise_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
    { 7, 1, HSV_ORANGE },
    { 9, 3, HSV_BLUE },
    { 13, 1, HSV_ORANGE },
    { 15, 3, HSV_BLUE }
);

const rgblight_segment_t PROGMEM rgb_adjust_layer_left[] = RGBLIGHT_LAYER_SEGMENTS(
    { 7, 4, HSV_PURPLE },
    { 11, 1, HSV_RED },
    { 13, 4, HSV_PURPLE },
    { 17, 1, HSV_PINK }
);

const rgblight_segment_t* const PROGMEM rgb_layers_left[] = RGBLIGHT_LAYERS_LIST(
    rgb_fixed_layer_left,
    rgb_default_layer_left,
    rgb_lower_layer_left,
    rgb_raise_layer_left,
    rgb_adjust_layer_left
);

const rgblight_segment_t PROGMEM rgb_fixed_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
    RGBLIGHT_END_SEGMENTS
);

const rgblight_segment_t PROGMEM rgb_default_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_ORANGE }
);

const rgblight_segment_t PROGMEM rgb_lower_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_ORANGE },
    { 1, 5, HSV_GREEN },
    { 10, 1, HSV_CYAN },
    { 15, 3, HSV_CYAN }
);

const rgblight_segment_t PROGMEM rgb_raise_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_ORANGE },
    { 6, 1, HSV_GOLDENROD },
    { 7, 1, HSV_GOLD },
    { 8, 1, HSV_YELLOW },
    { 12, 1, HSV_GOLDENROD },
    { 13, 1, HSV_GOLD },
    { 14, 1, HSV_YELLOW }
);

const rgblight_segment_t PROGMEM rgb_adjust_layer_right[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 1, HSV_ORANGE },
    { 2, 3, HSV_GREEN },
    { 8, 3, HSV_GREEN },
    { 14, 3, HSV_GREEN },
    { 17, 1, HSV_CHARTREUSE },
    { 19, 2, HSV_GREEN }
);

const rgblight_segment_t* const PROGMEM rgb_layers_right[] = RGBLIGHT_LAYERS_LIST(
    rgb_fixed_layer_right,
    rgb_default_layer_right,
    rgb_lower_layer_right,
    rgb_raise_layer_right,
    rgb_adjust_layer_right
);

bool sync_statuses[4] = {
    [KB10UY_SY_NUMLOCK] = false,
    [KB10UY_SY_CAPSLOCK] = false,
    [KB10UY_SY_SCROLLLOCK] = false,
    [KB10UY_SY_RECORDING] = true,
};

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// Common user actions --------------------------------------------------------

void keyboard_post_init_user(void) {
    rgblight_layers = (is_master) ? rgb_layers_left : rgb_layers_right;
    update_lighting_layers(layer_state);
}

// Called before data sync
void matrix_scan_user(void) {
    uint8_t sync = 0;
    sync |= sync_statuses[KB10UY_SY_NUMLOCK] << KB10UY_SY_NUMLOCK;
    sync |= sync_statuses[KB10UY_SY_CAPSLOCK] << KB10UY_SY_CAPSLOCK;
    sync |= sync_statuses[KB10UY_SY_SCROLLLOCK] << KB10UY_SY_SCROLLLOCK;
    sync |= sync_statuses[KB10UY_SY_RECORDING] << KB10UY_SY_RECORDING;
    transport_set_sync(sync);
}

// Called after data sync
void matrix_slave_scan_user(void) {
    uint8_t sync = transport_get_sync();
    sync_statuses[KB10UY_SY_NUMLOCK] = sync & (1 << KB10UY_SY_NUMLOCK);
    sync_statuses[KB10UY_SY_CAPSLOCK] = sync & (1 << KB10UY_SY_CAPSLOCK);
    sync_statuses[KB10UY_SY_SCROLLLOCK] = sync & (1 << KB10UY_SY_SCROLLLOCK);
    sync_statuses[KB10UY_SY_RECORDING] = sync & (1 << KB10UY_SY_RECORDING);

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
            return false;
        case K1_ENG:
            if (record->event.pressed) {
                register_code(KC_INT5);
                register_code(KC_LANG2);
            } else {
                unregister_code(KC_INT5);
                unregister_code(KC_LANG2);
            }
            return false;
        case K1_JPN:
            if (record->event.pressed) {
                register_code(KC_INT4);
                register_code(KC_LANG1);
            } else {
                unregister_code(KC_INT4);
                unregister_code(KC_LANG1);
            }
            return false;
        default:
            return true;
    }
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
        oled_render_lock_state();
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

// OLED user actions ----------------------------------------------------------

void oled_render_lock_state(void) {
    oled_write_char('[', false);
    oled_write_char(sync_statuses[KB10UY_SY_NUMLOCK] ? 'N' : ' ', false);
    oled_write_char(sync_statuses[KB10UY_SY_CAPSLOCK] ? 'C' : ' ', false);
    oled_write_char(sync_statuses[KB10UY_SY_SCROLLLOCK] ? 'S' : ' ', false);
    oled_write_char(']', false);
}

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR(" Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR(" Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR(" Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR(" Adjust"), false);
            break;
    }
}

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

// User-defined functions -----------------------------------------------------

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

    if (state->count >= 2) {
        register_code16(KC_LSFT);
    }
}

void dance_fn1_reset(qk_tap_dance_state_t *state, void *user_data) {
    layer_off(1);

    if (state->count >= 2) {
        unregister_code16(KC_LSFT);
    }
}
