#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void update_text(const uint8_t* data, uint16_t size);
protected:
    int tickCounter;

    void handleTickEvent();
    virtual void sliderValueChanged(int value);
    virtual void send_hello();

};

#endif // MAINVIEW_HPP
