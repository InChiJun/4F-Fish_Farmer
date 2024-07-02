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



void MainPresenter::tick()
{
	/*if(strncmp(rx_data,"S1",2)==0){
		char change_data[4] = {rx_data[2],rx_data[3],rx_data[4],rx_data[5]};

		view.update_text(change_data, 4);
	}*/
}

