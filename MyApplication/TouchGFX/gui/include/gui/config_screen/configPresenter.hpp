#ifndef CONFIGPRESENTER_HPP
#define CONFIGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class configView;

class configPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    configPresenter(configView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~configPresenter() {}

private:
    configPresenter();

    configView& view;
};

#endif // CONFIGPRESENTER_HPP
