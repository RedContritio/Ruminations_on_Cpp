#ifndef LIST__INC
#define LIST__INC
#pragma once

template<typename T >struct __Seq
{
	int use ;
	const T data ;
	__Seq *next ;
	void incuse(void ){++use ;}
	int decuse(void ){return --use ;}
	__Seq(const T& t ,__Seq *s ):data(t ),use(1 ),next(s ){s->incuse();}
	__Seq(const T& t ):data(t ),use(1 ),next(0 ){}
	~__Seq(void ){if(next &&next->decuse())delete next ;}
};
#endif
