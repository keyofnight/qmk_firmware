// Omega, a keymap for the Alpha
// written by /u/keyofnight. 
//
// This keymap takes inspiration from Pain27's default layout but includes
// a few of my own tweaks: QWERASDF as a nav cluster (complete with
// home/end and pgup/pgdn), a complete set of symbols, and mouse emulation.
// This should make this board usable for most people and in most
// environments. 
//
// Don't worry about the license. It's a keymap, so I don't care at all about 
// who uses it and for what. Keeb it up!
//

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYM    1
#define _NAV    2
#define _FN     3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYM,
    NAV,
    FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, \
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
		SFT_T(KC_Z), CTL_T(KC_X), ALT_T(KC_C), LT(_NAV, KC_V), LT(_SYM, KC_SPC), ALT_T(KC_B), CTL_T(KC_N), SFT_T(KC_M)),

	[_SYM] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV, KC_MINS, KC_EQL, KC_BSLS, KC_BSPC, \
		KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_LBRC, KC_RBRC, KC_QUOT, KC_ENT, \
		KC_LSFT, KC_LCTL, KC_LALT, MO(_FN), KC_NO, KC_COMM, KC_DOT, KC_SLSH),

	[_NAV] = LAYOUT(
		KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_ESC, KC_NO, KC_WH_U, KC_NO,   KC_MS_U, KC_NO, \
		KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_TAB, KC_NO, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, \
		KC_LSFT, KC_LCTL, KC_LALT,  KC_NO, MO(_FN), KC_BTN1, KC_BTN2, KC_BTN3),

	[_FN] = LAYOUT(
		KC_F12, KC_F11, KC_F10, KC_F9, KC_F8, KC_F7, KC_NO, KC_NO, KC_NO, RESET, \
		KC_F1,  KC_F2,  KC_F3,  KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, \
		KC_LSFT, KC_LCTL, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
};

void  led_set_keymap (uint8_t usb_led) {
    if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}
