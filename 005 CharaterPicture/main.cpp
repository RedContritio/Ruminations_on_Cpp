#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Picture.h"

using std::cout ;
const char* MainPic[3] ={"Glad" ,"To see" ,"you" };
int main()
{
	Picture x(MainPic ,3 );
	Picture y(0 ) ;
	y =frame(x );
	cout <<(frame(frame(frame(x&(x|y))))|frame(x&(x|y))) ;
	system("pause" );
	return 0 ;
}