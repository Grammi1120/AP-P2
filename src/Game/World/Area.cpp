#include "Area.h"

Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> Friends, vector<StaticEntity*> staticEntity)
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->name=name;
    this->Friends=Friends;
    this->staticEntity = staticEntity;
}
void Area::resetEnemies(){
        for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
    BossIsDead=false;
    enemies.back()->kill();
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}