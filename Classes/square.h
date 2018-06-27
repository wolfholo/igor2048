#ifndef _SQUARE_
#define _SQUARE_

#include "2048.h"

class square:public cocos2d::Sprite {  

public:  

	static square *create(int numbers, int length, float x, float y);  

	virtual bool init();  



	void setn(int num);  
	LayerColor* getsquarecolor();
	int getn();  

private:  

	int number; 
	int rnumber;
	void sInit(int n, int length, float x, float y);  


	LabelTTF *numl;  
  
	LayerColor *color;  

		CREATE_FUNC(square); 
};  

#endif