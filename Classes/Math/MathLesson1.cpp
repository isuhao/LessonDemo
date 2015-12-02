#include "MathLesson1.h"

USING_NS_CC;

Scene* MathLesson1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MathLesson1::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MathLesson1::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MathLesson1::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    // add "MathLesson1" splash screen"
    
    //create Sprite3D
    std::string filename = "res/Sprite3D/orc.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setScale(5);
    sprite->setRotation3D(Vec3(0, 0, 90));
    addChild(sprite);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::create(animation);
    sprite->runAction(RepeatForever::create(animate));
    
    return true;
}


void MathLesson1::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
