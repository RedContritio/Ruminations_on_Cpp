#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "greaters.h"
using std::find_if ;
int arr[] ={0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12 ,13 ,14 ,15 };

int main(void )
{
	int* p =find_if(arr ,arr+16 ,greater10 );
	printf("%d\n",*p);
	system("pause" );
	return 0 ;
}