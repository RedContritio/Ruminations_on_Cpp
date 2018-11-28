#include "Picture.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

Picture::Picture(const char** strs ,int n ):p(new PictureEntity(strs ,n ))
{
	;
}

Picture::Picture(int n ):p(new PictureEntity(n ))
{
}

Picture::Picture(PictureEntity *e ):p(e )
{
	p->incuse();
}

Picture::Picture(const Picture& rhs )
{
	p =rhs.p ;
	p->incuse();
}

Picture &Picture::operator=(const Picture &rhs )
{
	rhs.p->incuse();
	if(p->decuse()==0)delete p ;
	p =rhs.p ;
	return *this ;
}

Picture::~Picture(void )
{
	if(p->decuse()==0 )delete p ;
}

ostream& operator<<(ostream& o ,const Picture& e )
{
	for(int i=0 ;i<e.Height() ;i++ )o<<e.at(i )<<endl ;
	return o ;
}

Picture operator&(const Picture up, const Picture down)
{
	Picture x(up.Height()+down.Height());
	for(int i=0 ;i<up.Height() ;i++ )x.SetLine(up.at(i) ,i );
	for(int i=0 ;i<down.Height() ;i++ )x.SetLine(down.at(i) ,i+up.Height());
	return x ;
}

Picture operator|(const Picture left, const Picture right)
{
	Picture x(left.Height() >right.Height()?left.Height():right.Height());
	char *s =(char* )malloc(left.Width() +right.Width()+1);
	for(int i=0 ;i<x.Height() ;i++ )
	{
		memset(s ,0x20 ,left.Width()*sizeof(char ));
		s[left.Width()]=0 ;
		if(i<right.Height() &&right.Width(i)>=0)memcpy(s+left.Width() ,right.at(i) ,(right.Width(i )+1)*sizeof(char ));
		if(i<left.Height() &&left.Width(i)>=0 )memcpy(s ,left.at(i ),left.Width(i )*sizeof(char ));
		x.SetLine(s ,i );
	}
	return x ;
}

Picture frame(const Picture pic)
{
	Picture x(pic.Height()+2 );
	char *s =(char* )malloc((pic.Width()+3 )*sizeof(char ));
	s[0] =s[pic.Width()+1] ='+' ;s[pic.Width()+2] =0 ;
	for(int i=0 ;i<pic.Width() ;i++ )s[i+1] ='-' ;
	x.SetLine(s ,0 );
	x.SetLine(s ,pic.Height()+1 );
	for(int i=0 ;i<pic.Height() ;i++ )
	{
		memset(s ,0x20 ,(pic.Width()+2 )*sizeof(char ));
		s[0] =s[pic.Width()+1] ='|' ;
		memcpy(s+1 ,pic.at(i ),(pic.Width(i ))*sizeof(char ));
		x.SetLine(s ,i+1 );
	}
	return x ;
}
