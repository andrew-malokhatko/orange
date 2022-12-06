#ifndef __MAINGAME_SCENE_H__
#define __MAINGAME_SCENE_H__

#include "cocos2d.h"
#include "Hero.h"
#include "Attacks/Attack.h"
#include <list>

class MainGameScene : public cocos2d::Scene
{
private:
    std::list<Attack*> attacks;
    Hero* hero = nullptr;
    cocos2d::EventListenerMouse* mouseListener = cocos2d::EventListenerMouse::create();

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void update(float dt);
    void addAttack(cocos2d::Event* event);
    
    CREATE_FUNC(MainGameScene);
};

#endif