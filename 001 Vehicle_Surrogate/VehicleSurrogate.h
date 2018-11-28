#ifndef VehicleSurrogate__INC
#define VehicleSurrogate__INC
#pragma once
#include "Vehicle.h"

class VehicleSurrogate
{
public :
	VehicleSurrogate(void );
	VehicleSurrogate(const Vehicle& );
	~VehicleSurrogate(void );
	VehicleSurrogate(const VehicleSurrogate& );
	VehicleSurrogate& operator=(const VehicleSurrogate& );
	
	double weight(void )const;
	void start(void );
private :
	Vehicle *vp ;
};

#endif