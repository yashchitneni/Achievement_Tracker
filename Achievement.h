//
//  Achievement.h
//  assignment_tracker
//
//  Created by Yash Chitneni on 1/22/14.
//  Copyright (c) 2014 yash_chitneni. All rights reserved.
//

#ifndef assignment_tracker_Achievement_h
#define assignment_tracker_Achievement_h

#include <iostream>
#include <vector>

using namespace std;

class Achievement {
    
public:
	Achievement(){
		achievement_id = -1;
		achievement_name = "";
		achievement_points = -1;
        achieve_times_completed = 0;
	}
    
	Achievement(int id, string name, int points, int times_completed){
		achievement_id = id;
		achievement_name = name;
		achievement_points = points;
        achieve_times_completed = times_completed;
	}
    
    int getId(){
		return achievement_id;
	}
    
	string getName() {
		return achievement_name;
	}
    
    int getPoints() {
        return achievement_points;
    }
    
    void setAchievementTimes() {
        achieve_times_completed++;
    }
    
private:
	int achievement_id;
	string achievement_name;
	int achievement_points;
    int achieve_times_completed;
};

#endif
