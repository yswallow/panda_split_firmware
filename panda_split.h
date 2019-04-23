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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( kc01,  kc02,  kc03,  kc04,  kc05,     kc06, kc07, kc08, kc09, kc10, \
           kc11, kc12, kc13, kc14, kc15,    kc16, kc17, kc18, kc19, kc20, \
           kc21, kc22, kc23, kc24, kc25,    kc26, kc27, kc28, kc29, kc30, \
           kc31, kc32, kc33, kc34, kc35,    kc36, kc37, kc38, kc39, kc40 \
) \
{ \
        {   kc03, kc04, kc05, kc02, kc01, KC_NO, KC_NO, KC_NO,      kc21, kc22, kc23, kc24, kc25, KC_NO, KC_NO, KC_NO }, \
        {   kc15, kc14, kc13, kc12, kc11, KC_NO, KC_NO, KC_NO,      kc31, kc32, kc33, kc34, kc35, KC_NO, KC_NO, KC_NO }, \
        {   kc08, kc09, kc10, kc07, kc06, KC_NO, KC_NO, KC_NO,      kc26, kc27, kc28, kc29, kc30, KC_NO, KC_NO, KC_NO }, \
        {   kc20, kc19, kc18, kc17, kc16, KC_NO, KC_NO, KC_NO,      kc36, kc37, kc38, kc39, kc40, KC_NO, KC_NO, KC_NO }, \
}
/*
{ \
        {   kc03, kc04, kc05, kc02, kc01, KC_NO, KC_NO, KC_NO,      kc21, kc22, kc23, kc24, kc25, KC_NO, KC_NO, KC_NO }, \
        {   kc15, kc14, kc13, kc12, kc11, KC_NO, KC_NO, KC_NO,      kc31, kc32, kc33, kc34, kc35, KC_NO, KC_NO, KC_NO }, \
        {   kc08, kc09, kc10, kc07, kc06, KC_NO, KC_NO, KC_NO,      kc26, kc27, kc28, kc29, kc30, KC_NO, KC_NO, KC_NO }, \
        {   kc20, kc19, kc18, kc17, kc16, KC_NO, KC_NO, KC_NO,      kc36, kc37, kc38, kc39, kc40, KC_NO, KC_NO, KC_NO }, \
}
*/

#define LAYOUT_kc( \
  L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
  L30, L31, L32, L33, L34,   R30, R31, R32, R33, R34 \
) \
LAYOUT( \
  KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04,   KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, \
  KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14,   KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, \
  KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24,   KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, \
  KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34,   KC_##R30, KC_##R31, KC_##R32, KC_##R33, KC_##R34 \
)
