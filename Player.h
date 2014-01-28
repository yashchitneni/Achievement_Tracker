//
//  Player.h
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/22/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#ifndef assignment_tracker_Player_h
#define assignment_tracker_Player_h

#include <iomanip>
#include <vector>
#include "Game.h"
#include <utility>
#include <tuple>

using namespace std;

class Player {
    
public:
	Player() {
		player_id = -1;
		player_name = "";
	}
    
	Player(int id) {
		player_id = id;
	}
    
	Player(int id, string name){
		player_id = id;
		player_name = name;
	}
    
    /* Local Containers for respective lists */

	vector<Player*> friends;
	vector<pair<Player*, Game*> > games_played;
	vector<string> in_game_name;
    typedef pair<Player*, pair<Game*, Achievement*> > game_achieve_pair;
    vector<game_achieve_pair> vector_game_achieve;
    
    
	int getId(){
		return player_id;
	}
    
	string getName() {
		return player_name;
	}
    
private:
	int player_id;
	string player_name;
};

void getPlayerReserves();

/* Return address of player object */

Player* getPlayer(int id);

/* Get Player Name */

string getPlayerName(int id);

/* Add Player to Database */

void AddPlayer(int id, string name);

/* Note the game player plays */

void Plays(int player_id, int game_id, string ign);

/* Print players who play specified game */
 
void SummarizeGame(int game_id);

/* Make two Players friends mutually */

void AddFriends(int player_id_1, int player_id_2);

/* Show list of friends */

void PrintFriends(int player_id);

/* Push back pointers to specific local containers */

void Achieve(int player_id, int game_id, int achievement_id);

/* Print list of players who play specific game */

void FriendsWhoPlay(int player_id, int game_id);

/* Output Achievement Name and Points */

void PrintAchieve(int player_id, int game_id);

/* Compare two players */

void ComparePlayers(int player_id_1, int player_id_2, int game_id);

/* Use to print list of games player plays */

void PrintGame(int player_id);

/* Add up all points achieved by player */

int sumGamerPoints(int player_id);

/* Display Player Details */

void SummarizePlayer(int player_id);

/* Display Achievement Details */

void SummarizeAchievement(int game_id, int achievement_id);


#endif
