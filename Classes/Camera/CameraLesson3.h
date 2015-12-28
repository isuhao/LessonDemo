#ifndef __CAMERA_LESSON3_SCENE_H__
#define __CAMERA_LESSON3_SCENE_H__

#include "cocos2d.h"

class CameraLesson3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CameraLesson3);
};

#endif // __CAMERA_LESSON3_SCENE_H__
