#include "Static.h"

StaticEntity::StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh, string overworldPath) : Entity(ox,oy,ow,oh,overworldPath){
     this->id = id;
     this->entityName = entityName;
     
}

void StaticEntity::tickOverworld(){
    overworldSprite.load("images/entities/" + entityName + "/upframes/" + entityName + "-ow-up1.png");
}

void StaticEntity::renderOverworld(){
    overworldSprite.draw(renderX,renderY, ow, oh);
}

void StaticEntity::keyReleased(int key){

}
void StaticEntity::reset(){}