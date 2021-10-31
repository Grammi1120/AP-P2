#include "Fighter.h"
#include <iostream>
Fighter::Fighter(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage, string fightingPath, string overworldPath) : Entity(ox, oy, ow, oh, overworldPath) {

    this->fx = fx;
    this->fy = fy;
    this->fh = fh;
    this->fw = fw;
    this->health = health;
    this->baseDamage = baseDamage;

    fightingSprite.load(fightingPath);
}

void Fighter::renderFighting() {
    fightingSprite.draw(fx, fy, fw, fh);
}

void Fighter:: tickFighting(){
       fightingSprite = fighting->getCurrentFrame();
       fighting->tick();
}
