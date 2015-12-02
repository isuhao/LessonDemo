#ifndef __MATERIAL_LESSON9_SCENE_H__
#define __MATERIAL_LESSON9_SCENE_H__

#include "cocos2d.h"

class MaterialLesson9 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MaterialLesson9);
    
    virtual void update(float delta) override;
    
protected:
    cocos2d::Sprite3D* _sprite;
};

#endif // __MATERIAL_LESSON9_SCENE_H__
