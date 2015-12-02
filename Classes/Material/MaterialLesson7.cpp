#include "MaterialLesson7.h"

USING_NS_CC;

Scene* MaterialLesson7::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MaterialLesson7::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MaterialLesson7::init()
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
                                           CC_CALLBACK_1(MaterialLesson7::menuCloseCallback, this));
    
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
    std::string filename = "res/Material/teapot.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    addChild(sprite);
    sprite->setScale(10);
    sprite->setRotation3D(Vec3(-90, 0, 0));
    auto material = Material::createWithFilename("res/Material/toon.material");
    sprite->setMaterial(material);
    
    return true;
}


void MaterialLesson7::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
