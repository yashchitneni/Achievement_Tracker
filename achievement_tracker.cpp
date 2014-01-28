//
//  main.cpp
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/22/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using namespace std;

int main(){
	getGameReserves();
	getPlayerReserves();
    
	string input;
    
	cout << "Please choose from the following commands and type and press enter\n";
	cout << "AddPlayer <PlayerID> <PlayerName>\n";
	cout << "AddGame <GameID> <GameName>\n";
	cout << "AddAchievement <GameID> <AchievementID> <AchievementName> <AchievementPoints>\n";
	cout << "Plays <PlayerID> <GameID> <PlayerIGN>\n";
	cout << "AddFriends <PlayerID1> <PlayerID2>\n";
	cout << "Achieve <PlayerID> <GameID> <AchievementID>\n";
	cout << "FriendsWhoPlay <PlayerID> <GameID>\n";
	cout << "ComparePlayers <PlayerID1> <PlayerID2> <GameID>\n";
	cout << "SummarizePlayer <PlayerID>\n";
	cout << "SummarizeGame <GameID>\n";
	cout << "SummarizeAchievement <GameID> <AchievementID>\n";
	cout << "AchievementRanking\n";
    
	while (true){
		cin >> input;

		if (input == "AddPlayer"){
			int player_id;
			cin >> player_id;
			string player_name;
			cin >> player_name;
            
			AddPlayer(player_id, player_name);
		}
        
		else if (input == "AddGame"){
			int game_id;
			cin >> game_id;
			string game_name;
			cin >> game_name;
        
            AddGame(game_id, game_name);
		}
        
		else if (input == "AddAchievement"){
			int game_id;
			cin >> game_id;
			int achievement_id;
			cin >> achievement_id;
			string achievement_name;
			cin >> achievement_name;
			int achievement_points;
			cin >> achievement_points;
            
            AddAchievement(game_id, achievement_id, achievement_name, achievement_points);
		}
        
		else if (input == "Plays"){
			int player_id;
			int game_id;
			string player_ign;
			cin >> player_id;
			cin >> game_id;
			cin >> player_ign;
            
            Plays(player_id, game_id, player_ign);
		}
        
		else if (input == "AddFriends"){
			int player_id_1;
			int player_id_2;
            cin >> player_id_1;
            cin >> player_id_2;
            
            AddFriends(player_id_1, player_id_2);
		}
        
		else if (input == "Achieve"){
			int player_id;
			int game_id;
			int achievement_id;
			cin >> player_id;
			cin >> game_id;
			cin >> achievement_id;
            
            Achieve(player_id, game_id, achievement_id);
		}
        
		else if (input == "FriendsWhoPlay"){
			int player_id;
			int game_id;
			cin >> player_id;
			cin >> game_id;
            
            FriendsWhoPlay(player_id, game_id);
		}
        
		else if (input == "ComparePlayers"){
			int player_id_1;
			int player_id_2;
			int game_id;
			cin >> player_id_1;
			cin >> player_id_2;
			cin >> game_id;

            ComparePlayers(player_id_1, player_id_2, game_id);
		}
        
		else if (input == "SummarizePlayer"){
			int player_id;
			cin >> player_id;
            
            SummarizePlayer(player_id);
		}
        
		else if (input == "SummarizeGame"){
			int game_id;
			cin >> game_id;
            
            SummarizeGame(game_id);
		}
        
		else if (input == "SummarizeAchievement"){
			int game_id;
			int achievement_id;
			cin >> game_id;
			cin >> achievement_id;
            
            SummarizeAchievement(game_id, achievement_id);
		}
	}
    
}

