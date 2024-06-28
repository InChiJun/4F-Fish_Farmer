#ifndef CONFIGVIEW_HPP
#define CONFIGVIEW_HPP

#include <gui_generated/config_screen/configViewBase.hpp>
#include <gui/config_screen/configPresenter.hpp>

class configView : public configViewBase
{
public:
    configView();
    virtual ~configView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGVIEW_HPP
