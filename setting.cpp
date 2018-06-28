#include "setting.h"

int mode=1;
int order=3;
int probaility=10;
int iquantity=1;
float size=0.9f;

Scene* setting::createScene()
{

	auto scene = Scene::create();

	auto layer = setting::create();

	scene->addChild(layer);

	return scene;
}

bool setting::init()
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
	MenuItemFont::setFontSize(visibleSize.width/6);
	MenuItemFont * itemb = MenuItemFont::create("BACK",CC_CALLBACK_1(setting::menubackCallback,this));
	Menu * mn = Menu::create(itemb,NULL);
	mn->setPosition(Vec2(origin.x + visibleSize.width - itemb->getContentSize().width/2,
		origin.y + itemb->getContentSize().height/2));
	mn->alignItemsVertically();
	this->addChild(mn,2);

	auto label1 = LabelTTF::create("MODE", "MarkerFelt-Thin", visibleSize.width/7);
	label1->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label1->getContentSize().height/2));
	this->addChild(label1, 1);
	auto numl = cocos2d::LabelTTF::create(__String::createWithFormat("%i", mode)->getCString(), "MarkerFelt-Thin", visibleSize.width/7);  
	numl->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label1->getContentSize().height*1.5));  
	this->addChild(numl); 
	auto label2 = LabelTTF::create("ORDER", "MarkerFelt-Thin", visibleSize.width/7);
	label2->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*4 - label2->getContentSize().height/2));
	this->addChild(label2, 1);
	auto num2 = cocos2d::LabelTTF::create(__String::createWithFormat("%i", order)->getCString(), "MarkerFelt-Thin", visibleSize.width/7);  
	num2->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*4 - label1->getContentSize().height*1.5));  
	this->addChild(num2); 
	auto label3 = LabelTTF::create("QUALITY", "MarkerFelt-Thin", visibleSize.width/7);
	label3->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*3 - label3->getContentSize().height/2));
	this->addChild(label3, 1);
	auto num3 = cocos2d::LabelTTF::create(__String::createWithFormat("%i%%", probaility)->getCString(), "MarkerFelt-Thin", visibleSize.width/7);  
	num3->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*3 - label1->getContentSize().height*1.5));  
	this->addChild(num3); 
	auto label4 = LabelTTF::create("QUANTITY", "MarkerFelt-Thin", visibleSize.width/7);
	label4->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*2 - label4->getContentSize().height/2));
	this->addChild(label4, 1);
	auto num4 = cocos2d::LabelTTF::create(__String::createWithFormat("%i", iquantity)->getCString(), "MarkerFelt-Thin", visibleSize.width/7);  
	num4->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/5*2 - label1->getContentSize().height*1.5));  
	this->addChild(num4); 


	MenuItemFont::setFontName("MarkerFelt-Thin");
	MenuItemFont::setFontSize(visibleSize.width/7);
	MenuItemFont * item1 = MenuItemFont::create("-",CC_CALLBACK_1(setting::modem,this));
	MenuItemFont * item2 = MenuItemFont::create("-",CC_CALLBACK_1(setting::orderm,this));
	MenuItemFont * item3 = MenuItemFont::create("-",CC_CALLBACK_1(setting::probailitym,this));
	MenuItemFont * item4 = MenuItemFont::create("-",CC_CALLBACK_1(setting::sizem,this));
	Menu * minus = Menu::create(item1,item2,item3,item4,NULL);

	minus->setPosition(Vec2(visibleSize.width/4,
		                 visibleSize.height/2*1.1));
	minus->alignItemsVerticallyWithPadding(visibleSize.height/5-item1->getContentSize().height);
    this->addChild(minus,2);


	MenuItemFont * item5 = MenuItemFont::create("+",CC_CALLBACK_1(setting::modep,this));
	MenuItemFont * item6 = MenuItemFont::create("+",CC_CALLBACK_1(setting::orderp,this));
	MenuItemFont * item7 = MenuItemFont::create("+",CC_CALLBACK_1(setting::probailityp,this));
	MenuItemFont * item8 = MenuItemFont::create("+",CC_CALLBACK_1(setting::sizep,this));
	Menu * plus = Menu::create(item5,item6,item7,item8,NULL);

	plus->setPosition(Vec2(visibleSize.width/4*3,
		                 visibleSize.height/2*1.1));
	plus->alignItemsVerticallyWithPadding(visibleSize.height/5-item5->getContentSize().height);
	this->addChild(plus,2);

	return true;
}
void setting::menubackCallback(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto hw = mainmenu::createScene();
	Director::getInstance()->replaceScene(hw);
}

void setting::modem(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(mode==2)
	{
	mode--;
	}
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::orderm(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(order>2)
	order--;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::probailitym(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(probaility>=5)
	probaility-=5;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::sizem(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(iquantity>1)
	iquantity--;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::modep(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(mode==1)
	mode++;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);

}
void setting::orderp(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	
	order++;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::probailityp(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(probaility<=95)
	probaility+=5;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
void setting::sizep(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	if(iquantity<order)
	iquantity++;
		auto mw = setting::createScene();
	Director::getInstance()->replaceScene(mw);
}
