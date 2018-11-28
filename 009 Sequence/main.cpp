#include <cstdio>
#include <cstdlib>
#include "Seq.hpp"

int main()
{
	Sequence<int> x(10 );
	for(int i=0 ;i<100 ;i++ )
	{
		x =cons(i ,x );
	}
	Sequence<int> p=x ;
	while(!p.Empty())
	{
		printf("%d ",p.hd());
		++p ;
	}
	printf("\n%d\n" ,SeqLength(x ));
	system("pause" );
	return 0 ;
}