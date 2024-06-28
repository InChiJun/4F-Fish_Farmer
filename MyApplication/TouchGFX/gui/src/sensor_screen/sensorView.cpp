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

void sensorView::s1_update_text(const char* data, uint16_t size)
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

void sensorView::s2_update_text(const char* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data1[2];
	Unicode::UnicodeChar ch_data2[2];
	ch_data1[0]= (uint16_t)data[0];
	ch_data1[1]= (uint16_t)data[1];
	ch_data2[0]= (uint16_t)data[2];
	ch_data2[1]= (uint16_t)data[3];
    Unicode::strncpy(text_humidityBuffer1, ch_data1, 3);
    Unicode::strncpy(text_humidityBuffer2, ch_data2, 3);
    text_humidityBuffer1[2]= '\0';
    text_humidityBuffer2[2]= '\0';
    text_humidity.invalidate(); // 화면 갱신
}

void sensorView::s3_update_text(const char* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data1[2];
	Unicode::UnicodeChar ch_data2[2];
	ch_data1[0]= (uint16_t)data[0];
	ch_data1[1]= (uint16_t)data[1];
	ch_data2[0]= (uint16_t)data[2];
	ch_data2[1]= (uint16_t)data[3];
    Unicode::strncpy(text_phBuffer1, ch_data1, 3);
    Unicode::strncpy(text_phBuffer2, ch_data2, 3);
    text_phBuffer1[2]= '\0';
    text_phBuffer2[2]= '\0';
    text_ph.invalidate(); // 화면 갱신
}

void sensorView::s4_update_text(const char* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data1[2];
	Unicode::UnicodeChar ch_data2[2];
	ch_data1[0]= (uint16_t)data[0];
	ch_data1[1]= (uint16_t)data[1];
	ch_data2[0]= (uint16_t)data[2];
	ch_data2[1]= (uint16_t)data[3];
    Unicode::strncpy(text_tdsBuffer1, ch_data1, 3);
    Unicode::strncpy(text_tdsBuffer2, ch_data2, 3);
    text_tdsBuffer1[2]= '\0';
    text_tdsBuffer2[2]= '\0';
    text_tds.invalidate(); // 화면 갱신
}

void sensorView::s5_update_text(const char* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data1[2];
	Unicode::UnicodeChar ch_data2[2];
	ch_data1[0]= (uint16_t)data[0];
	ch_data1[1]= (uint16_t)data[1];
	ch_data2[0]= (uint16_t)data[2];
	ch_data2[1]= (uint16_t)data[3];
    Unicode::strncpy(text_levelBuffer1, ch_data1, 3);
    Unicode::strncpy(text_levelBuffer2, ch_data2, 3);
    text_levelBuffer1[2]= '\0';
    text_levelBuffer2[2]= '\0';
    text_level.invalidate(); // 화면 갱신
}
