#include <gui/main_screen/MainView.hpp>
#include <math.h>
#include <stdlib.h>

static uint16_t randomish(int32_t seed)
{
    static uint16_t last = 0;
    const uint16_t num = (seed * (1337 + last)) % 0xFFFF;
    last = num;
    return num;
}

MainView::MainView()
{
    tickCounter = 0;
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();

    // Initialize graph range with default slider value at start up
    /*sliderValueChanged(sliderResolution.getValue());*/
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::handleTickEvent()
{
    tickCounter++;
    presenter->tick();

    // Insert each second tick
    if (tickCounter % 2 == 0)
    {
        /*float yMax = graph.getGraphRangeYMaxAsFloat();*/

        // Insert "random" points along a sine wave
        /*graph.addDataPoint((int)((sinf(tickCounter * .02f) + 1) * (yMax / 2.2f)) + randomish(tickCounter) % (int)(yMax / 10.f));*/
    }
}


void MainView::update_text(const uint8_t* data, uint16_t size)
{
	Unicode::UnicodeChar ch_data[256];
	for(int i =size ; i>0; i--)
	{
		ch_data[i]= data[i];
	}

}
