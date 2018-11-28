#include "PictureEntity.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>


PictureEntity::PictureEntity(const char** pic ,int n ):m_use(1 ),m_height(n ),m_width(0 )
{
	m_pic =(char** )malloc(n *sizeof(char* ));
	m_len =(int* )malloc(n *sizeof(int ));
	for(int i=0 ;i<n ;i++ )
	{
		m_len[i] =strlen(pic[i] );
		if(m_width <m_len[i] )m_width =m_len[i] ;
		m_pic[i] =(char* )malloc((m_len[i]+1)*sizeof(char ));
		memcpy(m_pic[i] ,pic[i] ,(m_len[i]+1)*sizeof(char ));
	}
}

PictureEntity::PictureEntity(int n ):m_use(1 ),m_height(n )
{
	m_pic =(char** )calloc(n ,sizeof(char* ));
	m_len =(int* )malloc(n *sizeof(int ));
	memset(m_len ,-1 ,n *sizeof(int ));
}

PictureEntity::~PictureEntity(void )
{
	for(int i=0 ;i<m_height ;i++ )free(m_pic[i] );
	free(m_pic );
}

void PictureEntity::SetLine(const char *str ,int y )
{
	assert(y <m_height );
	if(m_len[y] >=0 )free(m_pic[y] );
	m_len[y] =strlen(str );
	if(m_width <m_len[y] )m_width =m_len[y] ;
	m_pic[y] =(char* )malloc((m_len[y]+1)*sizeof(char ));
	memcpy(m_pic[y] ,str ,(m_len[y]+1 )*sizeof(char ));
}