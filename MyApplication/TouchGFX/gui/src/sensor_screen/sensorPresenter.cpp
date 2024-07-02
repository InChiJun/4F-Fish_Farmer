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
		char change_data[10];
		int i =0;
		while(rx_data[i] != '\r')
		{
			change_data[i] = rx_data[i+2];
			i++;
		}

		view.s1_update_text(change_data, i);
	}
	else if(strncmp(rx_data,"S2",2)==0){
		char change_data[10];
		int i =0;
		while(rx_data[i] != '\r')
		{
			change_data[i] = rx_data[i+2];
			i++;
		}
			view.s2_update_text(change_data, i);
	}
	else if(strncmp(rx_data,"S3",2)==0){
		char change_data[10];
		int i =0;
		while(rx_data[i] != '\r')
		{
			change_data[i] = rx_data[i+2];
			i++;
		}
			view.s3_update_text(change_data, i);
		}
	else if(strncmp(rx_data,"S4",2)==0){
		char change_data[10];
		int i =0;
		while(rx_data[i] != '\r')
		{
			change_data[i] = rx_data[i+2];
			i++;
		}
			view.s4_update_text(change_data, i);
		}
	else if(strncmp(rx_data,"S5",2)==0){
		char change_data[10];
		int i =0;
		while(rx_data[i] != '\r')
		{
			change_data[i] = rx_data[i+2];
			i++;
		}
			view.s5_update_text(change_data, i);
		}
}
