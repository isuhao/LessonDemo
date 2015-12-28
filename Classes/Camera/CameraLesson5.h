#ifndef __CAMERA_LESSON5_SCENE_H__
#define __CAMERA_LESSON5_SCENE_H__

#include "cocos2d.h"

class CameraLesson5 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CameraLesson5);
    
protected:
    cocos2d::Camera* _camera;
};

#endif // __CAMERA_LESSON5_SCENE_H__
