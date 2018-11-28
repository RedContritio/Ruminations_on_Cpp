#ifndef PICTUREENTITY__INC
#define PICTUREENTITY__INC
#pragma once

#include "Picture.h"

class PictureEntity
{
protected :
	int use ;
	virtual int width(void )const =0 ;
	virtual int height(void )const =0 ;
	virtual void display(ostream& ,int ,int )const =0 ;
	void FillEmpty(ostream& ,int ,int )const ;
	static int max(int a ,int b );
	virtual void Reframe(char corner ,char vlimit ,char hlimit );
public :
	PictureEntity(void );
	virtual ~PictureEntity(void );
	virtual void incuse(void )=0 ;
	virtual int decuse(void )=0 ;
	friend class Picture ;
};

class BasicPicture :public PictureEntity
{
private :
	char **data ;
	int size ;
	int *m_width ;
	int MinWidth ;
public :
	BasicPicture(const char* const* ,int n );
	~BasicPicture(void );
	void incuse(void );
	int decuse(void );

	int width(void )const ;
	int height(void )const ;
	void display(ostream& ,int y ,int MinWidth )const ;
};

class FramePicture :public PictureEntity
{
private :
	Picture p ;
	char cl ,vl ,hl ;
public :
	FramePicture(const Picture& ,char corner ,char vlimit ,char hlimit );
	~FramePicture(void );
	void incuse(void );
	int decuse(void );
	
	void Reframe(char corner ,char vlimit ,char hlimit );

	int width(void )const ;
	int height(void )const ;
	void display(ostream& ,int y ,int MinWidth )const ;

	friend Picture frame(const Picture& );
};

class VcatPicture :public PictureEntity
{
private :
	Picture top ,bottom ;
public :
	VcatPicture(const Picture& ,const Picture& );
	~VcatPicture(void );
	void incuse(void );
	int decuse(void );
	
	int width(void )const ;
	int height(void )const ;
	void display(ostream& ,int y ,int MinWidth )const ;

	friend Picture operator&(const Picture& ,const Picture& );
};

class HcatPicture :public PictureEntity
{
public :
	Picture left ,right ;
public :
	HcatPicture(const Picture& ,const Picture& );
	~HcatPicture(void );
	void incuse(void );
	int decuse(void );
	
	int width(void )const ;
	int height(void )const ;
	void display(ostream& ,int y ,int MinWidth )const ;

	friend Picture operator|(const Picture& ,const Picture& );
};
#endif