#include "nyquist.h"
#include "eeconfig.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUM 1
#define _NAV 2

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    NAV,
    NUM,
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
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
        KC_LCTL,   KC_DEL, KC_LALT, KC_LGUI, MO(_NAV),KC_SPC,  KC_QUOT,  MO(_NUM), KC_RGUI, KC_LBRC, KC_RBRC, KC_BSLS\
        ),

    [_NUM] = LAYOUT(\
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  KC_NO,  KC_P7,       KC_P8,  KC_P9,  KC_PAST,  KC_BSPC, \
        KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,     KC_NO,  KC_NO,  KC_P4,       KC_P5,  KC_P6,  KC_PPLS,  KC_PMNS, \
        RESET,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,     KC_NO,  KC_NO,  KC_P1,       KC_P2,  KC_P3,  KC_EQL,  KC_ENT, \
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,  KC_NO,  KC_NO,       KC_P0,  KC_PDOT,  KC_PSLS,  KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS\
        ),

    [_NAV] = LAYOUT(\
        KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,      KC_NO, KC_NO, KC_F9,    KC_F10,    KC_F11,   KC_F12, KC_TRNS, \
        KC_TRNS, KC_HOME, KC_UP,  KC_END,   KC_PGUP,    KC_NO, KC_NO, KC_F5,    KC_F6,    KC_F7,   KC_F8, KC_NO, \
        KC_TRNS, KC_LEFT, KC_DOWN,KC_RGHT,  KC_PGDN,    KC_NO, KC_NO, KC_F1,    KC_F2,    KC_F3,   KC_F4, KC_TRNS, \
        KC_TRNS, KC_NO,   KC_NO,  KC_NO,    KC_NO,      KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO, KC_NO, KC_RSFT, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO\
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
