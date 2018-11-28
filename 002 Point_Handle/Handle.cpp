#include "Handle.h"

Handle::Handle(void ):up(new UPoint()){}

Handle::Handle(int x ,int y ):up(new UPoint(x ,y )){}

Handle::Handle(const Point& p ):up(new UPoint(p )){}

Handle::Handle(const Handle& h ):up(h.up ){++up->u ;}

Handle::~Handle(void ){ReleaseEntity();}

Handle& Handle::operator=(const Handle& h )
{
	++h.up->u ;
	ReleaseEntity();
	up =h.up ;
	return *this ;
}

int Handle::x(void )const {return up->p.x();}

int Handle::y(void )const {return up->p.y();}

Handle& Handle::x(int xv ){up->p.x(xv );return *this ;}

Handle& Handle::y(int xv ){up->p.y(xv );return *this ;}

void Handle::ReleaseEntity(void){if(--up->u == 0 )delete up ;}

void Handle::ApplyEntityPtr(UPoint *p ){++p->u ;up =p ;}