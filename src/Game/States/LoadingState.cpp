#include "LoadingState.h"


LoadingState::LoadingState(){
    timer = 100;
    vector<ofImage> loadingFrames;
    for (int i = 0; i < 20
    ; i++)
    {
    ofImage temp;
    string path = "images/ui/loading-";
    path += to_string(i);
    path += ".png";
    temp.load(path);
    loadingFrames.push_back(temp);
    }
    
    loadingscreen = new Animation(1, loadingFrames);
    music.load("audio/loadingscreenff7.wav");
    music.setLoop(true);
    music.setVolume(0.25);
}

void LoadingState::tick(){
loadingscreen->tick();
    if(timer<0){
        setFinished(true);
        timer = 100;
    }
    else{
        timer--;
    }
loadingImage = loadingscreen->getCurrentFrame();
}
void LoadingState::render(){
    loadingImage.draw(0,0,ofGetWidth(),ofGetHeight());
}
void LoadingState::keyPressed(int key) {
}

void LoadingState::mousePressed(int x, int y, int button){

}
void LoadingState::reset() {
    setFinished(false);
}
