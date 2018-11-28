#ifndef PICTUREENTITY__INC
#define PICTUREENTITY__INC
#pragma once
class Picture ;

class PictureEntity
{
private :
	char** m_pic ;
	int m_use ;
	int m_height ;
	int m_width ;
	int *m_len ;
	inline void incuse(void ){m_use ++ ;}
	inline int decuse(void ){return --m_use ;}
	void SetLine(const char* str ,int y );
public :
	PictureEntity(const char** pic ,int n );
	PictureEntity(int n );
	~PictureEntity(void );
	friend class Picture ;
};

#endif