#ifndef __MATH_LESSON4_SCENE_H__
#define __MATH_LESSON4_SCENE_H__

#include "cocos2d.h"

class MathLesson4 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MathLesson4);
    
    static cocos2d::Vec3 getInterpolatedPt(const cocos2d::Vec3& p0, const cocos2d::Vec3& p1, const cocos2d::Vec3& p2, float t);
    
    static cocos2d::Vec3 getInterpolatedPtDiff(const cocos2d::Vec3& p0, const cocos2d::Vec3& p1, const cocos2d::Vec3& p2, float t);
    
    virtual void update(float delta) override;
    
protected:
    std::vector<cocos2d::Vec3> _controlPts;
    int _idx;
    float _t;
    cocos2d::Sprite3D* _sprite;
};

#endif // __MATH_LESSON4_SCENE_H__
