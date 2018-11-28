#ifndef GREATER__INC
#define GREATER__INC
#pragma once

#define GREATER_VERSION 5

#if GREATER_VERSION <5 
bool greater10(int n );
#endif

#if GREATER_VERSION==1 
bool greater10(int n )
{
	return n >10 ;
}
#else // version >= 2 
#include <algorithm>
using std::greater ;
#if GREATER_VERSION==2
bool greater10(int n )
{
	greater<int> gt ;
	return gt(n ,10 );
}
#else // version >= 3  
#include <functional>
using std::bind2nd ;
#if GREATER_VERSION ==3
bool greater10(int n )
{
	greater<int> gt ;
	return (bind2nd(gt ,10 ))(n );
}
#elif GREATER_VERSION ==4 
bool greater10(int n )
{
	return bind2nd(greater<int>(),10)(n);
}
#elif GREATER_VERSION ==5 
#define greater10 bind2nd(greater<int>(),10)
#endif
#endif

#endif

#endif
