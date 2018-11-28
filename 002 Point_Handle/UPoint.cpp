#include "UPoint.h"



UPoint::UPoint(void):p( ),u(1 ){}

UPoint::UPoint(int x ,int y ):p(x ,y ),u(1 ){}

UPoint::UPoint(const Point& point ):p(point ),u(1 ){}

UPoint::~UPoint(){}
