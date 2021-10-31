#pragma once
#include "State.h"
#include "BattleState.h"

class PausedState : public State{
    private:
        ofImage paused;

    public:
        PausedState();
        void reset();
        void tick();
        void keyPressed(int key);
        void mousePressed(int x,int y, int button);
        void render();
        void toggleMusic() {};
};