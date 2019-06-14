#include "i2c_master.h"
#include <stdbool.h>

void panda_led_init(uint8_t address, uint8_t port, uint8_t pin_number) {
    uint8_t buffer[2];
    i2c_start(address, MATRIX_INIT_TIMEOUT);
    buffer[0] = 0x00 + port; // IODIR
    
    // read
    i2c_transmit(address, buffer, 1, MATRIX_INIT_TIMEOUT);
    i2c_receive(address, buffer, 1, MATRIX_INIT_TIMEOUT);
    
    // write
    buffer[1] = buffer[0] & (~(1<<pin_number));
    buffer[0] = 0x00 + port;
    i2c_transmit(address, buffer, 2, MATRIX_INIT_TIMEOUT);
      
    /*      
    buffer[0] = 0x14 + port; // OLAT
    buffer[1] = 0x00;
    i2c_transmit(address, buffer, 2, MATRIX_INIT_TIMEOUT);
    */
    i2c_stop();
}

void panda_led_set(uint8_t address, uint8_t port, uint8_t pin_number, bool led_state) {
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
