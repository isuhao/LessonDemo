#ifndef __SPRITE3D_LESSON2_SCENE_H__
#define __SPRITE3D_LESSON2_SCENE_H__

#include "cocos2d.h"

class Sprite3DLesson2 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Sprite3DLesson2);
};

#endif // __SPRITE3D_LESSON2_SCENE_H__
