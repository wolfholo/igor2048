#ifndef _MAINMENU_
#define _MAINMENU_


#include "2048.h"


class mainmenu : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

    virtual bool init();  
	
private:

    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuItem1Callback(cocos2d::Ref* pSender);
	void menuItem2Callback(cocos2d::Ref* pSender);
	void menuItem3Callback(cocos2d::Ref* pSender);
    CREATE_FUNC(mainmenu);
};

#endif