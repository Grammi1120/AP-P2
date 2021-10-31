#pragma once
#include "ofMain.h"
#include "Entity.h"
#include  "Animation.h"

class Fighter : public Entity{
    protected:
        int health;
        int baseDamage;
        // Fighting coordinates and dimensions
        int fx, fy, fw, fh;
        ofImage fightingSprite;
        Animation *fighting;
        

    public:
        Fighter(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage, string fightingPath, string overworldPath);
        virtual void tickFighting() = 0;
        virtual void renderFighting();
        int getHealth() { return health; };
        void setHealth(int health) { this->health = health; };
        int getDmg() { return baseDamage; };
        void setDmg(int baseDamage) { this->baseDamage = baseDamage; };
};