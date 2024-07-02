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
    air_btn.setAction(airButtonCallback); // air_btn 클릭 이벤트 설정
    water_btn.setAction(waterButtonCallback); // air_btn 클릭 이벤트 설정
    led_btn.setAction(ledButtonCallback); // air_btn 클릭 이벤트 설정
}

void motorView::tearDownScreen()
{
    motorViewBase::tearDownScreen();
}

void motorView::airButtonClicked(const touchgfx::AbstractButton& button)
{
    bool airOn = air_btn.getState(); // 토글 버튼 상태 가져오기
    presenter->setstate(airOn);

}
void motorView::waterButtonClicked(const touchgfx::AbstractButton& button)
{
    bool waterOn = water_btn.getState(); // 토글 버튼 상태 가져오기
    presenter->setstate(waterOn);

}
void motorView::ledButtonClicked(const touchgfx::AbstractButton& button)
{
    bool ledOn = led_btn.getState(); // 토글 버튼 상태 가져오기
    presenter->setstate(ledOn);

}

