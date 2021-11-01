#pragma once
#include "ofMain.h"
enum Direction {left, right, up, down};
class Entity {
    protected:
        int ox, oy, ow, oh;
        ofImage overworldSprite;

    public:
        Entity(int ox, int oy, int ow, int oh, string overworldPath);
        virtual void tickOverworld() = 0;
        virtual void renderOverworld();
        int getOX() { return ox; };
        int getOY() { return oy; };
        int getOW() { return ow; };
        int getOH() { return oh; };
        virtual ofRectangle getBounds();
        virtual ofRectangle getBounds(int ox, int oy);
        virtual bool collides(Entity* entity);
        virtual void setOX(int ox) { this-> ox = ox; };
        virtual void setOY(int oy) { this-> oy = oy; };
};