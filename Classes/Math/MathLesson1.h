#ifndef __MATH_LESSON1_SCENE_H__
#define __MATH_LESSON1_SCENE_H__

#include "cocos2d.h"

class MathLesson1 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MathLesson1);
};

#endif // __MATH_LESSON1_SCENE_H__
