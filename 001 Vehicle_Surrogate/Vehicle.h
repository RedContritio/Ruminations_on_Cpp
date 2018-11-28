#ifndef VEHICLE__INC
#define VEHICLE__INC

#pragma once
class Vehicle
{
private :
public :
	Vehicle(void );
	virtual ~Vehicle(void );
	virtual double weight(void )const =0 ;
	virtual void start(void ) =0 ;
	virtual Vehicle *copy(void )const =0 ;
};

#endif