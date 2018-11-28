#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Expr.h"

#include <iostream>
using std::cout ;

int main()
{
	Expr a('+' ,Expr(5 ),Expr('-' ,Expr(7 ),Expr(3 )));
	cout<<a <<"=" <<a.Calculate() <<std::endl ;
	a=Expr('?' ,':' ,Expr('/' ,Expr(5) ,Expr(6 )),Expr('-' ,Expr(7 ),Expr(3 )),Expr('%' ,Expr(17) ,Expr(3 )));
	cout<<a <<"=" <<a.Calculate();
	system("pause" );
	return 0 ;
}