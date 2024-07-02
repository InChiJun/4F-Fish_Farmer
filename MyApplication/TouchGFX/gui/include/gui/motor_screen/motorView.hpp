#ifndef MOTORVIEW_HPP
#define MOTORVIEW_HPP

#include <gui_generated/motor_screen/motorViewBase.hpp>
#include <gui/motor_screen/motorPresenter.hpp>

class motorView : public motorViewBase
{
public:
    motorView();
    virtual ~motorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void air_button_click();
    virtual void water_button_click();
    virtual void led_button_click();
protected:


private:

};

#endif // MOTORVIEW_HPP
