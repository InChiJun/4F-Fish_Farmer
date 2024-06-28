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
protected:
};

#endif // MOTORVIEW_HPP
