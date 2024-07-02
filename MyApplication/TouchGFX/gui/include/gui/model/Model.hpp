#ifndef MODEL_HPP
#define MODEL_HPP

#include <stdint.h>
#include "main.h"
class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void clicked_button_air();
    void clicked_button_water();
    void clicked_button_led();
    void send_blue_airoff();
    void send_blue_airon();
    void send_blue_wateroff();
    void send_blue_wateron();
    void send_blue_ledoff();
    void send_blue_ledon();
protected:
    ModelListener* modelListener;
};
extern char rx_data[256];

#endif // MODEL_HPP
