#ifndef _SETTING_
#define _SETTING_


#include "2048.h"

extern int mode;
extern int order;
extern int probaility;
extern float size;

class setting : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();

 
    virtual bool init();  
private:


    void modem(cocos2d::Ref* pSender);
    void orderm(cocos2d::Ref* pSender);
	void probailitym(cocos2d::Ref* pSender);
	void sizem(cocos2d::Ref* pSender);
	void modep(cocos2d::Ref* pSender);
    void orderp(cocos2d::Ref* pSender);
	void probailityp(cocos2d::Ref* pSender);
	void sizep(cocos2d::Ref* pSender);
	void menubackCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(setting);
};
#endif