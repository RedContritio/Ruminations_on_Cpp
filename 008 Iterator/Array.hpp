#ifndef ARRAY__INC
#define ARRAY__INC
#pragma once
#include "__ArrayData.hpp"

template<typename T> class Ptr_to_const ;
template<typename T> class Pointer ;

template<typename T > class Array
{
private :
	__ArrayData<T> *data ;
public :
	Array(void ):data(0 ){}
	Array(int n ):data(new __ArrayData<T>(n )){}
	Array(const Array<T>& a )
	{
		data =new __ArrayData<T>(a.data );
	}
	~Array(void ){if(data &&data->decuse()==0)delete data ;}

	Array& operator=(const Array<T>& a )
	{
		if(&a !=this )
			data =new __ArrayData<T>(a.data );
		return *this ;
	}
	T& operator[](int n )
	{
		if(data ==0 )
		{
			throw "No data is allocated";
		}
		else if(n <0 ||(n >=data->size()))
		{
			throw "Illegal Subscript";
		}
		return data->at(n );
	}

	Pointer<T> begin(void )const {return Pointer<T>(data ,0 );}
	Pointer<T> end(void )const {return Pointer<T>(data ,data->size());}
	void resize(int n ){data->resize(n );}

	friend class Ptr_to_const<T> ;
};

template<typename T> class Ptr_to_const 
{
protected :
	__ArrayData<T> *ap ;
	int sub ;
	T& at(void )const {return ap->at(sub );}
public :
	Ptr_to_const(void ):ap(0 ),sub(0 ){}
	Ptr_to_const(const Array<T>& a ,int n=0 ):ap(a.data ),sub(n ){a.data->incuse();}
	Ptr_to_const(const Ptr_to_const<T>& p ):ap(p.ap ),sub(p.sub ){if(ap )ap->incuse();}
	Ptr_to_const(__ArrayData<T> *p ,int n =0 ):ap(p ),sub(n ){if(p )p->incuse();}
	~Ptr_to_const(void ){if(ap &&ap->decuse()==0 )delete ap ;}

	Ptr_to_const& operator=(const Ptr_to_const<T>& p )
	{
		if(p.ap )p.ap->incuse();
		if(ap &&ap->decuse()==0 )delete ap ;
		ap =p.ap ;sub =p.sub ;
		return *this ;
	}

	const T& operator*(void )const 
	{
		if(ap ==0 )
		{
			throw "Unable operator * ";
		}
		return ap->at(sub );
	}
};

template<typename T> class Pointer :public Ptr_to_const<T>
{
public :
	Pointer(Array<T>& arr ,int n=0 ):Ptr_to_const<T>(arr ,n ){}
	Pointer(__ArrayData<T> *p ,int n=0 ):Ptr_to_const<T>(p ,n ){}
	Pointer(const Pointer<T>& ptr ):Ptr_to_const<T>(ptr.ap ,ptr.sub ){}
	Pointer(void ){}

	T& operator*(void )const
	{
		return this->at();
	}
	Pointer<T> operator+(int n ){return Pointer<T>((__ArrayData<T>*)(this->ap) ,(this->sub)+n );}
	Pointer<T> operator-(int n ){return Pointer<T>((__ArrayData<T>*)(this->ap) ,(this->sub)-n );}
	Pointer<T>& operator+=(int n ){this->sub +=n ;return *this ;}
	Pointer<T>& operator-=(int n ){this->sub -=n ;return *this ;}
	Pointer<T>& operator++(void ){++(this->sub );return *this ;}
	Pointer<T> operator++(int ){Pointer<T> x(*this );++(this->sub );return x ;}
	Pointer<T>& operator--(void ){--(this->sub );return *this ;}
	Pointer<T> operator--(int ){Pointer<T> x(*this );--(this->sub );return x ;}

	bool operator==(const Pointer<T>& rhs ){return (void*)(this->ap +this->sub )==(void*)(rhs.ap +rhs.sub );}
	bool operator!=(const Pointer<T>& rhs ){return !(*this ==rhs );}
	bool operator<(const Pointer<T>&rhs ){return (void*)(this->ap +this->sub )<(void*)(rhs.ap +rhs.sub );}
	bool operator>(const Pointer<T>&rhs ){return (void*)(this->ap +this->sub )>(void*)(rhs.ap +rhs.sub );}
	bool operator<=(const Pointer<T>&rhs ){return (void*)(this->ap +this->sub )<=(void*)(rhs.ap +rhs.sub );}
	bool operator>=(const Pointer<T>&rhs ){return (void*)(this->ap +this->sub )>=(void*)(rhs.ap +rhs.sub );}
};
#endif