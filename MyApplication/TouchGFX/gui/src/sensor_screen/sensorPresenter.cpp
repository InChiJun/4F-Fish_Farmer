#include <gui/sensor_screen/sensorView.hpp>
#include <gui/sensor_screen/sensorPresenter.hpp>
#include "string.h"
sensorPresenter::sensorPresenter(sensorView& v)
    : view(v)
{

}

void sensorPresenter::activate()
{

}

void sensorPresenter::deactivate()
{

}

void sensorPresenter::tick()
{
	if(strncmp(rx_data,"S1",2)==0){
		char change_data[4] = {rx_data[2],rx_data[3],rx_data[4],rx_data[5]};
		view.update_text(change_data, 4);
	}
}
