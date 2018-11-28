#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Picture.h"
#include "PictureEntity.h"
#include <iostream>
using std::cout ;

const char* pic[] ={"Glad" ,"to be here" ,"and so on" };

int main()
{
	Picture x(pic ,3 );
	Picture y =frame(x ) ;
	Picture z =frame(x |y );
	y.Reframe('*' ,'_' ,'8' );
	cout <<(z &y );
	system("pause" );
	return 0 ;
}