#include "CameraLesson6.h"

USING_NS_CC;

Scene* CameraLesson6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CameraLesson6::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CameraLesson6::init()
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
                                           CC_CALLBACK_1(CameraLesson6::menuCloseCallback, this));
    
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

    // add "CameraLesson6" splash screen"
    
    auto sizeInpixels = Director::getInstance()->getWinSizeInPixels();
    auto size = Director::getInstance()->getWinSize();
    auto fboSize = Size(sizeInpixels.width * 1, sizeInpixels.height * 1.5);
    auto fbo = experimental::FrameBuffer::create(1, fboSize.width, fboSize.height);
    
    auto rt = experimental::RenderTarget::create(fboSize.width, fboSize.height);
    auto rtDS = experimental::RenderTargetDepthStencil::create(fboSize.width, fboSize.height);
    fbo->attachRenderTarget(rt);
    fbo->attachDepthStencilTarget(rtDS);
    auto sprite = Sprite::createWithTexture(fbo->getRenderTarget()->getTexture());
    sprite->setScale(0.3);
    sprite->runAction(RepeatForever::create(RotateBy::create(1, 90)));
    sprite->setPosition(size.width/2, size.height/2);
    addChild(sprite);
    
    auto camera = Camera::createPerspective(60, visibleSize.width / visibleSize.height, 1.f, 1000.f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0, 0, 10));
    camera->setFrameBufferObject(fbo);
    fbo->setClearColor(Color4F(1,1,1,1));
    addChild(camera);
    
    //create Sprite3D
    std::string filename = "res/Sprite3D/orc.c3b";
    auto sprite2 = Sprite3D::create(filename);
    sprite2->setPosition3D(Vec3(0, 0, -10.f));
    addChild(sprite2);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::create(animation);
    sprite2->runAction(RepeatForever::create(animate));
    
    sprite2->setCameraMask((unsigned short)CameraFlag::USER1);
    
    return true;
}

void CameraLesson6::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    
}

void CameraLesson6::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
