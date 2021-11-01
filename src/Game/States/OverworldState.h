#pragma once

#include "State.h"
#include "Area.h"
#include "Player.h"
#include "Enemy.h"
#include "Friend.h"
#include "OverworldCamera.h"
#include "PausedState.h"
#include "LoadingState.h"
#include "Static.h"

class OverworldState : public State
{
    private:
        ofImage overworldImage;
        Player *player;
        OverworldCamera *camera;
        Area *area;
        std::vector<Enemy*> enemies;
        StaticEntity *staticEntity;
        Enemy *enemy;
        Friend *FriendTest;
        bool eKey=false;
        int KeyTimer = 60;
        
    public:
        OverworldState(Player *player, Area *area);
        Player* getPlayer() { return player;};
        void setEnemy(Enemy *enemy) { this->enemy = enemy;};
        Enemy* getEnemy() { return enemy;};
        void setStaticEntity(StaticEntity *staticEntity) {this->staticEntity = staticEntity;};
        void loadArea(Area *Area);
        Area* getArea() { return area;};
        Friend* getFriend() { return FriendTest; };
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
};