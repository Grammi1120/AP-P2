#pragma once

#include "Entity.h"
#include "Fighter.h"
#include "Animation.h"

class Friend: public Entity {

    private:
        bool walking=false;
        int speed=8;
        Direction direction=Direction::down;
        int renderX=1000, renderY=1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        string ID, EntityName;
        int MoveTimer;
        ofImage sprite;
        bool walkingLeft=true, walkingRight=true, walkingUp=true, walkingDown=true, DirectionChange=true;
    public:
        Friend(string ID, string EntityName, int ox, int oy, int ow, int oh);
        void tickOverworld();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        int getOX() { return ox; };
        int getOY() { return oy; };
        void setRenderX(int x) { renderX=x; };
        void setRenderY(int y) { renderY=y; };
        string getID() { return ID; };
        ofImage getSprite() { return overworldSprite; };
        void setCanWalkLeft(bool walkingLeft) { this->walkingLeft=walkingLeft; };
        void setCanWalkRight(bool walkingRight) { this->walkingRight=walkingRight; };
        void setCanWalkUp(bool walkingUp) { this->walkingUp=walkingUp; };
        void setCanWalkDown(bool walkingDown) { this->walkingDown=walkingDown; };
        bool getCanWalkLeft() { return walkingLeft; };
        bool getCanWalkRight() { return walkingRight; };
        bool getCanWalkDown() { return walkingDown; };
        bool getCanWalkUp() { return walkingUp; };
        int getSpeed() { return speed; }
        bool show=false;

};