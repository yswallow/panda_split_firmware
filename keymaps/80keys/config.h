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

#pragma once

// place overrides here
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

#undef MATRIX_ROWS
#define MATRIX_ROWS 8
#undef MATRIX_SLAVE_ADDRESS
#define MATRIX_SLAVE_ADDRESS { 0x40, 0x42, 0x44, 0x46, 0x48, 0x4A, 0x4C, 0x4E }

/* Mousekey config */
#define MOUSEKEY_DELAY             100
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         10
#define MOUSEKEY_TIME_TO_MAX       10
#define MOUSEKEY_WHEEL_MAX_SPEED   6
#define MOUSEKEY_WHEEL_TIME_TO_MAX 30

#define IS_COMMAND() (get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))
#define MAGIC_KEY_EEPROM F
#define MAGIC_KEY_SWITCH_LAYER_WITH_NKEYS false
#define MAGIC_KEY_SWITCH_LAYER_WITH_CUSTOM true
#define MAGIC_KEY_LAYER0 E
#define MAGIC_KEY_LAYER1 Q
#define MAGIC_KEY_LAYER2 J
#define MAGIC_KEY_LAYER3 N
#define MAGIC_KEY_LAYER0_ALT1 DELETE

#define LAYOUT80( \
            L01, L02, L03, L04, L05,    R01, R02, R03, R04, R05,    A01, A02, A03, A04, A05,    B01, B02, B03, B04, B05, \
            L06, L07, L08, L09, L10,    R06, R07, R08, R09, R10,    A06, A07, A08, A09, A10,    B06, B07, B08, B09, B10, \
            L11, L12, L13, L14, L15,    R11, R12, R13, R14, R15,    A11, A12, A13, A14, A15,    B11, B12, B13, B14, B15, \
            L16, L17, L18, L19, L20,    R16, R17, R18, R19, R20,    A16, A17, A18, A19, A20,    B16, B17, B18, B19, B20  \
) \
{ \
            {   L03, L04, L05, L02, L01, KC_NO, KC_NO, KC_NO,      L11, L12, L13, L14, L15, KC_NO, KC_NO, KC_NO }, \
            {   L10, L09, L08, L07, L06, KC_NO, KC_NO, KC_NO,      L16, L17, L18, L19, L20, KC_NO, KC_NO, KC_NO }, \
            {   R03, R04, R05, R02, R01, KC_NO, KC_NO, KC_NO,      R11, R12, R13, R14, R15, KC_NO, KC_NO, KC_NO }, \
            {   R10, R09, R08, R07, R06, KC_NO, KC_NO, KC_NO,      R16, R17, R18, R19, R20, KC_NO, KC_NO, KC_NO }, \
            {   A03, A04, A05, A02, A01, KC_NO, KC_NO, KC_NO,      A11, A12, A13, A14, A15, KC_NO, KC_NO, KC_NO }, \
            {   A10, A09, A08, A07, A06, KC_NO, KC_NO, KC_NO,      A16, A17, A18, A19, A20, KC_NO, KC_NO, KC_NO }, \
            {   B03, B04, B05, B02, B01, KC_NO, KC_NO, KC_NO,      B11, B12, B13, B14, B15, KC_NO, KC_NO, KC_NO }, \
            {   B10, B09, B08, B07, B06, KC_NO, KC_NO, KC_NO,      B16, B17, B18, B19, B20, KC_NO, KC_NO, KC_NO }, \
}

#define LAYOUT( \
           kc01, kc02, kc03, kc04, kc05,    kc06, kc07, kc08, kc09, kc10, \
           kc11, kc12, kc13, kc14, kc15,    kc16, kc17, kc18, kc19, kc20, \
           kc21, kc22, kc23, kc24, kc25,    kc26, kc27, kc28, kc29, kc30, \
           kc31, kc32, kc33, kc34, kc35,    kc36, kc37, kc38, kc39, kc40 \
) \
{ \
        {   kc03, kc04, kc05, kc02, kc01, KC_NO, KC_NO, KC_NO,      kc21, kc22, kc23, kc24, kc25, KC_NO, KC_NO, KC_NO }, \
        {   kc15, kc14, kc13, kc12, kc11, KC_NO, KC_NO, KC_NO,      kc31, kc32, kc33, kc34, kc35, KC_NO, KC_NO, KC_NO }, \
        {   kc08, kc09, kc10, kc07, kc06, KC_NO, KC_NO, KC_NO,      kc26, kc27, kc28, kc29, kc30, KC_NO, KC_NO, KC_NO }, \
        {   kc20, kc19, kc18, kc17, kc16, KC_NO, KC_NO, KC_NO,      kc36, kc37, kc38, kc39, kc40, KC_NO, KC_NO, KC_NO }, \
        {   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO }, \
        {   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO }, \
        {   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO }, \
        {   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO }  \
}
