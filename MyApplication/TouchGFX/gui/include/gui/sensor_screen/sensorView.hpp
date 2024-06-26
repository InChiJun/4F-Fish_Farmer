#ifndef SENSORVIEW_HPP
#define SENSORVIEW_HPP

#include <gui_generated/sensor_screen/sensorViewBase.hpp>
#include <gui/sensor_screen/sensorPresenter.hpp>

class sensorView : public sensorViewBase
{
public:
    sensorView();
    virtual ~sensorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void update_text(const char* data, uint16_t size);
protected:
    int tickCounter;

    void handleTickEvent();
};

#endif // SENSORVIEW_HPP
