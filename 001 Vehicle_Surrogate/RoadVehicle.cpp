#include "RoadVehicle.h"

void AutoVehicle::start(void)
{
	0 ;
}

Vehicle *AutoVehicle::copy(void)const
{
	return new AutoVehicle(*this );
}

AutoVehicle::~AutoVehicle(void)
{
	;
}
