#include "CameraLesson3.h"

USING_NS_CC;

Scene* CameraLesson3::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CameraLesson3::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CameraLesson3::init()
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
                                           CC_CALLBACK_1(CameraLesson3::menuCloseCallback, this));
    
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

    // add "CameraLesson3" splash screen"
    
    //create Sprite3D
    std::string filename = "res/Sprite3D/orc.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition3D(Vec3(0, 0, -50.f));
    addChild(sprite);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::create(animation);
    sprite->runAction(RepeatForever::create(animate));
    
    auto camera = Camera::createPerspective(60, visibleSize.width / visibleSize.height, 1.f, 1000.f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0, 0, 10.f));
    camera->lookAt(Vec3(0, 0, 0));
    addChild(camera);
    
    sprite->setCameraMask((unsigned short)CameraFlag::USER1);
    
    return true;
}


void CameraLesson3::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
