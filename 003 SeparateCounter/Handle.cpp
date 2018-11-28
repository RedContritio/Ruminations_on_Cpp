#include "Handle.h"
#include <cstdio>

#ifndef USE_COUNTER
Handle::Handle():u(new int(1 )),p(new Point()){}

Handle::Handle(int x ,int y ):u(new int(1 )),p(new Point(x ,y )){}

Handle::Handle(const Point& pp ):u(new int(1 )),p(new Point(pp )){}

Handle::Handle(const Handle& h ):u(h.u ),p(h.p ){++*u ;}

Handle& Handle::operator=(const Handle& h )
{
	++*h.u ;
	if(--*u == 0 ){delete u ;delete p ;}
	u =h.u ;p =h.p ;
	return *this ;
}

Handle::~Handle(void ){if(--*u ==0 ){delete u ;delete p ;}}

#else
Handle::Handle():u(new Counter()),p(new Point()){}

Handle::Handle(int x ,int y ):u(new Counter()),p(new Point(x ,y )){}

Handle::Handle(const Point& pp ):u(new Counter()),p(new Point(pp )){}

Handle::Handle(const Handle& h ):u(h.u ),p(h.p ){u->inc();}

Handle& Handle::operator=(const Handle& h )
{
	h.u->inc();
	if(u->dec() == 0 ){delete u ;delete p ;}
	u =h.u ;p =h.p ;
	return *this ;
}

Handle::~Handle(void ){if(u->dec() ==0 ){delete u ;delete p ;}}
#endif
int Handle::x(void )const {return p->x() ;}
int Handle::y(void )const {return p->y() ;}

Handle& Handle::x(int xv ){p->x(xv );return *this ;}
Handle& Handle::y(int yv ){p->y(yv );return *this ;}


void DebugOutput(Handle* x )
{
	printf("this :%p ,&point :%p ,&counter :%p\n",x ,x->p ,x->u );
	printf("point :{%d %d } ,counter :%d \n",x->p->x() ,x->p->y() ,x->u->num());
}