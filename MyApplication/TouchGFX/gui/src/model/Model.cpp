#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "bluetoothinterface.h"

extern void push_bt_button(void);

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::push_button()
{
	push_bt_button();
}


