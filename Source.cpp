#include <iostream> //allows cout and cin to be used
#include <string> //allows strings to be used

#include "player.h" //includes the player class header
#include "game.h" //includes the game class header

using namespace std;

int main()
{
	string name1; //variable to temporarily hold player one's name.
	string name2; //variable to temporarily hold player two's name.

	int success_rate1 = 0; //variable to temporarily hold player one's success rate
	int success_rate2 = 0; //variable to temporarily hold player two' success rate

	//player one information
	cout << "Hello, welcome to 501!" << endl; //introduces the game to the players
	cout << "What is your name?" << endl;
	cin >> name1; //stores the first player's name into the name1 variable
	cout << "************************************" << endl;
	cout << name1 << ", what is your success rate?" << endl;
	cin >> success_rate1; //stores the first player's success rate into the success rate into the success_rate1 variable

	//player two information
	cout << "************************************" << endl;
	cout << "What is the other player's name?" << endl;
	cin >> name2; //stores the second player's name into the name2 variable
	cout << "************************************" << endl;
	cout << "What is their success rate?" << endl;
	cin >> success_rate2; //stores the second player's success rate into the success_rate2 variable
	cout << "************************************" << endl;

	//Displaying Rules to players.
	cout << "Your starting score is 501, in order to win, you need to reach 0 and have your last dart finish on the bullseye or a double." << endl;
	cout << "Each player will have three darts. Once these darts have been thrown, it is the next player's turn and so on until someone wins." << endl;
	cout << name1 << ", you will start first." << endl;

	//uses player class' constructor to assign variable data to player variables.

	player playerone(name1, success_rate1); //creates an instance for player one and stores player one's information into this.
	player playertwo(name2, success_rate2); //creates an instance for player two and stores player two's information into this.

	game NewGame; //creates an instance of the game class called NewGame.

	NewGame.init(&playerone, &playertwo); //initialising variables in game class and sending address of the player instances.
	NewGame.playGame(); //runs the game.

	return 0;
}