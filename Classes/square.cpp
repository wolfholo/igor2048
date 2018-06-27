#include "square.h"  

bool square::init() 
{  
	if (!Sprite::init()) 
	{  
		return false;  
	}  
	return true;  
}  


void square::setn(int n) 
{  
	rnumber = n;

	if(mode==1)
	{
		number=pow(2,n);
	}
	if(mode==2)
	{
		number=n;
	}
	if (n > 0)
	{
		numl->setString(__String::createWithFormat("%i",number)->getCString());
	} 
	else 
	{
		numl->setString("");
	}

	numl->setFontSize(color->getContentSize().width/3);
	numl->setFontSize(color->getContentSize().width-numl->getContentSize().width);
	
	if (n >= 0)
	{
		color->setColor(Color3B(200, 190, 180));
	}
	if (n >= 1)
	{
		color->setColor(Color3B(240, 230, 220));
	}
	if (n >= 3)
	{
		color->setColor(Color3B(155,155,124));
	}
	if (n >= 5)
	{
		color->setColor(Color3B(155,155,0));
	}
	if (n >= 7)
	{
		color->setColor(Color3B(200,200,60));
	}
	if (n >= 9)
	{
		color->setColor(Color3B(255,215,0));
	}
	if (n >= 11)
	{
		color->setColor(Color3B(224,255,255));
	}
	if (n >= 13)
	{
		color->setColor(Color3B(0,255,255));
	}
	if (n >= 15)
	{
		color->setColor(Color3B(173,216,230));
	}
	if (n >= 17)
	{
		color->setColor(Color3B(127,255,212));
	}
	if (n >= 19)
	{
		color->setColor(Color3B(219,112,147));
	}
	if (n >= 21)
	{
		color->setColor(Color3B(255,0,255));
	}
	if (n >= 23)
	{
		color->setColor(Color3B(245,245,245));
	}
	if (n >= 25)
	{
		color->setColor(Color3B(245,222,179));
	}

}  

int square::getn() 
{  
	return rnumber;  
}  

square* square::create(int n,int length,float x,float y) 
{  

	square *sq = new square();
	if (sq && sq->init()) 
	{
		sq->autorelease();
		sq->sInit(n,length,x,y);
		return sq;
	}
	CC_SAFE_DELETE(sq);
	return NULL;
}

void square::sInit(int n, int length, float x, float y) 
{  
 
	rnumber = n;  
  
	color = cocos2d::LayerColor::create(cocos2d::Color4B(200, 190, 180, 255),length,length);  
	color->setPosition(Point(x, y));  

	if (rnumber > 0) 
	{  
		numl = cocos2d::LabelTTF::create(__String::createWithFormat("%i", rnumber)->getCString(), "MarkerFelt-Thin", length/3);  
		numl->setPosition(Point(color->getContentSize().width/2, color->getContentSize().height/2));  
		color->addChild(numl);  
	} 
	else 
	{  
		numl = cocos2d::LabelTTF::create("", "MarkerFelt-Thin",length/3);  
		numl->setPosition(Point(color->getContentSize().width/2, color->getContentSize().height/2));  
		color->addChild(numl);  
	}  

	this->addChild(color);  

}  

LayerColor* square::getsquarecolor()
{
	return color;
}