#include "Picture.h"
#include "PictureEntity.h"

Picture::Picture(void):ap(0 ){}

Picture::Picture(const char * const *pic, int n) :ap(new BasicPicture(pic, n)){}

Picture::Picture(const Picture &pic ):ap(pic.ap ){if(ap )ap->incuse();}

Picture::~Picture(void)
{
	if(ap &&ap->decuse()==0 )delete ap ;
}

Picture & Picture::operator=(const Picture &pic )
{
	if(pic.ap )pic.ap->incuse();
	if(ap && ap->decuse()==0 )delete ap ;
	ap =pic.ap ;
	return *this ;
}

Picture::Picture(PictureEntity* p ):ap(p ){if(ap )p->incuse();}

int Picture::width(void)const {return ap->width();}
int Picture::height(void )const {return ap->height();}

void Picture::display(ostream& o ,int y ,int mw )const {ap->display(o ,y ,mw );}

void Picture::Reframe(char corner ,char vlimit ,char hlimit )
{
	if(ap )ap->Reframe(corner ,vlimit ,hlimit );
}

ostream& operator<<(ostream& o ,const Picture& pic )
{
	int ht =pic.height() ;
	for(int i=0 ;i<ht ;i++ )
	{
		pic.display(o ,i ,0 );
		o <<std::endl ;
	}
	return o ;
}