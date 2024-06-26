#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include "bluetoothinterface.h"
extern Bluetooth bt;

uint16_t prev_bt_index = 0;
char sensor1[5];
char sensor2[5];
char sensor3[5];
char sensor4[5];
char sensor5[5];

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::con_sh_bc()
{
	model->push_button();
}

void MainPresenter::tick()
{
    uint16_t i = prev_bt_index;
    while(bt.rx_buffer[prev_bt_index]!='S')
    {
    	if(prev_bt_index>bt.rx_index){prev_bt_index = 0 ; return;}
    	prev_bt_index++;
    }
    // Ensure prev_bt_index is less than bt.rx_index
    if (prev_bt_index < bt.rx_index) {
        // Check if there are at least 8 characters available ("S1xxxx\r\n")
        if ((bt.rx_index - i) >= 8 && strncmp((char*)bt.rx_buffer + i, "S1", 2) == 0) {
            // Check for the terminating '\r\n' characters
            if (bt.rx_buffer[i + 6] == '\r' && bt.rx_buffer[i + 7] == '\n') {
                strncpy(sensor1, (char*)bt.rx_buffer + i + 2, 4);
                // Null terminate the destination string
                sensor1[4] = '\0';
                // Update prev_bt_index to point after the '\r\n' characters
                prev_bt_index = i + 8;
            }
        }
    }
}

/*	if (bt.rx_index > 0) { // bt.rx_index는 수신된 데이터의 길이를 나타내므로 0보다 커야 유효한 데이터가 있다고 판단합니다.
	        // bt.rx_buffer 값을 MainView의 update_text 함수를 통해 업데이트
	        view.update_text(bt.rx_buffer, bt.rx_index); // bt.rx_buffer의 데이터를 view에 업데이트 요청
	    }
}
*/
