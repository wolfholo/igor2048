#include "gamescene.h"

#define CC_PLATFORM_IOS                1
#define CC_PLATFORM_ANDROID            2
#define CC_PLATFORM_WIN32              3



Scene* gamescene::createScene()
{

	auto scene = Scene::create();

	auto layer = gamescene::create();

	scene->addChild(layer);

	return scene;
}

bool gamescene::init()
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
	MenuItemFont * item1 = MenuItemFont::create("BACK",CC_CALLBACK_1(gamescene::back,this));
	Menu * mn = Menu::create(item1,NULL);
	mn->setPosition(Vec2(origin.x + visibleSize.width - item1->getContentSize().width/2,
		origin.y + item1->getContentSize().height/2));
	this->addChild(mn,1);

	auto a1 = Sprite::create();


	mult=order;////////////////////////////////////////////////////////
	ssize=size;
	squareg=probaility;

	srand(time(0));
	squareSize = visibleSize.width *0.95f/ mult;
	auto snumbern = LabelTTF::create("score:","MarkerFelt-Thin", visibleSize.width/10);  
	snumbern->setPosition(visibleSize.width/2 - snumbern->getContentSize().width, 
		visibleSize.height*0.95 - snumbern->getContentSize().height/2);  
	addChild(snumbern);
	score=0;
	snumber = LabelTTF::create("0", "MarkerFelt-Thin", visibleSize.width/10);  
	snumber->setPosition(visibleSize.width/2*1.1 + snumber->getContentSize().width, 
		visibleSize.height*0.95 - snumber->getContentSize().height/2);  
	addChild(snumber);




	createsquare(visibleSize);  

	// 调用生成随机数  
	autoCreatesquareNumber();  
	autoCreatesquareNumber(); 

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(gamescene::keyPressed, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(gamescene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(gamescene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void gamescene::keyPressed(EventKeyboard::KeyCode keyCode,Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		if(doUp())
		{  
			autoCreatesquareNumber();  
			CheckGameOver(); 

		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		if(doLeft())
		{  
			autoCreatesquareNumber();
			CheckGameOver(); 

		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		if(doRight())
		{  
			autoCreatesquareNumber(); 
			CheckGameOver(); 

		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		if(doDown())
		{  
			autoCreatesquareNumber();  
			CheckGameOver(); 

		}
	}

}

bool gamescene::onTouchBegan(Touch *touch, Event *event)
{
	gettimeofday(&tv, NULL);
	startPt = touch->getLocation();

	return true;
}

void gamescene::onTouchEnded(Touch *touch, Event *event)
{
	timeval tv_end;
	gettimeofday(&tv_end, NULL);


	auto endPt = touch->getLocation();
	offsetX = endPt.x - startPt.x;
	offsetY = endPt.y - startPt.y;
	bool isTouch = false; 

//	if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) 
//	{
		if (abs(offsetX) > abs(offsetY))
		{
			if (offsetX < -5)
				isTouch = doLeft();
			else if (offsetX > 5)
				isTouch = doRight();
		}
		else
		{
			if (offsetY <-5 )
				isTouch = doDown();
			else if (offsetY>5)
				isTouch = doUp();
		}
//	}
//	else if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	{
//
//		if (abs(offsetX) > abs(offsetY))
//		{
//			if (offsetX < -5)
//				isTouch = doLeft();
//			else if (offsetX > 5)
//				isTouch = doRight();
//		}
//		else
//		{
//			if (offsetY > 5)
//				isTouch = doDown();
//			else if (offsetY<-5)
//				isTouch = doUp();
//		}
//	}
	if (isTouch)
	{

		autoCreatesquareNumber();
		CheckGameOver();
	}
}

void gamescene::back(Ref* pSender)
{
	MenuItem * item = (MenuItem*)pSender;
	int scorer[11];
	scorer[10]=score;
	for (int i = 0; i < 10; ++i)  
	{   
		CCString* getScore = CCString::createWithFormat("a_%d",i);  
		scorer[i] = CCUserDefault::sharedUserDefault()->getIntegerForKey(getScore->getCString());  
	}  

	for (int i =1;i < 11;++i)
	{
		for(int j = i;j > 0;--j)
		{
			if(scorer[j] > scorer[j -1])
			{
				int temp = scorer[j];
				scorer[j] = scorer[j - 1];
				scorer[j - 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)  
	{  
		CCString* setScore = CCString::createWithFormat("a_%d",i);  
		CCUserDefault::sharedUserDefault()->setIntegerForKey(setScore->getCString(), scorer[i]);         
	}  
	CCUserDefault::sharedUserDefault()->flush();

	auto hl = mainmenu::createScene();
	Director::getInstance()->replaceScene(hl);
}

void gamescene::autoCreatesquareNumber() 
{  

	int i = rand()%mult;  
	int j = rand()%mult;  

	if (squareArr[i][j]->getn() > 0) 
	{  
		autoCreatesquareNumber();  
	} 
	else 
	{  
		// 生成2和4的比例
		squareArr[i][j]->setn(CCRANDOM_0_1() * 100 <= squareg ? 2:1);  

		auto action = Sequence::createWithTwoActions(ScaleTo::create(0, 0), ScaleTo::create(0.3f, 1));

		squareArr[i][j]->getsquarecolor()->runAction(action);
	}  
}  

void gamescene::createsquare(cocos2d::Size size) 
{  

	squareArr  =  new square** [mult];
	for(int i = 0; i < mult; i++)
		squareArr[i] = new square* [mult];

	squareArrAction  =  new square** [mult];
	for(int i = 0; i < mult; i++)
		squareArrAction[i] = new square* [mult];

	for (int x = 0; x < mult; x++) 
	{  
		for (int y = 0; y < mult; y++) 
		{  
			square *square = square::create(0, squareSize*ssize, 
				squareSize*(((1-ssize)-mult)/2+x)+size.width/2 , 
				squareSize*(((1-ssize)-mult)/2+y)+size.height/2);  
			addChild(square,0);  

			squareArr[x][y] = square;  
		}  
	}  
	for (int x = 0; x < mult; x++)  
	{  
		for (int y = 0; y < mult; y++)  
		{  

			square *square = square::create(0, squareSize*ssize, 
				squareSize*(((1-ssize)-mult)/2+x)+size.width/2 , 
				squareSize*(((1-ssize)-mult)/2+y)+size.height/2);  

			this->addChild(square);  
			squareArrAction[x][y] = square;  
			//
			auto hide = Hide::create();  
			squareArrAction[x][y]->getsquarecolor()->runAction(hide);  
		}  
	}  
} 

bool gamescene::doLeft()
{  
	bool isdo = false;  

	for (int y = 0; y < mult; y++) 
	{  
		for (int x = 0; x < mult; x++) 
		{  
			for (int x1 = x + 1; x1 < mult; x1++) 
			{  
				if (squareArr[x1][y]->getn() > 0) 
				{ 
					if (squareArr[x][y]->getn() == 0) 
					{
						visibleSize = Director::getInstance()->getVisibleSize();
						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x1)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y)+visibleSize.height/2));  
						squareArrAction[x1][y]->setn(squareArr[x1][y]->getn());
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(-squareSize*(x1 - x), 0)); 
						auto hide = Hide::create();  
						squareArrAction[x1][y]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));
						squareArr[x][y]->setn(squareArr[x1][y]->getn());




						squareArr[x1][y]->setn(0);  


						x--;  
						isdo = true;  

					} 
					else if(squareArr[x][y]->getn() == squareArr[x1][y]->getn()) 
					{  

						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x1)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y)+visibleSize.height/2));  
						squareArrAction[x1][y]->setn(squareArr[x1][y]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(-squareSize*(x1 - x), 0));  
						auto hide = Hide::create();  
						squareArrAction[x1][y]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL)); 


						squareArr[x1][y]->setn(0);  

						auto merge = Sequence::create(ScaleTo::create(0.1f,  2/ssize-1), ScaleTo::create(0.1f, 1.0f), NULL);

						squareArr[x][y]->setn(squareArr[x][y]->getn()+1);

						squareArr[x][y]->getsquarecolor()->runAction(merge);
						score += pow(2,squareArr[x][y]->getn());  
						snumber->setString(__String::createWithFormat("%i", score)->getCString());  

						isdo = true;  
					}  
					break;
				}  
			}  
		}  
	}  

	return isdo;  
}  
bool gamescene::doRight()
{  
	bool isdo = false;  

	for (int y = 0; y < mult; y++) 
	{  
		for (int x = mult-1; x >= 0; x--) 
		{  
			for (int x1 = x - 1; x1 >= 0; x1-- ) 
			{  
				if (squareArr[x1][y]->getn() > 0) 
				{  
					if (squareArr[x][y]->getn() == 0) 
					{  
						visibleSize = Director::getInstance()->getVisibleSize();
						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x1)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y)+visibleSize.height/2));  
						squareArrAction[x1][y]->setn(squareArr[x1][y]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(-squareSize*(x1 - x), 0));
						auto hide = Hide::create();  
						squareArrAction[x1][y]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL)); 
						squareArr[x][y]->setn(squareArr[x1][y]->getn()); 
						squareArr[x1][y]->setn(0);
						x++;  
						isdo = true;  
					}  
					else if (squareArr[x][y]->getn() == squareArr[x1][y]->getn()) 
					{  
						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x1)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y)+visibleSize.height/2));  
						squareArrAction[x1][y]->setn(squareArr[x1][y]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(-squareSize*(x1 - x), 0));
						auto hide = Hide::create();  
						squareArrAction[x1][y]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));  

						squareArr[x1][y]->setn(0);  

						auto merge = Sequence::create(ScaleTo::create(0.1f, 2/ssize-1), ScaleTo::create(0.1f, 1.0f), NULL);  

						squareArr[x][y]->setn(squareArr[x][y]->getn()+1);
						squareArr[x][y]->getsquarecolor()->runAction(merge);

						squareArr[x1][y]->setn(0);  
						score += pow(2,squareArr[x][y]->getn()); 

						snumber->setString(__String::createWithFormat("%i", score)->getCString());  

						isdo = true;  
					}  
					break;  
				}  

			}  
		}  

	}  

	return isdo;  

}  
bool gamescene::doUp()
{  
	bool isdo = false;  

	for (int x = 0; x < mult; x++) 
	{  
		for (int y = mult-1; y >= 0; y--) 
		{  
			for (int y1 = y - 1; y1 >= 0; y1--) 
			{  
				if (squareArr[x][y1]->getn() > 0) 
				{
					if (squareArr[x][y]->getn() <= 0) 
					{
						visibleSize = Director::getInstance()->getVisibleSize();
						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y1)+visibleSize.height/2));  
						squareArrAction[x][y1]->setn(squareArr[x][y1]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(0 ,- squareSize*(y1 - y))); 
						auto hide = Hide::create();  
						squareArrAction[x][y1]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));
						squareArr[x][y]->setn(squareArr[x][y1]->getn());  
						squareArr[x][y1]->setn(0);  

						y++;  
						isdo = true;  

					} else if(squareArr[x][y]->getn() == squareArr[x][y1]->getn()) 
					{  

						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y1)+visibleSize.height/2));  
						squareArrAction[x][y1]->setn(squareArr[x][y1]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(0, -squareSize*(y1 - y)));
						auto hide = Hide::create();  
						squareArrAction[x][y1]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));  



						squareArr[x][y1]->setn(0);  

						auto merge = Sequence::create(ScaleTo::create(0.1f,  2/ssize-1), ScaleTo::create(0.1f, 1.0f), NULL); 

						squareArr[x][y]->setn(squareArr[x][y]->getn()+1);
						squareArr[x][y]->getsquarecolor()->runAction(merge);
						score += pow(2,squareArr[x][y]->getn());  
						snumber->setString(__String::createWithFormat("%i", score)->getCString());  

						isdo = true;  
					}  
					break;
				}  
			}  
		}  
	}  

	return isdo;  

}  
bool gamescene::doDown()
{  
	bool isdo = false;  

	for (int x = 0; x < mult; x++) 
	{  
		for (int y = 0; y < mult; y++) 
		{    
			for (int y1 = y + 1; y1 < mult; y1++) 
			{  
				if (squareArr[x][y1]->getn() > 0) 
				{
					if (squareArr[x][y]->getn() <= 0) 
					{
						visibleSize = Director::getInstance()->getVisibleSize();
						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y1)+visibleSize.height/2));  
						squareArrAction[x][y1]->setn(squareArr[x][y1]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(0, -squareSize*(y1 - y)));
						auto hide = Hide::create();  
						squareArrAction[x][y1]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));  


						squareArr[x][y]->setn(squareArr[x][y1]->getn());  
						squareArr[x][y1]->setn(0);  


						y--;  
						isdo = true;  

					} else if(squareArr[x][y]->getn() == squareArr[x][y1]->getn()) 
					{  

						auto place = Place::create(Point(squareSize*(((1-ssize)-mult)/2+x)+visibleSize.width/2 , 
							squareSize*(((1-ssize)-mult)/2+y1)+visibleSize.height/2));  
						squareArrAction[x][y1]->setn(squareArr[x][y1]->getn());  
						auto show = Show::create();  
						auto move = MoveBy::create(0.1f, Point(0, -squareSize*(y1 - y))); 
						auto hide = Hide::create();  
						squareArrAction[x][y1]->getsquarecolor()->runAction(Sequence::create(place, show, move, hide, NULL));  



						squareArr[x][y1]->setn(0);  

						auto merge = Sequence::create(ScaleTo::create(0.1f,  2/ssize-1), ScaleTo::create(0.1f, 1.0f), NULL); 

						squareArr[x][y]->setn(squareArr[x][y]->getn()+1);
						squareArr[x][y]->getsquarecolor()->runAction(merge);
						score += pow(2,squareArr[x][y]->getn());  
						snumber->setString(__String::createWithFormat("%i", score)->getCString());  
						isdo = true;  
					}  
					break;
				}  
			}  
		}  
	}  

	return isdo;  
}  

void gamescene::CheckGameOver() 
{  
	bool isGameOver = true;  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	for (int y = 0; y < mult; y++) 
	{  
		for (int x = 0; x < mult; x++) 
		{  
			if (squareArr[x][y]->getn() == 0  
				|| (x>0 && (squareArr[x][y]->getn() == squareArr[x-1][y]->getn()))  
				|| (x<mult-1 && (squareArr[x][y]->getn() == squareArr[x+1][y]->getn()))  
				|| (y>0 && (squareArr[x][y]->getn() == squareArr[x][y-1]->getn()))  
				|| (y<mult-1 && (squareArr[x][y]->getn() == squareArr[x][y+1]->getn()))) 
			{  
				isGameOver = false;
			}  
		}  
	}  

	if (isGameOver) 
	{  
		

		auto label1 = LabelTTF::create("GG", "MarkerFelt-Thin", visibleSize.width/5);
		label1->setPosition(Vec2(origin.x + visibleSize.width/2,
			origin.y +   label1->getContentSize().height*0.8));
		this->addChild(label1, 1);



	}  

}  
