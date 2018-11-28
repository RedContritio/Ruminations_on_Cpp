#ifndef TRACER__INC
#define TRACER__INC
#pragma once
#include <fstream>
using std::ostream ;

class Tracer
{
public :
	Tracer(ostream& o );
	~Tracer(void );
	bool Toggle(void );
private :
	ostream& os ;
	bool os_allowed ;
};

#endif