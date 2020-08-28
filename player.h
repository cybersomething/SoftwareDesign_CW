#pragma once //this means the file will only be used once during a compilation
#include <iostream> //allows cin and cout to be used
#include <string> //allows string to be used as a data type

using namespace std;

class player
{
	//initialising the variables and functions required for the player class
public:
	string PlayerName;

	int current_score;

	int success_rate;

	player(string PlayerName, int success); //constructor with variables to be passed in declared
	~player();

	void setCurrentScore(int x, int y); //current score setter with variable types to be passed in declared

	int getCurrentScore();

	string getName();

	int getSuccess();
};