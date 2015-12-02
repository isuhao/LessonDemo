#include "Sprite3DLesson2.h"

USING_NS_CC;

Scene* Sprite3DLesson2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Sprite3DLesson2::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Sprite3DLesson2::init()
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
                                           CC_CALLBACK_1(Sprite3DLesson2::menuCloseCallback, this));
    
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

    // add "Sprite3DLesson2" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    

    sprite->setScale(0.3f);
//    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    sprite->setGlobalZOrder(0);

    //create Sprite3D
    auto sprite3d = Sprite3D::create("res/Sprite3D/boss.obj");
    sprite3d->setTexture("res/Sprite3D/boss.png");
    sprite3d->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    addChild(sprite3d);
    sprite3d->setScale(10);
    
    auto action = RotateBy::create(3, 360);
    auto action_back = action->reverse();
    auto seq = Sequence::create( action, action_back, nullptr );
    sprite3d->runAction( RepeatForever::create(seq) );
    
    return true;
}


void Sprite3DLesson2::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
