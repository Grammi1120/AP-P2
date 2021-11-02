#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighter.h"

class StaticEntity : public Entity {
    private :
        string entityName;
        int speed  = 0;
        bool walking =  false;
        Animation *walkLeft;
        Animation *walkRight;
        string id;
        int renderX = 1000;
        int renderY = 1000; 
        int TimerMove;
       
    public : 
        StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh ,string overworldPath);
        void setRenderX(int x) { renderX = x;};
        void setRenderY(int y) { renderY = y;};
        void tickOverworld();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId() {return id;};
        ofImage getSprite(){return overworldSprite;};
};