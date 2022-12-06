#include "MainGameScene.h"
#include <iostream>

cocos2d::Scene* MainGameScene::createScene()
{
    return MainGameScene::create();
}

bool MainGameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    this->scheduleUpdate();

    hero = new Hero(this);
    mouseListener->onMouseDown = CC_CALLBACK_1(MainGameScene::addAttack, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

    return true;
}

void MainGameScene::update(float dt)
{
    //std::cout<< "attacks size: " << attacks.size() << " yo \n";
    std::list<Attack*> toDelete;
    for (Attack* attack : attacks)
    {
        if (!attack->process(dt))
        {
            toDelete.push_back(attack);
        }
    }

    for (Attack* attack : toDelete)
    {
        attacks.remove(attack);
        delete attack;
    }
}

void MainGameScene::addAttack(cocos2d::Event* event)
{
    cocos2d::EventMouse* mouseEvent = static_cast<cocos2d::EventMouse*>(event);
    double x = mouseEvent->getCursorX();
    double y = mouseEvent->getCursorY();
    attacks.push_back(hero->attack(Position{x, y}));
}

