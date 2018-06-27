#include "mainmenu.h"

Scene* mainmenu::createScene()
{

    auto scene = Scene::create();
    

    auto layer = mainmenu::create();


    scene->addChild(layer);


    return scene;
}


bool mainmenu::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto gameBkGround = LayerColor::create(Color4B(144, 136, 128, 255));
    this->addChild(gameBkGround);




	MenuItemFont::setFontName("MarkerFelt-Thin");
	MenuItemFont::setFontSize(visibleSize.width/7);
	MenuItemFont * item1 = MenuItemFont::create("START",CC_CALLBACK_1(mainmenu::menuItem1Callback,this));
	MenuItemFont * item2 = MenuItemFont::create("SETTING",CC_CALLBACK_1(mainmenu::menuItem2Callback,this));
	MenuItemFont * item3 = MenuItemFont::create("RANKING LIST",CC_CALLBACK_1(mainmenu::menuItem3Callback,this));
	MenuItemFont * itemc = MenuItemFont::create("CLOSE",CC_CALLBACK_1(mainmenu::menuCloseCallback,this));
	Menu * mn = Menu::create(item1,item2,item3,itemc,NULL);
	mn->setPosition(Vec2(visibleSize.width/2,
		                 visibleSize.height/2/1.1));
	mn->alignItemsVertically();
	this->addChild(mn,2);


	auto label = LabelTTF::create("2048", "MarkerFelt-Thin", visibleSize.width/4);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height*1.5/2));
    this->addChild(label, 1);


    
    return true;
}
void mainmenu::menuItem1Callback(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto gs = gamescene::createScene();
	Director::getInstance()->replaceScene(gs);
}
void mainmenu::menuItem2Callback(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void mainmenu::menuItem3Callback(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto mw = rankinglist::createScene();
	Director::getInstance()->replaceScene(mw);
}
void mainmenu::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
