#ifndef _RANKINGLIST_
#define _RANKINGLIST_


#include "2048.h"


class rankinglist : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();


    virtual bool init();  

private:

	void back(cocos2d::Ref* pSender);

    CREATE_FUNC(rankinglist);
};
#endif