#ifndef ITERATOROPERATOR__INC
#define ITERATOROPERATOR__INC
#pragma once

#define ITOP_VERSION 3
#if ITOP_VERSION ==1
int Add100(int n )
{
	return n +100 ;
}

#elif ITOP_VERSION ==2
class addN
{
public :
	addN(int n ):N(n ){}
	int operator()(int n )
	{
		return n +N ;
	}
private :
	int N ;
};
#elif ITOP_VERSION ==3
#include <functional>
using std::bind1st ;
using std::plus ;
#define add100 bind1st(plus<int>(),100)
#endif

#endif