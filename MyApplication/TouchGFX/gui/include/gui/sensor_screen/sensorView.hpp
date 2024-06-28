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
    void s1_update_text(const char* data, uint16_t size);
    void s2_update_text(const char* data, uint16_t size);
    void s3_update_text(const char* data, uint16_t size);
    void s4_update_text(const char* data, uint16_t size);
    void s5_update_text(const char* data, uint16_t size);
protected:
    int tickCounter;

    void handleTickEvent();
};

#endif // SENSORVIEW_HPP
