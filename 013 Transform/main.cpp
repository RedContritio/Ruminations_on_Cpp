#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::transform ;

#include "IteratorOperator.h"

int a[100] ;
int main()
{
	for(int i=0 ;i<100 ;i++ )a[i] =(i<<4)-(i&(i<<1));
	
#if ITOP_VERSION==1
	transform(a ,a+100 ,a ,Add100 );
#elif ITOP_VERSION==2
#ifdef USE__NAMED__OBJECT
	addN Add100(100 );
	transform(a ,a+100 ,a ,Add100 );
#else 
	transform(a ,a+100 ,a ,addN(100) );
#endif
#elif ITOP_VERSION==3
	transform(a ,a+100 ,a ,add100 );
#endif

	for(int i=0 ;i<100 ;i++ )printf("%d ",a[i]);
	system("pause" );
	return 0 ;
}