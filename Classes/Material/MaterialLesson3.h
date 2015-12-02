#ifndef __MATERIAL_LESSON3_SCENE_H__
#define __MATERIAL_LESSON3_SCENE_H__

#include "cocos2d.h"

class MaterialLesson3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MaterialLesson3);
};

#endif // __MATERIAL_LESSON3_SCENE_H__
