#include <cstdio>
#include <cstdlib>
#include "Composer.h"

int f(int x ){return 2*x ;}
int g(int x ){return x+1 ;}

int main(void )
{
#if ComposerVersion ==1
	IntegarComposer a(f ,g );
	IntegarComposer b(g ,f );
#elif ComposerVersion ==2 
	Composer<int (*)(int) ,int (*)(int) ,int ,int > a(f ,g );
	Composer<int (*)(int) ,Composer<int (*)(int) ,int (*)(int) ,int ,int > ,int ,int > b(g ,a );
#elif ComposerVersion ==3 
	Composition<int,int> a(f,g) ;
	Composition<int,int> b(a,a) ;
#endif
	printf("f*g =%d ,g*f =%d\n",a(5 ),b(5 ));
	system("pause" );
	return 0 ;
}