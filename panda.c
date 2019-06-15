#include "i2c_master.h"
#include <stdbool.h>

uint8_t panda_matrix_init(uint8_t slave_address) {
    uint8_t buffer[2] = {0x00, 0x00};
    if( 0 == i2c_start(slave_address, MATRIX_INIT_TIMEOUT) ) {
        //デフォルトで入力 (IODIR is set(1) )
            
        buffer[0] = 0x0C; //PULLUP
        buffer[1] = 0xFF;
        i2c_transmit(slave_address, buffer, 2, MATRIX_INIT_TIMEOUT);
        buffer[0] = 0x0D;
        i2c_transmit(slave_address, buffer, 2, MATRIX_INIT_TIMEOUT);
        buffer[0] = 0x02; //IPOL 論理反転
        i2c_transmit(slave_address, buffer, 2, MATRIX_INIT_TIMEOUT);
        buffer[0] = 0x03;
        i2c_transmit(slave_address, buffer, 2, MATRIX_INIT_TIMEOUT);
        
        //device_available = true;
        i2c_stop();
        return slave_address;
    } else {
        i2c_stop();
        return 0x00;
    }
}

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
