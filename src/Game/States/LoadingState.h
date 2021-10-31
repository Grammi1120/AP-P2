#pragma once
#include "State.h"
#include "Animation.h"

class LoadingState:public State{
    private:
        Animation *loadingscreen;
        ofImage loadingImage;

    public:
        LoadingState();
        void reset();
        void tick();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void render();
        void toggleMusic() {};
        int timer;
};