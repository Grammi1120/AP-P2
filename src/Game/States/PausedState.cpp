#include "PausedState.h"

PausedState::PausedState(){
    paused.load("images/ui/pausescreen.png");
    this->music.load("audio/ui/beep.wav");
}

void PausedState::reset(){
    this->setFinished(false);
}

void PausedState::tick(){

}

void PausedState::keyPressed(int key){
    if((key == 'p') || (key=='P')){
        this->setFinished(true);
    }
}

void PausedState::mousePressed(int x, int y,int button){

}

void PausedState::render(){
    paused.draw(0, 0, ofGetWidth(), ofGetHeight());
}

