#include "PictureEntity.h"
#include <cstring>

PictureEntity::PictureEntity(void):use(1 ){}

PictureEntity::~PictureEntity(void){}

void PictureEntity::FillEmpty(ostream& o ,int start, int mw) const
{
	for(int i=start ;i<mw ;i++ )o <<' ';
}

int PictureEntity::max(int a, int b)
{
	return a>b?a:b;
}

void PictureEntity::Reframe(char corner, char vlimit, char hlimit){}

#pragma warning(push)
#pragma warning(disable:4996)
BasicPicture::BasicPicture(const char * const *pic , int n)
	:data(new char*[n] ),size(n ),MinWidth(0 ),m_width(new int[n] )
{
	for(int i=0 ;i<n ;i++ )
	{
		m_width[i] =strlen(pic[i] );
		data[i] =new char[m_width[i]+1 ];
		if(MinWidth <m_width[i] )MinWidth =m_width[i] ;
		strcpy(data[i] ,pic[i] );
	}
}
#pragma warning(pop)

BasicPicture::~BasicPicture(void)
{
	for(int i=0 ;i<size ;i++ )
	{
		delete [] data[i];
	}
	delete []data ;
}

void BasicPicture::incuse(void){++use ;}
int BasicPicture::decuse(void ){return --use ;}

int BasicPicture::width(void) const{return MinWidth ;}
int BasicPicture::height(void ) const{return size ;}
void BasicPicture::display(ostream& o,int y ,int mw )const 
{
	if(y <0 ||y>=size )FillEmpty(o ,0 ,mw );
	else
	{
		o <<data[y] ;
		FillEmpty(o ,m_width[y] ,mw );
	}
}

FramePicture::FramePicture(const Picture& pic ,char corner ,char vlimit ,char hlimit )
	:p(pic ),cl(corner ),vl(vlimit ),hl(hlimit ){}

FramePicture::~FramePicture(void){}

void FramePicture::incuse(void){++use ;}
int FramePicture::decuse(void ){return --use ;}

void FramePicture::Reframe(char corner, char vlimit, char hlimit)
{
	cl =corner ;vl =vlimit ;hl =hlimit ;
}

int FramePicture::width(void) const {return (p.width())+2;}
int FramePicture::height(void) const {return (p.height())+2;}
void FramePicture::display(ostream& o,int y ,int mw )const 
{
	if(y <0 ||y>=height())
	{
		FillEmpty(o ,0 ,mw );
	}
	else
	{
		if(y ==0 ||y==height()-1 )
		{
			o<<cl ;
			for(int i=1 ;i<=p.width() ;i++ )o<<vl ;
			o<<cl ;
		}
		else
		{
			o<<hl;
			p.display(o ,y-1 ,p.width());
			o<<hl;
		}
	}
}

Picture frame(const Picture& pic ,char corner ,char vlimit ,char hlimit )
{
	return Picture(new FramePicture(pic ,corner ,vlimit ,hlimit ));
}

VcatPicture::VcatPicture(const Picture &up , const Picture &down ):top(up ),bottom(down ){}

VcatPicture::~VcatPicture(void){}

void VcatPicture::incuse(void){++use ;}
int VcatPicture::decuse(void ){return --use ;}

int VcatPicture::width(void) const{return max(top.width() ,bottom.width());}
int VcatPicture::height(void ) const{return top.height() +bottom.height();}

void VcatPicture::display(ostream &o , int y, int mw ) const
{
	if(y >=0 &&y<top.height())top.display(o ,y ,mw );
	else if(y>=top.height() &&y<top.height()+bottom.height())
		bottom.display(o ,y-top.height() ,mw );
	else
		FillEmpty(o ,0 ,mw );
}


Picture operator&(const Picture& up ,const Picture& down )
{
	return new VcatPicture(up ,down );
}

HcatPicture::HcatPicture(const Picture &l , const Picture &r ):left(l ),right(r ){}

HcatPicture::~HcatPicture(void){}

void HcatPicture::incuse(void){++use ;}
int HcatPicture::decuse(void ){return --use ;}

int HcatPicture::width(void) const{return left.width()+right.width();}
int HcatPicture::height(void ) const{return max(left.height() ,right.height());}

void HcatPicture::display(ostream &o , int y, int mw ) const
{
	left.display(o ,y ,left.width());
	right.display(o ,y ,right.width());
	FillEmpty(o ,left.width()+right.width() ,mw );
}



Picture operator|(const Picture& l,const Picture& r)
{
	return new HcatPicture(l ,r );
}