#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Array.hpp"

int main()
{
	Array<int> arr(10 );
	arr[0] =2 ;
	arr[1] =3 ;
	for(int i=2 ;i<10 ;i++ )
		arr[i] =arr[i-1]+arr[i-2]; 
	
	for(Pointer<int> it=arr.begin() ;it!=arr.end() ;it++ )
	{
		printf("%d " ,*it );
	}
	system("pause");
	return 0 ;
}