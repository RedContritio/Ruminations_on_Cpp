#ifndef PICTURE__INC
#define PICTURE__INC
#pragma once
#include <fstream>
using std::ostream ;
class PictureEntity ;

class Picture
{
private :
	PictureEntity *ap ;
	Picture(PictureEntity* p );

	int width(void )const ;
	int height(void )const ;
	void display(ostream& ,int ,int )const ;
public :
	Picture(void );
	Picture(const char* const * ,int );
	Picture(const Picture& );
	~Picture(void );

	Picture& operator=(const Picture& );
	void Reframe(char corner ,char vlimit ,char hlimit );

	friend ostream& operator<<(ostream& ,const Picture& );
	friend Picture frame(const Picture& ,char corner ='+' ,char vlimit ='-' ,char hlimit ='|' );
	friend Picture operator&(const Picture& ,const Picture& );
	friend Picture operator|(const Picture& ,const Picture& );

	friend class BasicPicture ;
	friend class FramePicture ;
	friend class VcatPicture ;
	friend class HcatPicture ;
};

#endif