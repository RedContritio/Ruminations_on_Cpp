#include <iostream>
#include "Handle.h"

using std::cout ;
using std::endl ;

int main()
{
	// now it is a handle likes ptr 
	Handle a(3 ,4 );
	{
		Handle b(a );
		{
			Handle c ;
			c = b ;

			b = b ;
		}
	}
	cout<<a.x()<<' '<<a.y()<<endl ;
	system("pause" );
	return 0 ;
}