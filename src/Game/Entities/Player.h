#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighter.h"

#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560


class Player : public Fighter {
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        vector<char> pressedKeys;
        bool walkingDown=true;
        bool walkingLeft=true;
        bool walkingRight=true;
        bool walkingUp=true;
    
    public:
        Player(int health, int baseDamage);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        void setCanWalkLeft(bool walkingLeft) { this->walkingLeft=walkingLeft; };
        void setCanWalkRight(bool walkingRight) { this->walkingRight=walkingRight; };
        void setCanWalkUp(bool walkingUp) { this->walkingUp=walkingUp; };
        void setCanWalkDown(bool walkingDown) { this->walkingDown=walkingDown; };
        bool getCanWalkLeft() { return walkingLeft; };
        bool getCanWalkRight() { return walkingRight; };
        bool getCanWalkDown() { return walkingDown; };
        bool getCanWalkUp() { return walkingUp; };
        int getSpeed() { return speed; };
        int allHealth;
};