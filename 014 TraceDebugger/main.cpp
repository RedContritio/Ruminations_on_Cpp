#include <cstdio>
#include <cstdlib>
#include <iostream>
using std::cout ;
#include "Tracer.h"

int main()
{
	{
		Tracer x(cout );
	}
	system("pause" );
	return 0 ;
}