//
//  Game.h
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/22/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#ifndef assignment_tracker_Game_h
#define assignment_tracker_Game_h

#include "Achievement.h"
#include <vector>

using namespace std;

class Game {
    
public:
	Game() {
		game_id = -1;
		game_name = "";
		game_ign = -1;
	}
    
	Game(int id, string name){
		game_id = id;
		game_name = name;
	}
    
	int getId(){
		return game_id;
	}
    
	string getName() {
		return game_name;
	}
    
	vector<Achievement> achievement;
    
private:
	int game_id;
	string game_name;
	string game_ign;
};

void getGameReserves();

/* Get address of specified game */

Game* getGame(int id);

/* Get address of specified achievement within game */

Achievement* getAchievement(int game_id, int achievement_id);

/* Return name of specified Game */

string getGameName(int game_id);

/* Return name of specified Achievement */

string getAchievementName(int achievement_id);

/* Push Back Game into Global Container */

void AddGame(int game_id, string game_name);

/* Push Back Achievement into local container */

void AddAchievement(int game_id, int achievement_id, string achievement_name, int achievement_points);

#endif
