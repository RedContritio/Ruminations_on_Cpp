#ifndef ROADVEHICLE__INC
#define ROADVEHICLE__INC
#pragma once
#include "Vehicle.h"

class RoadVehicle :public Vehicle 
{
	;
};

class AutoVehicle :public RoadVehicle 
{
public :
	double weight(void )const {return 1200 ;}
	void start(void );
	Vehicle* copy(void )const;
	~AutoVehicle(void );
};

#endif
