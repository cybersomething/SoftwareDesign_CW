#pragma once //this means the file will only be used once during a compilation

#include <iostream> //allows cin and cout to be used
#include <string> //allows string to be used as a data type
#include "player.h" //allows game to access the variables in player class 

using namespace std;

class game
{
public:
	//initialising the variables and functions required for the game class
	game();
	~game();

	//declaring and initialising the 'board'
	int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 }, { 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };;

	int success_rate;

	int standing_score;

	int holding_score;

	int random;

	int oddGuess(int j);

	bool valid_value = false;

	player* player1; //creates a pointer variable called player1
	player* player2; //creates a pointer variable called player2

	int takeTurn(player*, int&); //declares the pointer and the pointer address which is needed for the takeTurn variable.

	int botTurn();
	 
	int botTakeTurn(char throw_type, int dart_number);

	void playGame();

	int dartsWinner(string name); //declares the name variable needed for dartsWinner() function

	void init(player*, player*); //declares the pointers needed for the init() function

	//throws required for the game and declaring the variables needed to be passed in
	int throw_bull(int success_rate);
	int throw_single(int success_rate, int d);
	int throw_double(int success_rate, int d);
	int throw_triple(int success_rate, int d);

	bool throw_type_valid(char a);
	bool aim_valid(int x);
};