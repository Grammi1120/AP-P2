#include "Static.h"

StaticEntity::StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh, string overworldPath) : Entity(ox,oy,ow,oh,overworldPath){
     this->id = id;
     this->entityName = entityName;
     overworldSprite.load(overworldPath);
}

void StaticEntity::tickOverworld(){
 
}

void StaticEntity::renderOverworld(){
    overworldSprite.draw(renderX,renderY, ow, oh);

}

void StaticEntity::keyReleased(int key){

}
void StaticEntity::reset(){}