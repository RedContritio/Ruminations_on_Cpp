#include <cstdio>
#include <cstdlib>
#include "Array.h"

int main()
{
	{
	Array<int> x(10 );
	scanf_s("%d",&x[0] );
	x[1] =3 ;
	x[2] =x[0] +x[1] ;
	printf("%d\n",x[2] );
	}
	printf("test" );
	return 0 ;
}