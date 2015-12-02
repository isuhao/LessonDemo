#include "MathLesson4.h"

USING_NS_CC;

Scene* MathLesson4::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MathLesson4::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MathLesson4::init()
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
                                           CC_CALLBACK_1(MathLesson4::menuCloseCallback, this));
    
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

    std::string filename = "res/Sprite3D/tortoise.c3b";
    auto sprite = Sprite3D::create(filename);
    sprite->setPosition(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y);
    sprite->setScale(0.05);
//    sprite->setRotation3D(Vec3(0, 180, 0));
    addChild(sprite);
    
    auto animation = Animation3D::create(filename);
    auto animate = Animate3D::createWithFrames(animation, 0, 57);
    animate->setQuality(Animate3DQuality::QUALITY_LOW);
    sprite->runAction(RepeatForever::create(animate));
    _sprite = sprite;
    
    // control point
    
    float step = visibleSize.width * 0.2f;
    Vec3 p;
    p.x = step * 0.5f;
    p.y = visibleSize.height*0.2f;
    _controlPts.push_back(p);
    
    p.x+= step;
    p.y = visibleSize.height*0.8f;
    _controlPts.push_back(p);
    
    p.x += step;
    p.y = visibleSize.height*0.2f;
    _controlPts.push_back(p);
    
    p.x += step;
    p.y = visibleSize.height*0.8f;
    _controlPts.push_back(p);
    
    p.x += step;
    p.y =visibleSize.height*0.2f;
    _controlPts.push_back(p);
    
    
    
    _t = 0.f;
    _idx = 2;
    
    scheduleUpdate();
    
    return true;
}

void MathLesson4::update(float delta)
{
    _t += delta * 0.5f;
    if (_t > 1.f)
    {
        _idx++;
        if (_idx > 4)
            _idx = 2;
        _t -= 1.f;
    }
    Vec3 pt = getInterpolatedPt(_controlPts[_idx-2], _controlPts[_idx-1], _controlPts[_idx], _t);
    //切线
    Vec3 ptDiff = -getInterpolatedPtDiff(_controlPts[_idx-2], _controlPts[_idx-1], _controlPts[_idx], _t);
    ptDiff.normalize();
    //法线
    Vec3 fakenormal = (_controlPts[_idx-1] - _controlPts[_idx-2]) + (_controlPts[_idx-1] - _controlPts[_idx]);
    fakenormal.normalize();
    Vec3 z;
    Vec3::cross(ptDiff, fakenormal, &z);
    Vec3::cross(z, ptDiff, &fakenormal);
    
    Mat4 mat;
    mat.m[0] = ptDiff.x; mat.m[1] = ptDiff.y; mat.m[2] = ptDiff.z;
    mat.m[4] = fakenormal.x; mat.m[5] = fakenormal.y; mat.m[6] = fakenormal.z;
    mat.m[8] = z.x; mat.m[9] = z.y; mat.m[10] = z.z;
    
    Quaternion quat, oldQuat;
    Quaternion::createFromRotationMatrix(mat, &quat);
    oldQuat = _sprite->getRotationQuat();
    Quaternion::slerp(oldQuat, quat, 0.1f, &quat);
    _sprite->setRotationQuat(quat);
    _sprite->setPosition3D(pt);
}

cocos2d::Vec3 MathLesson4::getInterpolatedPt(const cocos2d::Vec3& p0, const cocos2d::Vec3& p1, const cocos2d::Vec3& p2, float t)
{
    CCASSERT(t >=0.f && t <= 1.f, "");
    float t2 = t * t;
    return p0*((1.f - 2.f*t + t2) * 0.5f) + p1 * ((1.f+2.f*t-2.f*t2)*0.5f) + p2 * (t2 * 0.5f);
}

cocos2d::Vec3 MathLesson4::getInterpolatedPtDiff(const cocos2d::Vec3& p0, const cocos2d::Vec3& p1, const cocos2d::Vec3& p2, float t)
{
    CCASSERT(t >=0.f && t <= 1.f, "");
    return p0*(t - 1.f) + p1 * (1.f-2.f * t) + p2 * (t);
}

void MathLesson4::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
