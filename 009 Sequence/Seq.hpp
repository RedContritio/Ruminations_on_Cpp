#ifndef SEQ__INC
#define SEQ__INC
#pragma once
#include "List.hpp"

// because I will use template ,I won't need __LIST__HEAD function , \
	instead ,I will construct list head by myself
template<typename T> class Sequence
{
private :
	__Seq<T> *phead ;
	Sequence(__Seq<T>* p ):phead(p ){if(p )p->incuse();}
public :
	Sequence(void ):phead(0 ){}
	Sequence(T value ):phead(new __Seq<T>(value )){}
	Sequence(T value ,Sequence<T> seq ):phead(new __Seq<T>(value ,seq.phead )){}
	Sequence(const Sequence<T>& pro ):phead(pro.phead ){if(phead )phead->incuse() ;}
	Sequence<T>& operator=(const Sequence<T>& rhs )
	{
		if(rhs.phead )rhs.phead->incuse();
		if(phead && phead->decuse()==0 )delete phead ;
		phead =rhs.phead ;
		return *this ;
	}
	~Sequence(void ){if(phead &&phead->decuse()==0 )delete phead ;}
	T hd(void )const 
	{
		if(!phead )throw "There is a nil sequence ,fuck you !" ;
		return phead->data ;
	}
	Sequence<T> tl(void )const 
	{
		if(!phead )throw "There is a nil sequence ,»¨ Q !" ;
		return Sequence<T>(phead->next );
	}
	bool Empty(void )const 
	{
		return phead==0 ;
	}
	Sequence<T>& operator++(void )
	{
		if(phead )
		{
			__Seq<T> *nx =phead->next ;
			if(nx )nx->incuse();
			if(phead &&phead->decuse()==0 )delete phead ;
			this->phead =nx ;
		}
		return *this ;
	}
};

template<typename T > Sequence<T> cons(const T& value ,const Sequence<T>& s )
{
	return Sequence<T>(value ,s );
}

template<typename T > int SeqLength(Sequence<T> s )
{
	int n=0 ;
	while(!s.Empty() )
	{
		++s ;++n ;
	}
	return n ;
}
#endif
