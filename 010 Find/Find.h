#ifndef FIND__INC
#define FIND__INC
#pragma once
#define __E__TYPE 
#define find(beg,end,val) findE(beg,end,val)
#define findN(arr,num,val) Find2(arr,num,val)
#define findE(beg,end,val) Find5(beg,end,val)

const int* Find1(const int *arr ,int n ,int v )
{
	const int *p =arr ;
	for(int i=0 ;i<n ;i++ )
	{
		if(*p ==v )return p ;
		p++ ;
	}
	return 0 ;
}

template<typename T> T* Find2(T *arr ,int n ,const T& v ) // it is possible that we can't copy T
{
	T *p =arr ;
	for(int i=0 ;i<n ;i++ )
	{
		if(*p ==v )return p ;
		p++ ;
	}
	return 0 ;
}

template<typename T> T* Find3(T *beg ,T *end ,const T& v )
{
	
	for(T *p =beg ;p !=end ;p++ )
	{
		if(*p ==v )return p ;
	}
	return end ;
}

template<typename T> T* Find4(T *beg ,T *end ,const T& v )
{
	T *p =beg ;
	while(p!=end &&*p!=v )p++ ;
	return p ;
}

template<typename P ,typename T > P Find5(P beg ,P end ,const T& v )
{
	P p =beg ;
	while(p!=end &&*p!=v )p++ ;
	return p ;
}
#endif
