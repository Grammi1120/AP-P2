#include "Boss.h"

Boss::Boss(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, string overworldPath) : Enemy(id,health,baseDamage,entityName,ox,oy,fightingPath,overworldPath){
    this->id=id;
    this->entityName=entityName;
    moveTimer=60;
    vector<ofImage> downframes = { };
    vector<ofImage> leftframes = { };
    vector<ofImage> rightframes = { };
    vector<ofImage> upframes = { };
    vector<ofImage> fightingFrames = { };
    ofImage temp; 

    for(int i=1; i<5; i++){
        temp.load("images/entities/"+entityName+"/downframes/"+entityName+"-ow-down"+std::to_string(i == 3 ? 1 : i)+".png");
        downframes.push_back(temp);
        temp.load("images/entities/"+entityName+"/upframes/"+entityName+"-ow-up"+std::to_string(i == 3 ? 1 : i)+".png");
        upframes.push_back(temp);
        temp.load("images/entities/"+entityName+"/leftframes/"+entityName+"-ow-left"+std::to_string(i == 3 ? 1 : i)+".png");
        leftframes.push_back(temp);
        temp.load("images/entities/"+entityName+"/rightframes/"+entityName+"-ow-right"+std::to_string(i == 3 ? 1 : i)+".png");
        rightframes.push_back(temp);
    }
    temp.load("images/entities/" + entityName + "/fightingframes/" + entityName + "-f1.png");
    fightingFrames.push_back(temp);
    temp.load("images/entities/" + entityName + "/fightingframes/" + entityName + "-f2.png");
    fightingFrames.push_back(temp);

    walkDown = new Animation(3, downframes);
    walkUp = new Animation(3, upframes);
    walkLeft = new Animation(3, leftframes);
    walkRight = new Animation(3, rightframes);
    fighting = new Animation(7, fightingFrames);
}

void Boss::renderOverworld()
{
    overworldSprite.draw(renderX,renderY,ow,oh);
}

void Boss::keyPressed(int key){

}
void Boss::keyReleased(int key){

}
void Boss::reset(){
    dead=true;
}
Boss::~Boss(){
    delete walkUp;
    delete walkDown;
    delete walkRight;
    delete walkLeft;
    delete fighting;
}

void Boss::phase(){
    PhasePass=true;
}