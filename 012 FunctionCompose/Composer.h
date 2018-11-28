#ifndef COMPOSER__INC
#define COMPOSER__INC
#pragma once

#define ComposerVersion 3
#if ComposerVersion ==1
class IntegarComposer
{
public :
	IntegarComposer(int (*f)(int ),int (*g)(int )):m_f(f ),m_g(g ){}
	int operator()(int n )const 
	{
		return m_f(m_g(n));
	}
private :
	int (*m_f)(int );
	int (*m_g)(int );
};
#elif ComposerVersion ==2
template<typename F ,typename G ,typename X ,typename Y > class Composer
{
public :
	Composer(F f ,G g ):m_f(f ),m_g(g ){}
	Y operator()(X x )const
	{
		return (Y)(m_f(m_g(x)));
	}
private :
	F m_f ;
	G m_g ;
};
#elif ComposerVersion ==3

template<typename X ,typename Y> class __ComposerBase
{
public :
	virtual Y operator()(X x )const =0 ;
	virtual __ComposerBase *clone(void )const =0 ;
	virtual ~__ComposerBase(void ){}
};

template<typename F ,typename G ,typename X ,typename Y > class __Composer :public __ComposerBase<X,Y> 
{
public :
	__Composer(F f ,G g ):m_f(f ),m_g(g ){}
	Y operator()(X x )const 
	{
		return m_f(m_g(x ));
	}
	__ComposerBase<X,Y> *clone(void )const
	{
		return new __Composer<F,G,X,Y>(*this );
	}
private :
	F m_f ;
	G m_g ;
};

template<typename X ,typename Y > class Composition
{
public :
	template<typename F ,typename G >Composition(F f ,G g ):p(new __Composer<F,G,X,Y>(f,g)){};
	Composition(const Composition<X,Y>& rhs ):p(rhs.p->clone()){}
	~Composition(void ){delete p ;}
	Y operator()(X x )const {return (*p)(x);}
	Composition<X,Y>& operator=(const Composition<X,Y>& rhs )
	{
		if(*this ==rhs )return *this ;
		p =rhs.p->clone();
		return *this ;
	}
private :
	__ComposerBase<X,Y> *p ;
};
#endif
#endif
