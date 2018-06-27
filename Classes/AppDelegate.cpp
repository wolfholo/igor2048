#include "AppDelegate.h"


AppDelegate::AppDelegate() 
{

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() 
{

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
		glview ->setFrameSize(480,720);
        director->setOpenGLView(glview);
    }


    director->setDisplayStats(true);

    director->setAnimationInterval(1.0 / 60);

    auto scene = mainmenu::createScene();

    director->runWithScene(scene);

    return true;
}


void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();


}


void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();


}
