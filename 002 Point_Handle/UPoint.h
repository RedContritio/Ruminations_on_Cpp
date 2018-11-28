#ifndef UPOINT__INC
#define UPOINT__INC
#pragma once
#include "Point.h"

class Handle ;

class UPoint
{
private :
	Point p ;
	unsigned int u ;

	UPoint(void );
	UPoint(int x ,int y );
	UPoint(const Point& point );
	~UPoint(void );

	friend class Handle ;
};

#endif