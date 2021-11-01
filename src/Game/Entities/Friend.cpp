#include "Friend.h"

Friend::Friend(string ID, string EntityName, int ox, int oy, int ow, int oh) : Entity(ox, oy, ow, oh, "images/entities/friend1/rightframes/friend1-ow-right1.png"){
    this->ID=ID;
    this->EntityName= EntityName;
    MoveTimer=60;
    vector<ofImage> downframes = { };
    vector<ofImage> leftframes = { };
    vector<ofImage> rightframes = { };
    vector<ofImage> upframes = { };
    ofImage temp;
    walking=true;

    for(int i=1; i<5; i++){
        temp.load("images/entities/"+EntityName+"/downframes/"+EntityName+"-ow-down"+std::to_string(i == 3 ? 1 : i)+".png");
        downframes.push_back(temp);
        temp.load("images/entities/"+EntityName+"/upframes/"+EntityName+"-ow-up"+std::to_string(i == 3 ? 1 : i)+".png");
        upframes.push_back(temp);
        temp.load("images/entities/"+EntityName+"/leftframes/"+EntityName+"-ow-left"+std::to_string(i == 3 ? 1 : i)+".png");
        leftframes.push_back(temp);
        temp.load("images/entities/"+EntityName+"/rightframes/"+EntityName+"-ow-right"+std::to_string(i == 3 ? 1 : i)+".png");
        rightframes.push_back(temp);
    }

    walkDown= new Animation(3, downframes);
    walkRight= new Animation(3, rightframes);
    walkLeft= new Animation(3, leftframes);
    walkUp= new Animation(3, upframes);
}

void Friend::tickOverworld(){
    if (MoveTimer == 60)
    {
        walking = true;
        switch (direction)
        {
        case Direction::left:
            direction = Direction::right;
            break;
        case Direction::right:
            direction = Direction::down;
            break;
        case Direction::up:
            direction = Direction::left;
            break;
        case Direction::down:
            direction = Direction::up;
            break;
        }
    }
    if (MoveTimer == 45)
    {
        walking = false;
    }
    MoveTimer--;
    if (MoveTimer == 0) MoveTimer = 60;

    if (walking)
    {
        switch (direction)
        {
        case Direction::left:
            if(walkingLeft){
            this->ox -= speed;
            walkLeft->tick();
            overworldSprite = walkLeft->getCurrentFrame();
        }
        break;
        case Direction::right:
            if(walkingRight){
            this->ox += speed;
            walkRight->tick();
            overworldSprite = walkRight->getCurrentFrame();
            }
            break;
        case Direction::up:
            if(walkingUp){
            this->oy -= speed;
            walkUp->tick();
            overworldSprite = walkUp->getCurrentFrame();
            }
            break;
        case Direction::down:
            if(walkingDown){
            this->oy += speed;
            walkDown->tick();
            overworldSprite = walkDown->getCurrentFrame();
            }
            break;
        }
    }
    else
    {
        switch (direction)
        {
        case Direction::left:
            overworldSprite.load("images/entities/" + EntityName + "/leftframes/" + EntityName + "-ow-left1.png");
            break;
        case Direction::right:
            overworldSprite.load("images/entities/" + EntityName + "/rightframes/" + EntityName + "-ow-right1.png");
            break;
        case Direction::up:
            overworldSprite.load("images/entities/" + EntityName + "/upframes/" + EntityName + "-ow-up1.png");
            break;
        case Direction::down:
            overworldSprite.load("images/entities/" + EntityName + "/downframes/" + EntityName + "-ow-down1.png");
            break;
        }
    }
}

void Friend::renderOverworld(){
    if(show){
        ofSetColor(0,0,0);
        ofNoFill();
        ofDrawRectangle(ofGetWidth()/4,(ofGetHeight()/4)-20,225,50);
        ofDrawBitmapString("Kill the evil pollitos\nfor they are vile creatures!",ofGetWidth()/4,ofGetHeight()/4);
        ofSetColor(255,255,255);
    }
    else{}
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void Friend::keyPressed(int key){

}

void Friend::keyReleased(int key){

}

void Friend::reset(){

}
