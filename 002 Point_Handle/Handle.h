#ifndef HANDLE__INC
#define HANDLE__INC
#pragma once
#include "UPoint.h"

class Handle
{
private :
	UPoint *up ;
	void ReleaseEntity(void );
	void ApplyEntityPtr(UPoint* p );
public:
	Handle(void );
	Handle(int x ,int y );
	Handle(const Point& p );
	Handle(const Handle& h );
	Handle& operator=(const Handle& h );
	~Handle(void );

	int x(void )const ;
	Handle& x(int xv ); // if use handle like a value ,should copy the entity when change it
	int y(void )const ;
	Handle& y(int yv );
};

#endif