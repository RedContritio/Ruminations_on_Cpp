#ifndef PICTURE__INC
#define PICTURE__INC
#pragma once
#include <fstream>
using std::ostream ;
using std::endl ;
#include "PictureEntity.h"


class Picture
{
private :
	PictureEntity *p ;
public:
	Picture(const char** ,int );
	Picture(int );
	Picture(PictureEntity * );
	Picture(const Picture& );
	Picture& operator=(const Picture& );
	~Picture(void );
	inline const char* at(int y )const {return p->m_pic[y] ;}
	inline char& at(int x ,int y ){return p->m_pic[y][x] ;};
	inline int Height(void )const {return p->m_height ;}
	inline int Width(void )const {return p->m_width ;}
	inline int Width(int y )const {return p->m_len[y] ;}
	inline void SetLine(const char* str ,int y ){p->SetLine(str ,y );}

	friend ostream& operator<<(ostream& ,const Picture& );
	friend Picture operator&(const Picture up ,const Picture down );
	friend Picture operator|(const Picture left ,const Picture right );
};

Picture frame(const Picture pic );
#endif