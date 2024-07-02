#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "bluetoothinterface.h"

extern void send_turnoff_air(void);
extern void send_turnon_air(void);
extern void send_turnoff_water(void);
extern void send_turnon_water(void);
extern void send_turnoff_led(void);
extern void send_turnon_led(void);

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}


void Model::send_blue_wateroff()
{
	send_turnoff_water();
}
void Model::send_blue_wateron()
{
	send_turnon_water();
}
void Model::send_blue_airoff()
{
	send_turnoff_air();
}
void Model::send_blue_airon()
{
	send_turnon_air();
}
void Model::send_blue_ledoff()
{
	send_turnoff_led();
}
void Model::send_blue_ledon()
{
	send_turnon_led();
}

