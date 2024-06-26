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
    void push_button();

protected:
    ModelListener* modelListener;
};
extern char rx_data[256];

#endif // MODEL_HPP
