#include "i2c_master.c"
#include "matrix.h"
#include <print.h>

uint8_t slave_address[MATRIX_ROWS] = MATRIX_SLAVE_ADDRESS;
uint8_t buffer[3] = {0x00, 0x00, 0x00};
uint8_t available_address[MATRIX_ROWS];

/* matrix state(1:on, 0:off) */
matrix_row_t matrix[MATRIX_ROWS];
matrix_row_t matrix_debouncing[MATRIX_ROWS];

#define DEBOUNCE 5
uint8_t debouncing = DEBOUNCE;

void matrix_init(void) {
    i2c_init();
    for(short i=0; i<MATRIX_ROWS; i++) {
        if( 0 == i2c_start(slave_address[i], MATRIX_INIT_TIMEOUT) ) {
            available_address[i] = slave_address[i];
            
            buffer[0] = 0x0C;
            buffer[1] = 0xFF;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x0D;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x02;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            buffer[0] = 0x03;
            i2c_transmit(slave_address[i], buffer, 2, MATRIX_INIT_TIMEOUT);
            
            i2c_stop();
        } else {
            available_address[i] = 0x00;
        }
    }
}

uint8_t matrix_scan(void) {
    for(uint8_t i=0; i<MATRIX_ROWS; i++) {
        if(available_address[i]) {
            i2c_status_t result = 0;
            wait_us(30);
            //matrix_row_t cols = read_cols(i);
            buffer[0] = 0x12;
            result |= i2c_start(slave_address[i], MATRIX_SCAN_TIMEOUT);
            result |= i2c_transmit(slave_address[i], buffer, 1, MATRIX_SCAN_TIMEOUT); 
            result |= i2c_receive(slave_address[i], buffer, 2, MATRIX_SCAN_TIMEOUT);
            if(result) {
                buffer[0] = buffer[1] = 0x00;
            }

            matrix_row_t cols =  buffer[1] << 8 | buffer[0];
            //end read_cols(i)

            if(matrix_debouncing[i] != cols) {
                matrix_debouncing[i] = cols;
                debouncing = DEBOUNCE;
            }

            //matrix[i] = buffer[1] << 8 | buffer[0];
        } else {
            //matrix[i] = 0x0000;
            matrix_debouncing[i] = 0x0000;
        }

    }

    if(debouncing) {
        if(--debouncing) {
            wait_ms(1);
        } else {
            for(uint8_t i=0; i<MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
    return 1;
}

matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void)
{

}
