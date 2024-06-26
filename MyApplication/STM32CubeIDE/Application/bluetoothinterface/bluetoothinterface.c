#include "bluetoothinterface.h"
#include "cmsis_os.h"
#include <stdlib.h> // malloc과 free를 사용하기 위한 헤더 파일

Bluetooth bt;

void Bluetooth_init(Bluetooth* bt, UART_HandleTypeDef* huart, void (*rx_callback)(uint8_t* data, uint16_t size), void (*tx_callback)(void)) {
    bt->rx_index = 0;
    bt->huart = huart;
    bt->bluetooth_rx_callback = rx_callback;
    bt->bluetooth_tx_callback = tx_callback;
    bt->tx_complete = 1; // 전송 완료 플래그 초기화

    // UART 초기화 코드
    huart->Instance = UART7;
    huart->Init.BaudRate = 9600;
    huart->Init.WordLength = UART_WORDLENGTH_8B;
    huart->Init.StopBits = UART_STOPBITS_1;
    huart->Init.Parity = UART_PARITY_NONE;
    huart->Init.Mode = UART_MODE_TX_RX;
    huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart->Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(huart) != HAL_OK) {
        // 초기화 오류 처리
        // 오류 처리 코드 추가
    }

    // UART 인터럽트 활성화
    HAL_NVIC_SetPriority(UART7_IRQn, 0, 1);
    HAL_NVIC_EnableIRQ(UART7_IRQn);

    // 첫 수신 인터럽트 시작
    //HAL_UART_Receive_IT(huart, (uint8_t *)&bt->rx_buffer[bt->rx_index], 1);
}


void Bluetooth_write_data(Bluetooth* bt, uint8_t* data, uint16_t size) {
    bt->tx_complete = 0; // 전송 완료 플래그 초기화
#if 0
    if (HAL_UART_Transmit_IT(bt->huart, data, size) != HAL_OK) {
#else
    if (HAL_UART_Transmit(bt->huart, data, size, -1) != HAL_OK) {
#endif
        // 전송 오류 처리
        	while(1){
            // 오류 처리 루프
        	}
    }

}

// 전송 완료 콜백 함수


void Bluetooth_handle_rx_interrupt(Bluetooth* bt) {
    // 버퍼 오버플로 방지
    if (bt->rx_index >= sizeof(bt->rx_buffer)) {
        bt->rx_index = 0;
    }
    bt->rx_index++;
    // 다음 수신을 위한 인터럽트 설정
    HAL_UART_Receive_IT(bt->huart, (uint8_t *)&bt->rx_buffer[bt->rx_index], 1);


    // 수신된 문자가 '\n'일 경우, 이전 문자가 '\r'인지 확인
    if (bt->rx_buffer[bt->rx_index - 1] == '\n' && bt->rx_buffer[bt->rx_index - 2] == '\r') {
        // 수신된 데이터를 콜백으로 전달
        if (bt->bluetooth_rx_callback) {
            bt->bluetooth_rx_callback(bt->rx_buffer, bt->rx_index);
        }
        bt->rx_index = 0;
    }
}

void UART7_IRQHandler(void) {
    HAL_UART_IRQHandler(bt.huart);
}





