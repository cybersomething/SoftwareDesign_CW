#include <iostream> //allows cin and cout to be used
#include "player.h" //includes header for this class

using namespace std;

player::player(string PlayerName, int success) //using constructor to get inputted data from main function
{
	this->PlayerName = PlayerName; //assigning data from main to class variable PlayerName with class pointer
	this->success_rate = success; //assigning data from main to class variable success with class pointer
	current_score = 501; //sets current score to 501 so score is at 501 when new game takes place.
}

player::~player() //deconstructor left empty deliberately
{
}

//setters

void player::setCurrentScore(int x, int y) //setter used to calculate new current_score after legal dart throw
{
	current_score = x - y; //current_score = (variable passed in - variable passed in);
}

//getters

int player::getCurrentScore() //getter used to return current score when used in game class
{
	return current_score;
}

string player::getName() //getter used to return current score when used in game class
{
	return PlayerName;
}

int player::getSuccess() //getter used to return current score when used in game class
{
	return success_rate;
}
