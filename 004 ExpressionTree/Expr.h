#ifndef EXPR__INC
#define EXPR__INC
#pragma once
#include "ExprNode.h"
#include "Counter.h"
#include <iostream>
using std::ostream ;

class Expr
{
private :
	ExprNode *p ;
public :
	Expr(int );
	Expr(char ,Expr );
	Expr(char ,Expr ,Expr );
	Expr(const Expr& );
	Expr(char ,char ,Expr ,Expr ,Expr );
	Expr& operator=(const Expr& );
	int Calculate(void )const ;
	~Expr(void );

	friend ostream& operator<<(ostream& ,const Expr& );
};

#endif