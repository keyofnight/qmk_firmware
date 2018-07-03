#include "nyquist.h"
#include "eeconfig.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// enum {
//    TD_RESET = 0
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(\
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_QUOT),\
        KC_LCTL,   KC_DEL, KC_LALT, KC_LGUI, MO(_RAISE),KC_SPC,  KC_SPC,  MO(_LOWER), KC_RGUI, KC_LBRC, KC_RBRC, KC_BSLS\
        ),

    [_LOWER] = LAYOUT(\
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,  KC_F7,  KC_F8,      KC_F9,  KC_F10, KC_F11, KC_F12, \
        KC_TRNS,  KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,     KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO, \
        RESET,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,     KC_NO,  KC_NO,  AU_OFF,     AU_ON,  KC_NO,  KC_NO,  KC_TRNS, \
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  KC_NO,  MU_OFF,     MU_ON,  KC_NO,  KC_NO, KC_TRNS, \
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, MO(_RAISE), KC_TRNS, KC_TRNS, MO(_LOWER), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS\
        ),

    [_RAISE] = LAYOUT(\
        KC_NO,  KC_NO,   KC_NO,  KC_NO,    KC_NO,      KC_NO, KC_NO, KC_P7,    KC_P8,    KC_P9,   KC_PAST, KC_BSPC, \
        KC_TRNS, KC_HOME, KC_UP,  KC_END,   KC_PGUP,    KC_NO, KC_NO, KC_P4,    KC_P5,    KC_P6,   KC_PPLS, KC_PMNS, \
        KC_TRNS, KC_LEFT, KC_DOWN,KC_RGHT,  KC_PGDN,    KC_NO, KC_NO, KC_P1,    KC_P2,    KC_P3,   KC_EQL, KC_ENT, \
        KC_TRNS,KC_NO,   KC_NO,  KC_NO,    KC_NO,      KC_NO, KC_NO, KC_NO,    KC_P0,    KC_PDOT, KC_PSLS, MT(MOD_RSFT, KC_QUOT), \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  MO(_RAISE), KC_TRNS, KC_TRNS, MO(_LOWER), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS\
        ),
};

//
// Keep NUMLOCK on, no matter what.
//

void led_set_keymap(uint8_t usb_led) {
    if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

//
// Reset tap dance. 
//
// void reset_dance (qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 3) {
//         reset_keyboard();
//         reset_tap_dance(state);
//    }
// }
//
// Tap dance list.
//

// qk_tap_dance_action_t tap_dance_actions[] = {
//     [TD_RESET] = ACTION_TAP_DANCE_FN(reset_dance)
// };
