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
#include "panda_split.h"
#include "i2c_master.h"
// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

inline void panda_led_set(uint8_t address, uint8_t port, uint8_t pin_number, bool led_state) {
  uint8_t buffer[2];
  
  buffer[0] = 0x14 + port;
  i2c_start(address, MATRIX_SCAN_TIMEOUT);
  i2c_transmit(address, buffer, 1, MATRIX_SCAN_TIMEOUT);
  i2c_receive(address, buffer, 1, MATRIX_SCAN_TIMEOUT);
  if(led_state) {
    buffer[1] = buffer[0] | (1<<pin_number);
  } else {
    buffer[1] = buffer[0] & ~(1<<pin_number);
  }
  
  buffer[0] = 0x14 + port; 
  
  i2c_transmit(address, buffer, 2, MATRIX_SCAN_TIMEOUT);
  i2c_stop();
}
 
void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
  
  #ifdef PANDA_LED_ENABLE
  
  //void panda_led_set(uint8_t address, uint8_t port, uint8_t pin_number, bool led_state)
  #ifdef NUMLOCK_LED_ADDRESS
    panda_led_set( NUMLOCK_LED_ADDRESS, NUMLOCK_LED_PORT, NUMLOCK_LED_PIN_NUMBER, usb_led & (1 << USB_LED_NUM_LOCK) );
  #endif
  
  #ifdef CAPSLOCK_LED_ADDRESS
    panda_led_set( CAPSLOCK_LED_ADDRESS, CAPSLOCK_LED_PORT, CAPSLOCK_LED_PIN_NUMBER, usb_led & (1 << USB_LED_CAPS_LOCK) );
  #endif
  
  #ifdef SCROLLLOCK_LED_ADDRESS
    panda_led_set( SCROLLLOCK_LED_ADDRESS, SCROLLLOCK_LED_PORT, SCROLLLOCK_LED_PIN_NUMBER, usb_led & (1 << USB_LED_SCROLL_LOCK) );
  #endif
    
  #endif
  led_set_user(usb_led);
}

