#include <gui/motor_screen/motorView.hpp>

// 필요에 따라 시리얼 통신 라이브러리 포함
// #include <some_serial_library.h>

motorView::motorView()
{
	//air_btn.Callback(this, &motorView::airButtonClicked);
	//water_btn.Callback(this, &motorView::waterButtonClicked);
	//led_btn.Callback(this, &motorView::ledButtonClicked);

}

void motorView::setupScreen()
{
    motorViewBase::setupScreen();

}

void motorView::tearDownScreen()
{
    motorViewBase::tearDownScreen();
}

void motorView::air_button_click()
{
    bool airOn = air_button.getState(); // 토글 버튼 상태 가져오기
    presenter->air_setstate(airOn);
}

void motorView::water_button_click()
{
    bool waterOn = water_button.getState(); // 토글 버튼 상태 가져오기
    presenter->water_setstate(waterOn);
}

void motorView::led_button_click()
{
    bool ledOn = led_button.getState(); // 토글 버튼 상태 가져오기
    presenter->led_setstate(ledOn);
}
