#ifndef COUNTER__INC
#define COUNTER__INC
#pragma once
class Counter
{
private :
	int *n ;
protected :
	inline int set(int v ){return *n=v ;}
public :
	Counter(void );
	~Counter(void );
	inline int operator++(void ){return *n++ ;}
	inline int operator--(void ){return *n-- ;}
	inline int operator++(int ){return ++*n ;}
	inline int operator--(int ){return --*n ;}
	inline int inc(void ){return ++*n ;}
	inline int dec(void ){return --*n ;}
	inline int num(void )const {return *n ;}

	inline bool isZero(void )const {return !*n ;}

};

#endif