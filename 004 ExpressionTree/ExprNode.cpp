#include "ExprNode.h"

ExprNode::ExprNode(void ):use(1 ){}

ExprNode::~ExprNode(void ){}

ostream& operator<<(ostream &o , const ExprNode &e )
{
	e.print(o );
	return o ;
}

IntNode::IntNode(int v ):n(v ){}

IntNode::~IntNode(void){}

void IntNode::print(ostream& o )const {o<<n ;}

void IntNode::incuse(void ){use++ ;}
int IntNode::decuse(void ){return --use ;}

int IntNode::Calculate(void )const {return n ;}

UnaryNode::UnaryNode(char op_ch ,ExprNode *obj ):op(op_ch ),opnd(obj )
{
	obj->incuse();
}

UnaryNode::~UnaryNode(void ){}

void UnaryNode::print(ostream& o )const { o<< '('<< op<< *opnd<< ')';}

void UnaryNode::incuse(void ){use++ ;opnd->incuse();}
int UnaryNode::decuse(void ){use-- ;if(opnd->decuse()==0)delete opnd ;return use ;}

int UnaryNode::Calculate(void )const 
{
	int ans =opnd->Calculate() ;
	switch(op )
	{
		case '-' :
		{
			ans= -ans ;
			break ;
		}
		case '+' :
		{
			ans= ans ;
			break ;
		}
		default :
		{
			throw("Unexpected Unary Operator");
			NULL ;
			break ;
		}
	}
	return ans ;
}

BinaryNode::BinaryNode(char op_ch ,ExprNode *l ,ExprNode *r ):op(op_ch ),left(l ),right(r )
{
	l->incuse(); r->incuse();
}

BinaryNode::~BinaryNode(void ){}

void BinaryNode::print(ostream& o )const { o<< '('<< *left<< op<< *right<< ')';}

void BinaryNode::incuse(void ){use++ ;left->incuse();right->incuse();}
int BinaryNode::decuse(void )
{
	use-- ;
	if(left->decuse()==0 )delete left ;
	if(right->decuse()==0 )delete right ;
	return use ;
}

int BinaryNode::Calculate(void )const 
{
	int lhs =left->Calculate();
	int rhs =right->Calculate();
	int ans =0 ;
	switch(op )
	{
		case '+' :
		{
			ans =lhs +rhs ;
			break ;
		}
		case '-' :
		{
			ans =lhs -rhs ;
			break ;
		}
		case '*' :
		{
			ans =lhs *rhs ;
			break ;
		}
		case '/' :
		{
			ans =lhs /rhs ;
			break ;
		}
		case '%' :
		{
			ans =lhs %rhs ;
			break ;
		}
		default :
		{
			throw("Unexpected Binary operator");
			break ;
		}
	}
	return ans ;
}

TernaryNode::TernaryNode(char op_1 ,char op_2 ,ExprNode *l ,ExprNode *m ,ExprNode *r )
	:left(l ),middle(m ),right(r ),op1(op_1 ),op2(op_2 )
{
	l->incuse();
	m->incuse();
	r->incuse();
}

TernaryNode::~TernaryNode(void ){}

void TernaryNode::print(ostream& o )const 
{
	o << '(' <<*left <<op1 <<*middle <<op2 <<*right <<')';
}

void TernaryNode::incuse(void )
{
	use ++ ;
	left->incuse();middle->incuse();right->incuse();
}

int TernaryNode::decuse(void )
{
	use-- ;
	if(left->decuse()==0 )delete left ;
	if(middle->decuse()==0 )delete middle ;
	if(right->decuse()==0 )delete right ;
	return use ;
}

int TernaryNode::Calculate(void )const
{
	int ans =0 ;
	if(op1 =='?' &&op2 ==':' )ans= left->Calculate()?middle->Calculate():right->Calculate() ;
	else throw("Unexpected Ternary Operator");
	return ans ;
}