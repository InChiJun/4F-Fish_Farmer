#ifndef BLUETOOTHINTERFACE_H
#define BLUETOOTHINTERFACE_H

#include "stm32f7xx_hal.h"
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    UART_HandleTypeDef* huart;
    uint8_t rx_buffer[256];
    uint16_t rx_index;
    uint8_t tx_complete;
    void (*bluetooth_rx_callback)(uint8_t* data, uint16_t size);
    void (*bluetooth_tx_callback)(void);
} Bluetooth;

extern Bluetooth bt;
extern char bt_data[8];


void Bluetooth_init(Bluetooth* bt, UART_HandleTypeDef* huart, void (*rx_callback)(uint8_t* data, uint16_t size), void (*tx_callback)(void));
void Bluetooth_write_data(Bluetooth* bt, uint8_t* data, uint16_t size);
void Bluetooth_handle_rx_interrupt(Bluetooth* bt);
void Bluetooth_start_receive(Bluetooth* bt);

#ifdef __cplusplus
}
#endif

#endif // BLUETOOTHINTERFACE_H
