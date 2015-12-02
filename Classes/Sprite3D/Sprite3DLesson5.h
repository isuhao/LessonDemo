#ifndef __SPRITE3D_LESSON5_SCENE_H__
#define __SPRITE3D_LESSON5_SCENE_H__

#include "cocos2d.h"

class Sprite3DLesson5 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Sprite3DLesson5);
    
    virtual void update(float delta) override;
    
protected:
    cocos2d::Sprite3D* _sprite;
    
    cocos2d::Sprite3D* _lfoot;
    cocos2d::Sprite3D* _rfoot;
};

#endif // __SPRITE3D_LESSON5_SCENE_H__
