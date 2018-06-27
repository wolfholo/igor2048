#ifndef _GAMESCENE_
#define _GAMESCENE_


#include "2048.h"

class gamescene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void back(cocos2d::Ref* pSender);


private:
	Size visibleSize;
	void keyPressed(EventKeyboard::KeyCode keyCode, Event *event);
	void CheckGameOver();  
	void autoCreatesquareNumber();  
	bool doLeft();  
	bool doRight();  
	bool doUp();  
	bool doDown();  
	float ssize;
	Point startPt;
	int offsetX, offsetY;
    class	square ***squareArr;
	class square ***squareArrAction;
	int mult;
	void createsquare(cocos2d::Size size);   
	int score;
	int squareSize;
	int squareg;
	cocos2d::LabelTTF *snumber;  

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	timeval tv;

	CREATE_FUNC(gamescene);
	
};






#endif