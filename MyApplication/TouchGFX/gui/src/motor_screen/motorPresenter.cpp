#include <gui/motor_screen/motorView.hpp>
#include <gui/motor_screen/motorPresenter.hpp>

motorPresenter::motorPresenter(motorView& v)
    : view(v)
{

}

void motorPresenter::activate()
{

}

void motorPresenter::deactivate()
{

}

void motorPresenter::air_setstate(bool state)
{
	if(state == 1)
	{
		model->send_blue_airoff();
	}
	else
	{
		model->send_blue_airon();
	}
}

void motorPresenter::water_setstate(bool state)
{
	if(state == 1)
	{
		model->send_blue_wateroff();
	}
	else
	{
		model->send_blue_wateron();
	}
}

void motorPresenter::led_setstate(bool state)
{
	if(state == 1)
	{
		model->send_blue_ledoff();
	}
	else
	{
		model->send_blue_ledon();
	}
}


