#ifndef HANDLE__INC
#define HANDLE__INC
#pragma once
#include "Point.h"
#define USE_COUNTER

#include "Counter.h"
class Handle
{
private :
#ifndef USE_COUNTER
// should a counter is just a int ? I can hardly agree .
	int *u ; // counter
#else
	Counter *u ;
#endif
	Point *p ;
public :
	Handle(void );
	Handle(int x ,int y );
	Handle(const Point& p );
	Handle(const Handle& h );
	Handle& operator=(const Handle& h );
	~Handle(void );

	int x(void )const ;
	int y(void )const ;
	Handle& x(int xv );
	Handle& y(int yv );

	friend void DebugOutput(Handle* );
};

void DebugOutput(Handle* x );
#endif