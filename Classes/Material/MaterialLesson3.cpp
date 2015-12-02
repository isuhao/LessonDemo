#include "MaterialLesson3.h"

USING_NS_CC;

Scene* MaterialLesson3::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MaterialLesson3::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MaterialLesson3::init()
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
                                           CC_CALLBACK_1(MaterialLesson3::menuCloseCallback, this));
    
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
    std::string filename = "res/Sprite3D/boss.obj";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setScale(5);
    sprite->setRotation3D(Vec3(0, 0, 90));
    sprite->setTexture("res/Sprite3D/boss.png");
    addChild(sprite);
    
    auto program = GLProgram::createWithFilenames("res/Material/simple.vert", "res/Material/simple.frag");
    
    for (ssize_t i = 0; i < sprite->getMeshCount(); i++) {
        auto programState = GLProgramState::create(program);
        auto mesh = sprite->getMeshByIndex(i);
        long offset = 0;
        for (int j = 0; j <  mesh->getMeshVertexAttribCount(); j++) {
            auto meshattribute = mesh->getMeshVertexAttribute(j);
            programState->setVertexAttribPointer(s_attributeNames[meshattribute.vertexAttrib],
                                               meshattribute.size,
                                               meshattribute.type,
                                               GL_FALSE,
                                               mesh->getVertexSizeInBytes(),
                                               (GLvoid*)offset);
            offset += meshattribute.attribSizeBytes;
        }
        programState->setUniformVec4("u_color2", Vec4(1.f, 0.f, 0.f, 1.f));
        sprite->setGLProgramState(programState);
    }
    
    return true;
}


void MaterialLesson3::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
