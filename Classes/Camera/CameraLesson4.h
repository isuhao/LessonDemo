#ifndef __CAMERA_LESSON4_SCENE_H__
#define __CAMERA_LESSON4_SCENE_H__

#include "cocos2d.h"

class CameraLesson4 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CameraLesson4);
};

#endif // __CAMERA_LESSON4_SCENE_H__
