#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
    afterLoadSt="Battle";
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
}

void OverworldState::tick()
{
    player->tickOverworld();

    for(StaticEntity* StaticEntity1 : area->getStaticEntity()) {
        StaticEntity1->tickOverworld();
    }



    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            area->getEnemies().at(i)->tickOverworld();
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("LoadingState");
                setFinished(true);
            }
        }
    }
    player->setCanWalkLeft(true);
    player->setCanWalkRight(true);
    player->setCanWalkUp(true);
    player->setCanWalkDown(true);

    for(Friend* f:area->getFriends()){
           f->tickOverworld();
        }
  
    for(Friend* f:area->getFriends()){
        f->setCanWalkLeft(true);
        f->setCanWalkRight(true);
        f->setCanWalkUp(true);
        f->setCanWalkDown(true);
        if(player->getBounds(player->getOX()-player->getSpeed(), player->getOY()).intersects(f->getBounds())){
            player->setCanWalkLeft(false);
            f->setCanWalkRight(false);
            f->setCanWalkDown(false);
            f->setCanWalkUp(false);
            f->setCanWalkLeft(false);
            eKey=true;
        }
        if(player->getBounds(player->getOX()+player->getSpeed(), player->getOY()).intersects(f->getBounds())){
            player->setCanWalkRight(false);
            f->setCanWalkRight(false);
            f->setCanWalkDown(false);
            f->setCanWalkUp(false);
            f->setCanWalkLeft(false);
            eKey=true;
        }
        if(player->getBounds(player->getOX(),player->getOY()-player->getSpeed()).intersects(f->getBounds())){
            player->setCanWalkUp(false);
            f->setCanWalkRight(false);
            f->setCanWalkDown(false);
            f->setCanWalkUp(false);
            f->setCanWalkLeft(false);
            eKey=true;
        }
        if(player->getBounds(player->getOX(),player->getOY()+player->getSpeed()).intersects(f->getBounds())){
            player->setCanWalkDown(false);
            f->setCanWalkRight(false);
            f->setCanWalkDown(false);
            f->setCanWalkUp(false);
            f->setCanWalkLeft(false);
            eKey=true;
        }
    }
    for(Friend* f1: area->getFriends()){
        if(f1->show){
        KeyTimer--;
        if(KeyTimer<=0){
            KeyTimer=60;
            eKey=false;
            f1->show=false;
        }
    }
    }
    if(area->getRemainingEnemies()==0 && !area->BossIsDead){
        area->getEnemies().back()->revive();
    }
    for(unsigned int i=0; i<area->getEnemies().size(); i++){
        if(!area->getEnemies().at(i)->isDead()){
            Enemy* enemy=area->getEnemies().at(i);
            enemy->tickOverworld();
            if(player->collides(area->getEnemies().at(i))){
                setEnemy(area->getEnemies().at(i));
                setNextState("LoadingState");
                setFinished(true);
                Boss* boss=dynamic_cast<Boss*> (enemy);
                if(boss!=nullptr)
                {
                    area->BossIsDead=true;
                }
            }
        }
    }

    camera->tick();
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();

    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();
        }
    }
    for (StaticEntity* StaticE1 : area->getStaticEntity())
    {
        int playerDistanceX = StaticE1->getOX() - camera->getPlayerX();
        int playerDistanceY = StaticE1->getOY() - camera->getPlayerY();
        StaticE1->setRenderX(camera->getDimensionX()/ 2 + playerDistanceX);
        StaticE1->setRenderY(camera->getDimensionY()/ 2 + playerDistanceY);
        StaticE1->renderOverworld();
    }


    ofSetColor(255,0,0);
    ofDrawBitmapString("HP: "+to_string(player->getHealth()),(ofGetWidth()/16)-30,ofGetHeight()/16);
    ofSetColor(255,255,0);
    ofDrawBitmapString("Current Enemy Count: "+to_string(area->getRemainingEnemies()),(ofGetWidth()/16)-30,ofGetHeight()/16+20);
    ofSetColor(0,0,255);
    ofDrawBitmapString("Area: "+area->getName(),(ofGetWidth()/16)-30,ofGetHeight()/16+40);
    ofSetColor(255,255,255);

    for(unsigned int i=0;i<area->getFriends().size(); i++){
        int PlayerReachX=area->getFriends().at(i)->getOX()-camera->getPlayerX();
        int PlayerReachY=area->getFriends().at(i)->getOY()-camera->getPlayerY();
        area->getFriends().at(i)->setRenderY(camera->getDimensionY()/2+PlayerReachY);
        area->getFriends().at(i)->setRenderX(camera->getDimensionX()/2+PlayerReachX);
        area->getFriends().at(i)->renderOverworld();
    }
}

void OverworldState::keyPressed(int key)
{
    if((key == 'P')||(key == 'p')){
        this->setFinished(true);
        this->setNextState("PausedState");
    }
    player->keyPressed(key);
    if(key=='e'||key=='E'){
        if(eKey)
        {
            for(Friend* f1:area->getFriends())
            {
                f1->show=true;
            }
        }
    }
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
    if((key == 'H')|| (key == 'h')){
        if(player->getHealth()<100){
            player->setHealth(100);
          
        }
    }
    
    if((key == 'R')|| (key == 'r')){
        for (unsigned int i = 0; i < area->getEnemies().size(); i++){
        area->getEnemies()[i]->revive();
        }
    area->getEnemies().back()->kill();
    }
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}