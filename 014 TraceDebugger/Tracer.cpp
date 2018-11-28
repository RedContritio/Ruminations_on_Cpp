#include "Tracer.h"

Tracer::Tracer(ostream& o ):os(o ),os_allowed(true )
{
	if(os_allowed )os <<"Trace Begin" <<std::endl ;
}


Tracer::~Tracer()
{
	if(os_allowed )os <<"Trace End" <<std::endl ;
}

bool Tracer::Toggle(void)
{
	return os_allowed=!os_allowed ;
}
