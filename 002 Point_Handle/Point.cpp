#include "Point.h"

Point::Point(void ):xval(0 ),yval(0 ){}

Point::Point(int x ,int y ):xval(x ),yval(y ){}

int Point::x(void )const {return xval ;}
int Point::y(void )const {return yval ;}

Point& Point::x(int xv ){xval =xv ;return *this ;}
Point& Point::y(int yv ){yval =yv ;return *this ;}

Point::~Point(){}