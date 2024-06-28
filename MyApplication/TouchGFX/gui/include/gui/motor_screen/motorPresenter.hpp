#ifndef MOTORPRESENTER_HPP
#define MOTORPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class motorView;

class motorPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    motorPresenter(motorView& v);

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

    virtual ~motorPresenter() {}

private:
    motorPresenter();

    motorView& view;
};

#endif // MOTORPRESENTER_HPP
