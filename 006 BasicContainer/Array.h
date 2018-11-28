#ifndef ARRAY__INC
#define ARRAY__INC
#pragma once

template<typename T> class Array ;

template<typename T> class __ArrayData
{
private :
	friend class Array<T>;

	__ArrayData(int n = 0 ):data(new T[size] ),size(n ),use(1 ){}
	~__ArrayData(void ){delete []data ;}
	inline void incuse(void ){use ++ ;}
	inline int decuse(void ){return --use ;}
	T& operator[](int n )
	{
		if( n>=size|| n<0 )
		{
			throw "Array Subscript out of Range.";
		}
		return data[n] ;
	}

	T& at(int n ){return data[n] ;}

/* functions following is not defined ,which is not expected to be use */
	__ArrayData(const __ArrayData& );
	__ArrayData& operator=(const __ArrayData& );

	T* data ;
	int size ;
	int use ;
};

template<typename T> class Array 
{
private :
	__ArrayData<T> *data ;
	Array(const Array<T>& );
	Array& operator=(const Array<T>& );
public :
	Array(int n ):data(new __ArrayData<T>(n )){}
	~Array(void ){if(data->decuse()==0)delete data ;}
	T& operator[](int n ){
		return data->at(n );
	}
};

template<typename T> class Ptr_to_const 
{
private :
	__ArrayData<T> *ap ;
	int sub ;
public :
	Ptr_to_const(const Array<T>& arr, unsigned n=0 ):ap(arr.data ),sub(n ){ap->incuse();}
	Ptr_to_const(void ):ap(0 ),sub(0 ){}
	Ptr_to_const(const Ptr_to_const<T>& p ):ap(p.ap ),sub(p.sub ){if(ap )ap->incuse();}
	~Ptr_to_const(void ){if(ap &&ap->decuse()==0 )delete ap ;}
	Ptr_to_const& operator=(const Ptr_to_const<T>& p )
	{
		if(p.ap )p.ap->incuse();
		if(ap &&ap->decuse()==0 )delete ap ;
		ap =p.ap ;sub =p.sub ;
		return *this ;
	}

	T& operator*(void )const
	{
		if(ap )
			throw("* of unbound Ptr_to_const* ");
		return (*ap)[sub] ;
	}
};

template<typename T> class Pointer :public Ptr_to_const<T>
{
public :
	Pointer(Array<T>& arr, unsigned n=0 ):Ptr_to_const<T>(arr ,n ){}
	Pointer(void ){}

	T& operator*(void )const
	{
		if(ap )
			throw("* of unbound Ptr_to_const* ");
		return (*ap)[sub] ;
	}
};
#endif