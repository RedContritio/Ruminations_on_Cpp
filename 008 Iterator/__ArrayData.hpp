#ifndef __ARRAYDATA__INC
#define __ARRAYDATA__INC
#pragma once
template<typename T> class __ArrayData
{
private :
	int m_size ;
	T *m_data ;
	int use ;
	static void copy(T *dst ,T *src ,int dsize ,int ssize )
	{
		for(int i=0 ;i<dsize &&i<ssize ;i++ )
			dst[i] =src[i] ;
	}
public :
	__ArrayData(void ):m_data(0 ),m_size(0 ),use(1 ){}
	__ArrayData(int n ):m_size(n ),m_data(new T[n] ),use(1 ){}
	__ArrayData(const __ArrayData<T>& arr ):m_size(arr.m_size ),m_data(new T[arr.m_size] ),use(1 )
	{
		copy(m_data ,arr.m_data ,m_size ,arr.m_size );
	}
	~__ArrayData(void ){delete []m_data ;}
	void incuse(void ){++use ;}
	int decuse(void ){return --use ;}
	T& at(int n ){return m_data[n] ;}
	void resize(int n )
	{
		if(n ==m_size )return ;
		T* prdata =m_data ;
		m_data =new T[n] ;
		this->copy(m_data ,prdata ,n ,m_size );
		delete []prdata ;
		m_size =n ;
	}
	void growto(int nsize )
	{
		int psize =m_size ;
		if(psize ==0 )psize =1 ;
		while(psize <=nsize )
		{
			nsize *=2 ;
		}
		resize(psize );
	}
	void clear(void )
	{
		if(m_data )delete []m_data ;
		m_size =0 ;
		m_data =0 ;
	}
	bool empty(void )
	{
		return m_data ==0 ||m_size ==0 ;
	}
	int size(void )
	{
		return m_size ;
	}
};

#endif
