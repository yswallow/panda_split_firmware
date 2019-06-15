/* Copyright 2019 %YOUR_NAME%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define _EUCALYN 0
#define _QWERTY 1
#define _EUCALYN_J 2
#define _QWERTY_J 3
//#define _TRANS 4
#define _LOWER 8
#define _RAISE 9
#define _LOWER_J 10
#define _RAISE_J 11
#define _ARROW 12
#define _MOUSE 13
#define _ADJUST 16

#define KC_____ KC_TRNS
#define KC_RESET RESET
#define KC_B_BK LALT(KC_LEFT) //ブラウザバック
#define KC_ADJUST MO(_ADJUST)
#define KC_S_ADJ  LT(_ADJUST, KC_SPC)
#define ____ KC_TRNS
#define KC_MOUSE MO(_MOUSE)
#define KC_ARROW MO(_ARROW)
#define KC_DF TO(_TRANS)
#define KC_CTL_L LM(_TRANS, KC_LCTL)
#define KC_REDO LCTL(KC_Z)
#define KC_FDEL S(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_EUCALYN] = LAYOUT_WITH_CHEESE( \
        LALT_T(KC_Q), KC_MINUS, KC_COMM, KC_DOT, KC_W,      KC_M, KC_Y, KC_K, KC_R, RALT_T(KC_P),       
        LCTL_T(KC_A), KC_O, KC_E, KC_I, KC_U,               KC_N, KC_H, KC_J, KC_L, RCTL_T(KC_G),       
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_F,               KC_S, KC_T, KC_D, KC_B, RSFT_T(KC_Q),          
        LCTL_T(KC_ESC),KC_LGUI, LT(_ARROW, KC_F10), LT(_ARROW, KC_TAB), LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT), KC_BSPACE, LCTL(KC_SPC), KC_APP, KC_RGUI,
        \
        KC_P7, KC_P8, KC_P9, KC_NLCK, KC_DELETE,
        KC_P4, KC_P5, KC_P6, KC_TAB, KC_BSPACE,
        KC_P1, KC_P2, KC_P3, KC_LSFT, LCTL(KC_W),
        KC_P0, KC_PDOT, KC_ENT, KC_ESC, KC_LCTL,
        \
        KC_DELETE, KC_BSPACE,
        KC_RALT, KC_ENT,
        KC_RCTL,
        KC_UP, KC_RSFT,
        KC_LEFT, KC_DOWN, KC_RIGHT,
        \
        KC_BSPACE,
        KC_LALT, KC_DELETE,
        KC_ENT,
        KC_UP,
        KC_LEFT, KC_DOWN, KC_RIGHT
        \
),

[_QWERTY] = LAYOUT( \
          LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
          LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_MINUS),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), ____, LT(_ARROW, KC_F10), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT), KC_BSPACE, ____, ____, ____
),

[_EUCALYN_J] = LAYOUT( \
          LALT_T(KC_Q), KC_MINUS, KC_COMM, KC_DOT, KC_W,       KC_M, KC_Y, KC_K, KC_R, RALT_T(KC_P),
          LCTL_T(KC_A), KC_O, KC_E, KC_I, KC_U,       KC_N, KC_H, KC_J, KC_L, RCTL_T(KC_G),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_F,       KC_S, KC_T, KC_D, KC_B, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), ____, LT(_ARROW, KC_F10), LT(_LOWER_J, KC_TAB), LT(_LOWER_J, KC_SPC),    LT(_RAISE_J, KC_ENT), KC_BSPACE, JP_ZHTG, ____, ____
),

[_QWERTY_J] = LAYOUT( \
          LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
          LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_MINUS),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), ____, LT(_ARROW, KC_F10), LT(_LOWER_J, KC_TAB), LT(_LOWER_J, KC_SPC),    LT(_RAISE_J, KC_ENT), KC_BSPACE, JP_ZHTG, ____, ____
),

[_LOWER] = LAYOUT_kc( \
            EXLM, AT,   HASH, DLR,  PERC,    CIRC, AMPR, ASTR, LPRN, RPRN,
            1,    2,    3,    4,    5,       6,    7,    8,    9,    0,
            MOUSE,REDO, ____, ____, ____,    ____, ____, ____, ____, ____,
            ____, ____, ____, ____, ____,    ADJUST, DELETE, FDEL, ____, ____
),

[_RAISE] = LAYOUT_kc( \
            LALT, UNDS, LABK, RABK, LCBR,    RCBR, COLN, DQUO, QUES, PIPE,
            LCTL, ESC,  GRV,  EQL,  LBRC,    RBRC, SCLN, QUOT, SLSH, BSLS,
            LSFT, ____, TILD, PLUS, ____,    ____, ____, ____, ____, ENT,
            ESC,  LGUI, ____, ____, S_ADJ,  ____, ____, ____, ____, ____
),

[_LOWER_J] = LAYOUT( \
            KC_EXLM,  JP_AT,   KC_HASH, KC_DLR,  KC_PERC,    JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN,
            KC_1,     KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
            MO(_MOUSE), ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____,    ____,
            ____,     ____,    ____,    ____,    ____,   MO(_ADJUST), KC_DELETE, ____,  ____,    ____

),

[_RAISE_J] = LAYOUT( \
            KC_LALT, JP_UNDS,  JP_TILD, JP_PLUS, JP_LCBR,    JP_RCBR, JP_COLN, JP_DQT,  JP_QUES, JP_PIPE,
            KC_LCTL, JP_YEN,  JP_GRV,  JP_EQL,  JP_LBRC,    JP_RBRC, JP_SCLN, JP_QUOT, JP_SLSH, JP_BSLS,
            KC_LSFT, ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____, ____,
            KC_ESC,  KC_LGUI, ____,  ____,   MO(_ADJUST),    ____,  ____,   ____,    ____,       ____
),

[_ARROW] = LAYOUT_kc( \
            LALT, F1,   F2,   F3,   F4,      ____, ____, UP,   ____, ____,
            LCTL, F5,   F6,   F7,   F8,      LEFT, LEFT, DOWN, RIGHT, ____,
            LSFT, F9,   F10,  F11,  F12,     HOME, PGDN, PGUP, END,  ____,
            ESC,  LGUI, ____, ____, ____,    ____, ____, ____, ____,  ____
),

[_MOUSE] = LAYOUT_kc( \
            LALT, ____, ____, ____, ____,    B_BK, WH_U, MS_U, NO,   VOLU,
            LCTL, ____, ____, ____, ____,    MS_L, MS_L, MS_D, MS_R, PSCR,
            LSFT, ____, ____, ____, ____,    MS_BTN1, WH_D, MS_BTN2, NO, VOLD,
            ESC, LGUI,  ____, ____, ____,    MS_BTN1, MS_BTN2, NO, NO, NO
),

[_ADJUST] = LAYOUT( \
            DF(_QWERTY), ____, DF(_EUCALYN), ____, ____,    QMKBEST, ____, KC_PSCR, KC_VOLU, RESET,
            ____, ____, DF(_EUCALYN), ____, ____,           ____, DF(_QWERTY_J), KC_INS, KC_VOLD, ____,
            ____, ____, ____, ____, ____,                   ____, ____, ____, ____, ____,
            ____,   ____,  ____, ____,   ____,              ____,     ____,   ____,   ____,   ____
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
    
}

void matrix_scan_user(void) {
    
}

void led_set_user(uint8_t usb_led) {
    
}
