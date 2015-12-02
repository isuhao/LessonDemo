#include "Sprite3DLesson5.h"
#include "base/CCEventListenerCustom.h"

USING_NS_CC;

Scene* Sprite3DLesson5::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Sprite3DLesson5::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Sprite3DLesson5::init()
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
                                           CC_CALLBACK_1(Sprite3DLesson5::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesEnded = CC_CALLBACK_2(Sprite3DLesson5::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    /////////////////////////////
    std::string filename = "res/Sprite3D/girl.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/3 + origin.y);
    addChild(sprite);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::create(animation);
    sprite->runAction(RepeatForever::create(animate));
    
    auto lfoot = Sprite::create("res/Sprite3D/circle.png");
    auto rfoot = Sprite::create("res/Sprite3D/circle.png");
    _lfoot = Sprite3D::create();
    _lfoot->addChild(lfoot);
    _lfoot->setRotation3D(Vec3(90, 0, 0));
    _rfoot = Sprite3D::create();
    _rfoot->addChild(rfoot);
    _rfoot->setRotation3D(Vec3(90, 0, 0));
    
    addChild(_lfoot);
    addChild(_rfoot);
    _lfoot->setScale(0.3f);
    _rfoot->setScale(0.3f);
    _lfoot->setVisible(false);
    _rfoot->setVisible(false);
    
    _sprite = sprite;
    
    ValueMap valuemap0;
    valuemap0["footname"] = Value("Bip001 R Toe0");
    valuemap0["lfoot"] = Value(false);
    animate->setKeyFrameUserInfo(10, valuemap0);
    valuemap0["footname"] = Value("Bip001 L Toe0");
    valuemap0["lfoot"] = Value(true);
    animate->setKeyFrameUserInfo(26, valuemap0);
    auto listener2 = EventListenerCustom::create(Animate3DDisplayedNotification, [&](EventCustom* event)
    {
        auto info = (Animate3D::Animate3DDisplayedEventInfo*)event->getUserData();
        auto footname = info->userInfo->at("footname").asString();
        bool lfoot = info->userInfo->at("lfoot").asBool();
        auto mat = _sprite->getNodeToWorldTransform() * _sprite->getSkeleton()->getBoneByName(footname)->getWorldMat();
        Sprite3D* foot = lfoot ? _lfoot : _rfoot;
        foot->setPosition3D(Vec3(mat.m[12], mat.m[13], mat.m[14]));
        foot->setVisible(true);
        cocos2d::log("frame %d", info->frame);
    });
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener2, -1);
    
    scheduleUpdate();
    return true;
}

void Sprite3DLesson5::update(float delta)
{
    static float accAngle = 0.f;
    accAngle += delta * CC_DEGREES_TO_RADIANS(60);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float radius = 50.f;
    Vec3 center(visibleSize.width / 2.f + origin.x, visibleSize.height / 4.f + origin.y, 0);
    float x = cosf(accAngle) * radius + center.x, z = sinf(accAngle) * radius + center.z;
    
    _sprite->setPosition3D(Vec3(x, center.y, z));
}

void Sprite3DLesson5::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    
}

void Sprite3DLesson5::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
