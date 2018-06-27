#include "rankinglist.h"


Scene* rankinglist::createScene()
{

	auto scene = Scene::create();

	auto layer = rankinglist::create();

	scene->addChild(layer);

	return scene;
}

bool rankinglist::init()
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
	MenuItemFont * item1 = MenuItemFont::create("BACK",CC_CALLBACK_1(rankinglist::back,this));
	Menu * mn = Menu::create(item1,NULL);
	mn->setPosition(Vec2(origin.x + visibleSize.width - item1->getContentSize().width/2,
		origin.y + item1->getContentSize().height/2));
	this->addChild(mn,1);

	auto label0 = LabelTTF::create("RANKING LIST", "MarkerFelt-Thin", visibleSize.width/7);
	label0->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label0->getContentSize().height/2));
	this->addChild(label0, 1);

	int scorer[10];
	LabelTTF *label[10];
	std::string sscore[10];

	for (int i = 0; i < 9; ++i)  
	{   
		CCString* getScore = CCString::createWithFormat("a_%d",i);  
		scorer[i] = CCUserDefault::sharedUserDefault()->getIntegerForKey(getScore->getCString()); 
		sscore[i] = __String::createWithFormat("%i-------%i", i+1,scorer[i])->getCString();
		label[i] = LabelTTF::create( sscore[i], "MarkerFelt-Thin", visibleSize.width/7);
		label[i]->setPosition(Vec2(origin.x + visibleSize.width*0.07+label[i]->getContentSize().width/2,
			origin.y + visibleSize.height*(12-i)/13 - label[i]->getContentSize().height));
		this->addChild(label[i], 1);
	}  

	CCString* getScore = CCString::createWithFormat("a_%d",9);  
	scorer[9] = CCUserDefault::sharedUserDefault()->getIntegerForKey(getScore->getCString()); 
	sscore[9] = __String::createWithFormat("%i------%i", 10,scorer[9])->getCString();
	label[9] = LabelTTF::create( sscore[9], "MarkerFelt-Thin", visibleSize.width/7);
	label[9]->setPosition(Vec2(origin.x + visibleSize.width*0.07+label[9]->getContentSize().width/2,
		origin.y + visibleSize.height*(12-9)/13 - label[9]->getContentSize().height));
	this->addChild(label[9], 1);








	return true;
}
void rankinglist::back(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	auto hw = mainmenu::createScene();
	Director::getInstance()->replaceScene(hw);
}
