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
    Unicode::strncpy(text_temperatureBuffer, data, size);
    text_temperatureBuffer[size-2]= '\0';
    text_temperature.invalidate(); // 화면 갱신
}

void sensorView::s2_update_text(const char* data, uint16_t size)
{
    Unicode::strncpy(text_humidityBuffer, data, size);
    text_humidityBuffer[size-2]= '\0';
    text_humidity.invalidate(); // 화면 갱신
}

void sensorView::s3_update_text(const char* data, uint16_t size)
{
    Unicode::strncpy(text_phBuffer, data, size);
    text_phBuffer[size-2]= '\0';
    text_ph.invalidate(); // 화면 갱신
}

void sensorView::s4_update_text(const char* data, uint16_t size)
{
    Unicode::strncpy(text_tdsBuffer, data, size);
    text_tdsBuffer[size-2]= '\0';
    text_tds.invalidate(); // 화면 갱신
}

void sensorView::s5_update_text(const char* data, uint16_t size)
{
    Unicode::strncpy(text_levelBuffer, data, size);
    text_levelBuffer[size-2]= '\0';
    text_level.invalidate(); // 화면 갱신
}
