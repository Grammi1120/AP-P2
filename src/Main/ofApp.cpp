#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(30);
	ofSetWindowTitle("PA2");
	setupAreas();
	// Declaration and Initialization of States
	player = new Player(100, 6);
	titleState = new TitleState();
	overworldState = new OverworldState(player, currentArea);
	battleState = new BattleState(player, currentArea);
	winState = new WinState();
	endGameState = new EndGameState();
	pausedState = new PausedState();
	loadingState = new LoadingState();


	// Initial State
	loadingState->setNextState("Overworld");
	currentState = titleState;
}

//--------------------------------------------------------------
void ofApp::setupAreas()
{
	//each area is 672 pixels wide and 640 pixels high, with 10 and 8 pixels of space between the player and the edge of the map respectively
	//each in-game pixel is 4 * 1 screen pixel

	vector<Enemy *> enemies2;
	vector<Friend*> AshKetchup;
	ofPoint entrancePosition2(4 * 110, 4 * 116);
	Enemy *area2Enemy1 = new Enemy("21", 30, 6, "enemy2", 4 * 120, 4 * 342,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Enemy *area2Enemy2 = new Enemy("22", 30, 6, "enemy2", 4 * 254, 4 * 130,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Enemy *area2Enemy3 = new Enemy("23", 30, 6, "enemy2", 4 * 542, 4 * 124,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Enemy *area2Enemy4 = new Enemy("24", 30, 6, "enemy2", 4 * 532, 4 * 368,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Enemy *area2Enemy5 = new Enemy("25", 30, 6, "enemy2", 4 * 266, 4 * 312,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Enemy *area2Enemy6 = new Enemy("26", 30, 6, "enemy2", 4 * 194, 4 * 532,"images/entities/enemy2/fightingframes/enemy2-f1.png","images/entities/enemy2/downframes/enemy2-ow-down1.png");
	Friend *area2Friend1=new Friend("70", "friend1", 4*102, 4*344 ,64,64);

	enemies2.push_back(area2Enemy1);
	enemies2.push_back(area2Enemy2);
	enemies2.push_back(area2Enemy3);
	enemies2.push_back(area2Enemy4);
	enemies2.push_back(area2Enemy5);
	enemies2.push_back(area2Enemy6);
	AshKetchup.push_back(area2Friend1);

	Boss *area2Boss=new Boss("72",40,8,"boss1",4*120,4*254,"images/entities/boss1/fightingframes/boss1-f1.png","images/entities/boss1/downframes/boss1-ow-down1.png");
	enemies2.push_back(area2Boss);
	area2Boss->kill();

	area2 = new Area(NULL, "images/areas/area2.png", "audio/ice.wav", "images/stages/stage2.png", entrancePosition2, enemies2, "Area 2", AshKetchup); 
	vector<Enemy *> enemies1;
	ofPoint entrancePosition1(4 * 414, 4 * 566);
	Enemy *area1Enemy1 = new Enemy("11", 20, 4, "enemy1", 4 * 480, 4 * 432,"images/entities/enemy1/fightingframes/enemy1-f1.png","images/entities/enemy1/downframes/enemy1-ow-down1.png");
	Enemy *area1Enemy2 = new Enemy("12", 20, 4, "enemy1", 4 * 225, 4 * 178,"images/entities/enemy1/fightingframes/enemy1-f1.png","images/entities/enemy1/downframes/enemy1-ow-down1.png");
	Enemy *area1Enemy3 = new Enemy("13", 20, 4, "enemy1", 4 * 420, 4 * 178,"images/entities/enemy1/fightingframes/enemy1-f1.png","images/entities/enemy1/downframes/enemy1-ow-down1.png");
	Friend *area1Friend1=new Friend("71", "friend1", 1568, 2128 ,64,64);

	enemies1.push_back(area1Enemy1);
	enemies1.push_back(area1Enemy2);
	enemies1.push_back(area1Enemy3);
	
	vector<StaticEntity *>StaticE1;
	StaticEntity *area1StaticEntity1 = new StaticEntity("60","static1",4 * 300, 4 * 546, 200, 200,"images/entities/static1/upframes/static1-ow-up1.png");
	StaticEntity *area1StaticEntity2 = new StaticEntity("60","static1",4 * 264, 4* 400, 200, 200,"images/entities/static1/upframes/static1-ow-up1.png");
	StaticEntity *area1StaticEntity3 = new StaticEntity("60","static1",4 * 270, 4 * 500, 200, 200,"images/entities/static1/upframes/static1-ow-up1.png");
	
	StaticE1.push_back(area1StaticEntity1);
	StaticE1.push_back(area1StaticEntity2);
	StaticE1.push_back(area1StaticEntity3);
	area1 = new Area(area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, "Area 1");
	AshKetchup.push_back(area1Friend1);

	Boss *area1Boss=new Boss("73",40,8,"boss1",4*120,4*254,"images/entities/boss1/fightingframes/boss1-f1.png","images/entities/boss1/downframes/boss1-ow-down1.png");
	enemies1.push_back(area1Boss);
	area1Boss->kill();

	area1 = new Area(area2, "images/areas/area1.png", "audio/forest.wav", "images/stages/stage1.png", entrancePosition1, enemies1, "Area 1", AshKetchup);
	currentArea = area1;
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (currentState != nullptr)
	{
		currentState->tick();
		if (currentState->hasFinished())
		{
			currentState->toggleMusic();
			if (currentState->getNextState() == "Title")
			{
				endGameState->setWin(false);
				area1->resetEnemies();
				area2->resetEnemies();
				currentArea = area1;
				battleState->resetPlayer();
				battleState->setStage(currentArea->getStage());
				overworldState->loadArea(currentArea);
				currentState = titleState;
			}
			else if (currentState->getNextState() == "Overworld")
			{
				currentState = overworldState;
			}
			else if (currentState->getNextState() == "Battle")
			{
                if(dynamic_cast<PausedState*>(currentState) != nullptr){
                    battleState->isPaused;
                }
				battleState->startBattle(overworldState->getEnemy());
				currentState = battleState;
			}
			else if(currentState->getNextState()=="LoadingState"){
				loadingState->setNextState(currentState->getAfterLoadSt());
				currentState = loadingState;
			}
			else if(currentState->getNextState()=="PausedState"){
				if(dynamic_cast<BattleState*>(currentState)!=nullptr){
						pausedState->setNextState("Battle");
				}		
				if(dynamic_cast<OverworldState*>(currentState)!=nullptr){
						pausedState->setNextState("Overworld");

				}
				currentState = pausedState;

			}
			else if (currentState->getNextState() == "Win")
			{
				battleState->isPaused=false;
				overworldState->getEnemy()->kill();
				if (currentArea->getRemainingEnemies() == 0 && currentArea->BossIsDead)
				{
					if (currentArea->getNextArea() == NULL)
					{
						endGameState->setWin(true);
						currentState = endGameState;
					}
					else
					{
						currentArea = currentArea->getNextArea();
						overworldState->loadArea(currentArea);
						battleState->setStage(currentArea->getStage());
						currentState = winState;
					}
				}
				else
				{
					currentState = winState;
				}
			}
			else if (currentState->getNextState() == "End")
				currentState = endGameState;
			currentState->toggleMusic();
			currentState->reset();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (currentState != nullptr)
	{
		currentState->render();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (currentState != nullptr)
		currentState->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	if (currentState != nullptr)
		currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
	if (currentState != nullptr)
		currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}