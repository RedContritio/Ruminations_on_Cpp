#include "VehicleSurrogate.h"
#include <cstdio>
VehicleSurrogate::VehicleSurrogate(void ):vp(NULL ){}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v ):vp(v.copy()){}

VehicleSurrogate::~VehicleSurrogate(void )
{
	if(vp )delete vp ;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v ):vp(v.vp ?v.vp->copy() :NULL ){}

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& v )
{
	if(this !=&v )
	{
		delete vp ;
		vp =(v.vp ?v.vp->copy() :NULL );
	}
	return *this ;
}

double VehicleSurrogate::weight(void )const 
{
	if(vp )return vp->weight() ;
	throw "vp is nullptr ,unable weight it";
}

void VehicleSurrogate::start(void )
{
	if(vp )vp->start();
	throw "vp is nullptr ,unable start it";
}