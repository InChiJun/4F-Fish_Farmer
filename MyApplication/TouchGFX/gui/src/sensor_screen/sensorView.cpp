#include <gui/sensor_screen/sensorView.hpp>
uint32_t red = (255 << 24) | (255 << 16) | (0 << 8) | 0;
uint32_t blue = (255 << 24) | (0 << 16) | (0 << 8) | 255;
uint32_t black = (255 << 24) | (0 << 16) | (0 << 8) | 0;

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

void sensorView::s1_set_color(const char* data)
{
	if(data[0]== '1' )
	{
		text_temperature.setColor(red);
	}
	else if(data[0]=='2')
	{
		text_temperature.setColor(blue);
	}
	else text_temperature.setColor(black);
	text_temperature.invalidate();
}

void sensorView::s2_set_color(const char* data)
{
	if(data[0]== '1' )
	{
		text_humidity.setColor(red);
	}
	else if(data[0]=='2')
	{
		text_humidity.setColor(blue);
	}
	else text_humidity.setColor(black);
	text_humidity.invalidate();
}

void sensorView::s3_set_color(const char* data)
{
	if(data[0]== '1' )
	{
		text_ph.setColor(red);
	}
	else if(data[0]=='2')
	{
		text_ph.setColor(blue);
	}
	else text_ph.setColor(black);
	text_ph.invalidate();
}

void sensorView::s5_set_color(const char* data)
{
	if(data[0]== '1' )
	{
		text_level.setColor(red);
	}
	else if(data[0]=='2')
	{
		text_level.setColor(blue);
	}
	else text_level.setColor(black);
	text_level.invalidate();
}
