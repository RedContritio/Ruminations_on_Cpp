#include <iostream>
#include <cstdlib>
using std::cout ;
#include "Handle.h"

Handle x[50];

int main()
{
	for(int i=0 ;i<3 ;i++ )DebugOutput(x+i );puts("");
	x[0] =Point(2 ,5 );
	for(int i=0 ;i<3 ;i++ )DebugOutput(x+i );puts("");
	x[1] =x[0] ;
	for(int i=0 ;i<3 ;i++ )DebugOutput(x+i );puts("");
	x[2] =x[0] ;
	for(int i=0 ;i<3 ;i++ )DebugOutput(x+i );puts("");
	x[1] =Point(3 ,4 );
	for(int i=0 ;i<3 ;i++ )DebugOutput(x+i );puts("");
	system("pause" );
	return 0 ;
}
