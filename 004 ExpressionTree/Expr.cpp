#include "Expr.h"

Expr::Expr(int n ){p =new IntNode(n );}

Expr::Expr(char op ,Expr r ){p =new UnaryNode(op ,r.p );}

Expr::Expr(char op ,Expr l ,Expr r ){p =new BinaryNode(op ,l.p ,r.p );}

Expr::Expr(char op1 ,char op2 ,Expr l ,Expr m ,Expr r ){p =new TernaryNode(op1 ,op2 ,l.p ,m.p ,r.p );}

Expr::Expr(const Expr& e ){p =e.p ;p->incuse(); }

Expr& Expr::operator=(const Expr& e )
{
	e.p->incuse();
	if(p->decuse()==0 )delete p ;
	p =e.p ;
	return *this ;
}

Expr::~Expr(void ){p->use -- ;if(p->use ==0 )delete p ;}

ostream& operator<<(ostream& o ,const Expr& e )
{
	o <<*(e.p );
	return o ;
}

int Expr::Calculate(void )const 
{
	return p->Calculate();
}