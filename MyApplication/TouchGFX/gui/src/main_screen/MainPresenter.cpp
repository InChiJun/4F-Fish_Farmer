#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include "bluetoothinterface.h"
extern Bluetooth bt;


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

void MainPresenter::call_air()
{
	model->clicked_button_air();
}

void MainPresenter::tick()
{
	/*if(strncmp(rx_data,"S1",2)==0){
		char change_data[4] = {rx_data[2],rx_data[3],rx_data[4],rx_data[5]};

		view.update_text(change_data, 4);
	}*/
}

/*	if (bt.rx_index > 0) { // bt.rx_index는 수신된 데이터의 길이를 나타내므로 0보다 커야 유효한 데이터가 있다고 판단합니다.
	        // bt.rx_buffer 값을 MainView의 update_text 함수를 통해 업데이트
	        view.update_text(bt.rx_buffer, bt.rx_index); // bt.rx_buffer의 데이터를 view에 업데이트 요청
	    }
}
*/
