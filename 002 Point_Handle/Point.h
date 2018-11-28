#ifndef POINT__INC
#define POINT__INC
#pragma once
class Point
{
public :
	Point(void );
	Point(int x ,int y );
	int x(void )const ;
	int y(void )const ;
	Point& x(int xv );
	Point& y(int yv );
	~Point(void );
private :
	int xval ,yval ;
};

#endif