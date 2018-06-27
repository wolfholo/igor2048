#ifndef  _APPDELEGATE_
#define  _APPDELEGATE_


#include "2048.h"


class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();


    virtual bool applicationDidFinishLaunching();


    virtual void applicationDidEnterBackground();

    virtual void applicationWillEnterForeground();
};

#endif
