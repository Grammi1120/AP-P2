#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Friend.h"
#include "OverworldCamera.h"
#include "Static.h"
class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<StaticEntity*>staticEntity;
        std::vector<Enemy*> enemies;
        Area *nextArea;
        std::vector<Friend*> Friends;
        string name;

    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> Friends);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        vector<Enemy*> getEnemies() { return enemies;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        void setFriends(std::vector<Friend*> friends) { this->Friends = Friends; };
        vector<Friend*> getFriends() { return Friends; };
        string getName() { return name; };
        void setStaticEntity( std::vector<StaticEntity*>) {this->staticEntity = staticEntity;};
        vector<StaticEntity*>getStaticEntity() {return staticEntity;};
};