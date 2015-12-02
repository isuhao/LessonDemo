#include "Sprite3DLesson6.h"

USING_NS_CC;

Scene* Sprite3DLesson6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Sprite3DLesson6::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Sprite3DLesson6::init()
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
                                           CC_CALLBACK_1(Sprite3DLesson6::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesEnded = CC_CALLBACK_2(Sprite3DLesson6::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    /////////////////////////////
    std::string filename = "res/Sprite3D/orc.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setScale(5);
    sprite->setScaleX(-5);
    sprite->setCullFace(GL_FRONT);
    addChild(sprite);
//
//    auto animation = Animation3D::create(filename);
//    auto animate = Animate3D::create(animation);
//    sprite->runAction(RepeatForever::create(animate));
//    
//    auto sp = Sprite3D::create("res/Sprite3D/axe.c3b");
//    
//    auto node = sprite->getAttachNode("Bip001 L Hand");
//    node->addChild(sp);
//    sp->setRotation3D(Vec3(0, 90, 0));
    
//    auto girl = Sprite3D::create("res/Sprite3D/reskin/ReskinGirl.c3b");
//    girl->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/4 + origin.y);
//    girl->setScale(5);
//    addChild(girl);
//    
//    girl->getMeshByName("Girl_LowerBody01")->setVisible(false);
//    girl->getMeshByName("Girl_UpperBody02")->setVisible(false);
    
    return true;
}

void Sprite3DLesson6::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    
}

void Sprite3DLesson6::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
