//
//  Game.cpp
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/27/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#include "Game.h"

extern vector<Game> game_database;

/* Get address of specified game */

Game* getGame(int id){
	for (int i = 0; i < game_database.size(); i++){
		if (id == game_database[i].getId()){
			return &game_database[i];
		}
	}
    return 0;
}

/* Get address of specified achievement within game */

Achievement* getAchievement(int game_id, int achievement_id){
	for (int i = 0; i < game_database.size(); i++){
        if (game_id == game_database[i].getId()) {
            for (int j = 0; j < game_database[i].achievement.size(); j++) {
                if (achievement_id == game_database[i].achievement[j].getId()) {
                    return &game_database[i].achievement[j];
                }
            }
        }
	}
    return 0;
}

/* Return name of specified Game */

string getGameName(int game_id) {
    for (int i = 0; i < game_database.size(); i++) {
        if (game_id == game_database[i].getId()) {
            return game_database[i].getName();
        }
    }
    return NULL;
}

/* Return name of specified Achievement */

string getAchievementName(int achievement_id) {
    for (int i = 0; i < game_database.size(); i++) {
        for (int j = 0; j< game_database[i].achievement.size(); j++) {
            if (achievement_id == game_database[i].achievement[j].getId()) {
                return game_database[i].achievement[j].getName();
            }
        }
    }
    return NULL;
}

/* Push Back Game into Global Container */

void AddGame(int game_id, string game_name){
	Game game_created(game_id, game_name);
	game_database.push_back(game_created);
}

/* Push Back Achievement into local container */

void AddAchievement(int game_id, int achievement_id, string achievement_name, int achievement_points) {
	Achievement added_achievement(achievement_id, achievement_name, achievement_points, 0);
    
	for (int i = 0; i < game_database.size(); i++) {
		if (game_id == game_database[i].getId()) {
			game_database[i].achievement.push_back(added_achievement);
		}
	}
}
