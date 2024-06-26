#include <gui/sensor_screen/sensorView.hpp>

sensorView::sensorView()
{
	tickCounter = 0;
}

void sensorView::setupScreen()
{
    sensorViewBase::setupScreen();
}

void sensorView::handleTickEvent()
{
    tickCounter++;
    presenter->tick();
}
void sensorView::tearDownScreen()
{
    sensorViewBase::tearDownScreen();
}

void sensorView::update_text(const char* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data1[2];
	Unicode::UnicodeChar ch_data2[2];
	ch_data1[0]= (uint16_t)data[0];
	ch_data1[1]= (uint16_t)data[1];
	ch_data2[0]= (uint16_t)data[2];
	ch_data2[1]= (uint16_t)data[3];
    Unicode::strncpy(text_temperatureBuffer1, ch_data1, 3);
    Unicode::strncpy(text_temperatureBuffer2, ch_data2, 3);
    text_temperatureBuffer1[2]= '\0';
    text_temperatureBuffer2[2]= '\0';
    text_temperature.invalidate(); // 화면 갱신
}
