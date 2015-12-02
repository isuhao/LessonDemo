#include "Sprite3DLesson4.h"

USING_NS_CC;

Scene* Sprite3DLesson4::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Sprite3DLesson4::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Sprite3DLesson4::init()
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
                                           CC_CALLBACK_1(Sprite3DLesson4::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesEnded = CC_CALLBACK_2(Sprite3DLesson4::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    /////////////////////////////
//    std::string filename = "res/Sprite3D/orc.c3b";
//    auto sprite = Sprite3D::create(filename);
//    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
//    sprite->setScale(5);
//    addChild(sprite);
//    
//    auto animation = Animation3D::create(filename);
//    auto animate = Animate3D::create(animation);
//    sprite->runAction(RepeatForever::create(animate));
    
    std::string filename = "res/Sprite3D/tortoise.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setScale(0.1);
    sprite->setRotation3D(Vec3(0, 180, 0));
    addChild(sprite);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::createWithFrames(animation, 0, 57);
    animate->setQuality(Animate3DQuality::QUALITY_LOW);
    sprite->runAction(RepeatForever::create(animate));
    _sprite = sprite;
    
    return true;
}

void Sprite3DLesson4::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    _sprite->stopActionByTag(100);
    
    std::string filename = "res/Sprite3D/tortoise.c3b";
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::create(animation, 1.933f, 2.8f);
    Animate3D::setTransitionTime(0.2f);
    animate->setTag(100);
    _sprite->runAction(animate);
}

void Sprite3DLesson4::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
