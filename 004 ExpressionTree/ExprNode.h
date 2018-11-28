#ifndef EXPRNODE__INC
#define EXPRNODE__INC
#pragma once
#include <iostream>
using std::ostream ;

class Expr ;

class ExprNode
{
protected :

	virtual void print(ostream& )const =0 ;

public :
	virtual void incuse(void )=0 ;
	virtual int decuse(void )=0 ;
	virtual int Calculate(void )const =0 ;
	int use ;
	friend class Expr ;
	friend ostream& operator<<(ostream& ,const ExprNode& );
	ExprNode(void );
	virtual ~ExprNode(void );
};

class IntNode :public ExprNode 
{
	friend class Expr ;
	int n ;
	IntNode(int );
	~IntNode(void );
	void print(ostream& o )const ;
	void incuse(void );
	int decuse(void );
	int Calculate(void )const ;
};

class UnaryNode :public ExprNode
{
	friend class Expr ;
	char op ;
	ExprNode *opnd ;
	UnaryNode(char op_ch ,ExprNode *obj );
	~UnaryNode(void );
	void print(ostream& )const ;
	void incuse(void );
	int decuse(void );
	int Calculate(void )const ;
};

class BinaryNode :public ExprNode 
{
	friend class Expr ;
	char op ;
	ExprNode *left ,*right ;
	BinaryNode(char op_ch ,ExprNode *l ,ExprNode *r );
	~BinaryNode(void );
	void print(ostream& )const ;
	void incuse(void );
	int decuse(void );
	int Calculate(void )const ;
};

class TernaryNode :public ExprNode
{
	friend class Expr ;
	char op1 ,op2 ;
	ExprNode *left ,*middle ,*right ;
	TernaryNode(char op_1 ,char op_2 ,ExprNode *l ,ExprNode *m ,ExprNode *r );
	~TernaryNode(void );
	void print(ostream& )const ;
	void incuse(void );
	int decuse(void );
	int Calculate(void )const ;
};
#endif