#include <cstdio>
#include <cstdlib>

#include "Vehicle.h"
#include "RoadVehicle.h"
#include "AirVehicle.h"
#include "VehicleSurrogate.h"

#define SURROGATE__USE

#ifdef SURROGATE__USE
VehicleSurrogate parkinglot[1000] ;
int NumVehicles =0 ;
#else
// AN ERROR : unable use any class with pure virtual functions
// Vehicle parkinglot[1000] ;

AutoVehicle AV_x ;

Vehicle *parkinglot[100] ;
int NumVehicles =0 ;
#endif

int main(void )
{
#ifdef SURROGATE__USE
	AutoVehicle AV_x ;
	parkinglot[NumVehicles++] =AV_x ;
	printf("the vehicle on parking lot 0 weight is %g .\n",parkinglot[0].weight());
	try
	{
		parkinglot[1].start();
	}
	catch (const char* ExceptionDescription )
	{
		printf("Catch Exception :\"%s\"\n" ,ExceptionDescription );
	}
#else
// AN ERROR : unable know the type of pointer without AV_x 
//	parkinglot[NumVehicles++] =&AV_x ;

	parkinglot[NumVehicles++] =new AutoVehicle(AV_x );
	if(parkinglot[1] !=parkinglot[0] )
	{
		if(parkinglot[1] )delete parkinglot[1] ;
// AN ERROR : unable use new operator on a class with pure virtual functions ,
//			  a virtual copy function is in need
//		parkinglot[1] =new Vehicle(parkinglot[0] );

		parkinglot[1] =parkinglot[0]->copy(); // but should I release it by myself
// AN WARNING : if user should release ,it is a bad design .
// but if not ,the memory will leak 
	}
#endif
	system("pause" );
	return 0 ;
}