//
//  Player.cpp
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/27/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#include "Player.h"

vector<Player> player_database;
vector<Game> game_database;

void getPlayerReserves() {
    player_database.reserve(100);
}

/* Return address of player object */

Player* getPlayer(int id){
	for (int i = 0; i < player_database.size(); i++){
		if (id == player_database[i].getId()){
			return &player_database[i];
		}
	}
    return 0;
}

/* Get Player Name */

string getPlayerName(int id){
    for (int i = 0; i < player_database.size(); i++) {
        if (id == player_database[i].getId()) {
            return player_database[i].getName();
        }
    }
    return NULL;
}

/* Add Player to Database */

void AddPlayer(int id, string name){
	Player player_created(id, name);
	player_database.push_back(player_created);
}

/* Note the game player plays */

void Plays(int player_id, int game_id, string ign){
    
    /* Returns address of specific game */
    Player* game_player = getPlayer(player_id);
	Game* game_playing = getGame(game_id);
    
	for (int i = 0; i < player_database.size(); i++) {
		if (player_id == player_database[i].getId()) {
			player_database[i].games_played.push_back(make_pair(game_player, game_playing));
			player_database[i].in_game_name.push_back(ign);
		}
	}
}

/* Print players who play specified game */

void SummarizeGame(int game_id) {
    cout << "Players who played " << getGameName(game_id) << ":" << endl;
    for (int i = 0; i < player_database.size(); i++) {
        for (int j = 0; j < player_database[i].games_played.size(); j++) {
            cout << j+1 << ". ";
            if (game_id == player_database[i].games_played[j].second->getId()) {
                cout << player_database[i].games_played[j].first->getName() << endl;
            }
        }
    }
}

/* Make two Players friends mutually */

void AddFriends(int player_id_1, int player_id_2){
    
    /* Returns the address of the specific friends */
    
	Player* player_one = getPlayer(player_id_1);
	Player* player_two = getPlayer(player_id_2);
    
	for (int i = 0; i < player_database.size(); i++){
		if (player_id_1 == player_database[i].getId()){
			player_database[i].friends.push_back(player_two);
		}
		else if (player_id_2 == player_database[i].getId()){
			player_database[i].friends.push_back(player_one);
		}
	}
}

/* Show list of friends */

void PrintFriends(int player_id) {
    int count = 0;
    for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()) {
            cout << "  Friends of " << player_database[i].getName() << endl;
            for (int j = 0; j < player_database[i].friends.size(); j++) {
                count++;
                cout << count << "." << player_database[i].friends[j]->getName() << "\n";
            }
        }
    }
}

/* Push back pointers to specific local containers */

void Achieve(int player_id, int game_id, int achievement_id) {
    
    Player* player_achieved = getPlayer(player_id);
    Game* game_achieved = getGame(game_id);
    Achievement* player_achieved_1 = getAchievement(game_id, achievement_id);
    
	for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()) {
            player_database[i].vector_game_achieve.push_back(make_pair(player_achieved, make_pair(game_achieved, player_achieved_1)));
        }
    }
}

/* Print list of players who play specific game */

void FriendsWhoPlay(int player_id, int game_id){
    for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()){
            for (int j = 0; j < player_database[i].friends.size(); j++) {
                for (int k = 0; k < player_database[i].friends[j]->games_played.size(); k++) {
                    if (game_id == (*player_database[i].friends[j]->games_played[k].second).getId()) {
                        cout << player_database[i].friends[j]->getName() << endl;
                    }
                }
            }
        }
	}
}

/* Output Achievement Name and Points */

void PrintAchieve(int player_id, int game_id) {
    int count = 0;
    for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()) {
            cout << setw(20) << left << "   Achievement Name" << setw(20) << "   Achievement Points" << endl;
            for (int j = 0; j < player_database[i].games_played.size(); j++) {
                if (game_id == player_database[i].games_played[j].second->getId()) {
                    for (int k = 0; k < player_database[i].vector_game_achieve.size(); k++) {
                        if (game_id == player_database[i].vector_game_achieve[k].second.first->getId()) {
                            count++;
                            cout << count << left << ". " << setw(20) << left << player_database[i].vector_game_achieve[k].second.second->getName() << setw(20) <<
                            left << player_database[i].vector_game_achieve[k].second.second->getPoints() << endl;
                        }
                    }
                }
            }
        }
    }
}

/* Compare two players */

void ComparePlayers(int player_id_1, int player_id_2, int game_id) {
    cout << setw(20) << right << getPlayerName(player_id_1) << endl;
    PrintAchieve(player_id_1, game_id);
    cout << setw(20) << right << getPlayerName(player_id_2) << endl;
    PrintAchieve(player_id_2, game_id);
}

/* Use to print list of games player plays */

void PrintGame(int player_id) {
    int count = 0;
    for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()) {
            for (int j = 0; j < player_database[i].games_played.size(); j++) {
                count++;
                cout << count << left << "." << setw(20) << left << player_database[i].games_played[j].second->getName() << setw(20) << left
                << player_database[i].in_game_name[j] << endl;
            }
        }
    }
}

/* Add up all points achieved by player */

int sumGamerPoints(int player_id) {
    int game_points = 0;
    for (int i = 0; i < player_database.size(); i++) {
        for (int j = 0; j < player_database[i].vector_game_achieve.size(); j++) {
            if (player_id == player_database[i].vector_game_achieve[j].first->getId()) {
                game_points += player_database[i].vector_game_achieve[j].second.second->getPoints();
            }
        }
    }
    return game_points;
}

/* Display Player Details */

void SummarizePlayer(int player_id) {
    for (int i = 0; i < player_database.size(); i++) {
        if (player_id == player_database[i].getId()) {
            cout << "" << endl;
            cout << "Player Name: " << getPlayerName(player_id) << endl;
            cout << "" << endl;
            cout << "  " << setw(20) << left << "Game Name" << setw(20) << left << "Game IGN" << endl;
            PrintGame(player_id);
            cout << "" << endl;
            PrintFriends(player_id);
            cout << "" << endl;
        }
    }
    cout << "Total gamer points: " << sumGamerPoints(player_id);
}

/* Display Achievement Details */

void SummarizeAchievement(int game_id, int achievement_id) {
    cout << "Players who have achieved " << getAchievementName(achievement_id) << endl;
    for (int i = 0; i < player_database.size(); i++) {
        for (int j = 0; j < player_database[i].vector_game_achieve.size(); j++) {
            if (game_id == player_database[i].vector_game_achieve[j].second.first->getId()) {
                if (achievement_id == player_database[i].vector_game_achieve[j].second.second->getId()) {
                    cout << j + 1 << ". " << player_database[i].vector_game_achieve[j].first->getName() << endl;
                }
            }
        }
    }
}