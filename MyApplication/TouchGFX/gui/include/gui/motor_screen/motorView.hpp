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
    void airButtonClicked(const touchgfx::AbstractButton& button);
    void waterButtonClicked(const touchgfx::AbstractButton& button);
    void ledButtonClicked(const touchgfx::AbstractButton& button);

private:
    touchgfx::Callback<motorView, const touchgfx::AbstractButton&> airButtonCallback;
    touchgfx::Callback<motorView, const touchgfx::AbstractButton&> waterButtonCallback;
    touchgfx::Callback<motorView, const touchgfx::AbstractButton&> ledButtonCallback;
};

#endif // MOTORVIEW_HPP
