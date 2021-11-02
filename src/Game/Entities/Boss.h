#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Enemy.h"
#include "State.h"

class Boss : public Enemy{
    private:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
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
        Boss(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, string overworldPath);
        ~Boss();
        bool isDead() { return dead; };
        void kill() { this->dead=true; };
        void revive() {this->dead=false; };
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId() { return id; };
        bool PhasePass=false;
        void phase();
        bool getHasPhase() { return PhasePass; };



};