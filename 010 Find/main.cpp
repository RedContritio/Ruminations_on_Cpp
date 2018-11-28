#include <cstdio>
#include <cstdlib>
#include "Find.h"

int arrA[6+1] ={0 ,1 ,3 ,2 ,4 ,5 ,-1};
int arrB[6+1] ={0 ,1 ,3 ,3 ,4 ,5 ,-1 };

int main()
{
	const int *p1 ,*p2 ;
#ifdef __E__TYPE // Find by End
	p1 =find(arrA ,arrA+6 ,2 );
	p2 =find(arrB ,arrB+6 ,2 );
#else
	p1 =find(arrA ,6 ,2 );
	p2 =find(arrB ,6 ,2 );
#endif
	printf("%p ->%d \n%p ->%d\n",p1 ,p1?*p1:0 ,p2 ,p2?*p2:0 );
	system("pause" );
	return 0 ;
}