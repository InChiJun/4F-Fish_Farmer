#include <gui/main_screen/MainView.hpp>
#include <math.h>
#include <stdlib.h>


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


