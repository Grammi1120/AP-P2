#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighter.h"

class Enemy : public Fighter {
    protected:
        Direction direction = Direction::down;
        int speed = 4;
        bool walking = false;
        int renderX = 1000;
        int renderY = 1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        string id;
        int moveTimer;
        bool dead = false;
        string entityName;
        ofImage sprite; 


    public:
        Enemy(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, string overworldPath);
        ~Enemy();
        virtual int getOX() { return ox; };
        virtual int getOY() { return oy; };
        virtual bool isDead() { return dead;};
        virtual void kill() { this->dead = true;};
        virtual void revive() { this->dead = false;};
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        virtual void tickOverworld();
        virtual void tickFighting();
        virtual void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        virtual string getId(){ return id; };
        virtual ofImage getSprite() { return overworldSprite;};
        int maxhealth;
        int getRenderX()  { return renderX; };
        int getRenderY() { return renderY; };
};
