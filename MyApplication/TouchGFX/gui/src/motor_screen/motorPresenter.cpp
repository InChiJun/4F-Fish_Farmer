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

void motorPresenter::setstate(bool state)
{
	if(state == 1)
	{
		model->send_blue();
	}
	else
	{
		model->send_blue();
	}
}
