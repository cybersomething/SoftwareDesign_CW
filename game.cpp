#include <cstdlib> //used for the random number generator
#include <iostream> //allows cin and cout to be used 
#include <string> //allows string to be used as a data type

#include "game.h" //includes the game class header

using namespace std;

game::game() //constructor left deliberately empty
{
}


game::~game()//constructor left deliberately empty
{
}

//this function assigns data to the variables needed for the game.
void game::init(player* p1, player* p2) //pointer variables passed in 
{
	standing_score = 0; //this variable holds the score achieved in the throw functions

	holding_score = 0; //this variable holds the score achieved in the throw functions, within the playGame() function

	player1 = p1; //player1 is now equal to the pointer variable
	player2 = p2; //player2 is now equal to the pointer variable

	random = 0;
}

//this function is used to simulate the user aiming and throwing at the bull on the board
int game::throw_bull(int success_rate) //success rate passsed in to the function
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate - 20) //if the random number generated is less than the success_rate-20, the bullseye will be hit.
	{
		standing_score = 50; //Bullseye hit, which is 50
		cout << "Bullseye hit!" << endl;
		return standing_score;
	}
	else if (random < 85) //if the random number generated is less than 85, the outer bull will be hit.
	{
		standing_score = 25; //outerbull hit, which is 25
		cout << "Outer Bull hit!" << endl;
		return standing_score;
	}
	else
	{
		standing_score = (1 + rand() % 20); //if the bull or the outer bull are not hit, the bullseye will not be hit and the standing score will be set to a single on the board
		cout << "Missed the bullseye, you hit, " << standing_score << endl;
		return standing_score;
	}
}

//this function is used to simulate the user aiming and throwing at a single on the board.
int game::throw_single(int success_rate, int d) //success rate and number to be aimed at passed in to the function
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate) //if random number generated is less than the player's success rate:
	{
		cout << "You hit your desired number! - " << d << endl; //single hit, display number chosen.
		standing_score = d; //set standing score to number chosen
		return standing_score;
	}
	else if (random < 92) //if random number generated is less than 92, 
	{
		standing_score = bd[0][d]; //dart has went to the left, calculate neighbour and set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 96) //if random number generated is less than 96, calculate neighbour and set as stading score
	{
		standing_score = bd[1][d]; //dart has went to the right, calculate neighbour and set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 98) //if random number generated is less than 98, calculate neighbour and set as standing score
	{
		standing_score = 2 * d; //dart has hit a double, multiply the chosen number by two and set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}//double hit
	else
	{
		standing_score = 3 * d; //dart has hit a triple, multiply the chosen number by three and set as standing score
		cout << "You scored - " << standing_score << endl;
	} //triple hit
}

//this function is used to simulate the player aiming and throwing for a double on the board
int game::throw_double(int success_rate, int d)
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate) //if random number is less than the player's success rate,
	{
		standing_score = 2 * d; //double hit on chosen number
		cout << "You hit your desired number! - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 85) //if random number is less than 85,
	{
		standing_score = 0; //dart board missed completely, standing score set to 0
		cout << "You missed the dart board! - " << endl;
		return standing_score;
	}
	else if (random < 90) //if random number is less than 90, 
	{
		standing_score = d; //double not hit, but single instead
		cout << "You missed, but you hit the single! - " << d << endl;
		return standing_score;
	}
	else if (random < 93) //if random number is less than 93,
	{
		standing_score = 2 * bd[0][d]; //dart has went to the left, calculate neighbour and set as standing score
		cout << "You scored - " << standing_score << endl;

	}
	else if (random < 96) //if random number is less than 96, 
	{
		standing_score = 2 * bd[1][d]; //dart has went to the right, calculte neighbout and set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 98) //if random number is less than 98,
	{
		standing_score = 3 * bd[0][d];//dart has hit a triple and has went to the left, calculate neighbour and multiply by 3, set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else
	{
		standing_score = 3 * bd[1][d]; //dart has hit a triple and has went to the right, calculate neighbour and multiply by 3, set as standing score
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
}

//this function is used to simulate the user aiming and throwing at a triple on the board
int game::throw_triple(int success_rate, int d)
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate) //if random number lower than success_rate
	{
		standing_score = 3 * d; //dart has hit the triple and chosen number, set as standing score
		cout << "You hit your chosen number - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 90) //if random number lower than 90
	{
		standing_score = d; //single hit on desired number
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 93) //if random number lower than 93, 
	{
		standing_score = 3 * bd[0][d]; //dart has still hit a treble but has moved to the left, calculate neighbour and multiply by 3, set as standing score
		cout << "You missed, but you still hit a treble- " << standing_score << endl;
		return standing_score;
	}
	else if (random < 96) //if random number lower than 96
	{
		standing_score = 3 * bd[1][d]; //dart has still hit a treble but has moved to the right, calculate neighbour adn set as standing_score
		cout << "You missed, but you still hit a treble - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 98) //if random number lower than 98
	{
		standing_score = bd[0][d]; //dart has hit a single but has moved to the left, calculate neighbour and set as standing_score
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	}//single of left hand score hit
	else
	{
		standing_score = bd[1][d]; //dart has hit as single but has moved to the right, calculate neighbout adn set as standing_score
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	}
}

bool game::throw_type_valid(char throw_type)
{
	if (throw_type == 'b' || throw_type == 's' || throw_type == 'd' || throw_type == 't')
	{
		valid_value = true;
	}
	else if (throw_type != 'b' || throw_type != 's' || throw_type != 'd' || throw_type != 't')
	{
		valid_value = false;
		cout << "Please enter a valid throw." << endl;
	}

	return valid_value;
}

bool game::aim_valid(int x)
{
	if ((x >= 1) && (x <= 20))
	{
		valid_value = true;
	}
	else if (!cin)
	{
		valid_value = false;
		cout << "Please enter a valid number." << endl;
	}
	else
	{
		valid_value = false;
		cout << "Please enter a valid number." << endl;
	}

	return valid_value;
}

int game::takeTurn(player* player, int &i) //this function is used as the player's turn, it contains the pointer for player and the counter's memory address location
{
	int d = 0; //initialise chosen number variable as 0
	char throw_type = 'A'; //initialise throw type variable as 'a'

	cout << "*****************************************" << endl;
	cout << player->getName() << ", your current score is, " << player->getCurrentScore() << endl; //get player name and current score by using pointers

	do {
		cout << "What multiplier would you like to aim at? Please enter, B for bullseye, S for single, D for double and T for Triple." << endl;
		cin >> throw_type; //get throw type from keyboard
		cout << "*****************************************" << endl;
	} while (throw_type_valid(throw_type) == false);

	switch (throw_type)
	{
	case 'b': //if character b is entered, run the throwBull function

		//Bullseye Function
		if (player->getCurrentScore() >= 50)
		{
			cout << "Bullseye chosen, " << endl;
			holding_score = throw_bull(player->getSuccess()); //pass player success into throwBull() function using player pointer and set it to the holding score
			cout << "You scored, " << holding_score << endl;
			player->setCurrentScore(player->getCurrentScore(), holding_score); //set player's current score as player's current score and holding score to calculate it.
		}
		else if (player->getCurrentScore() < 50)
		{
			cout << "Illegal Throw, try another." << endl; //let the player know that their throw was illegal
			i--; //add that turn back into their throw counter
		}
		break;
	case 's': //if character s is entered, run the throwSingle function
		do {
			cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
			cin >> d;
		} while (aim_valid(d) == false);

		//Singles Function
		if (player->getCurrentScore() >= 2) //if player's current score is more than or equal to 2
		{
			cout << "Single chosen - ";
			holding_score = throw_single(player->getSuccess(), d); //pass player success into throwSingle() function using player pointer and set it to the holding score
			if (holding_score < player->getCurrentScore()) //if the holding score is less than the current score
			{
				//valid throw, set current score to (currentscore - holding score)
				cout << "You scored, " << holding_score << endl;
				player->setCurrentScore(player->getCurrentScore(), holding_score);
			}
			else
			{
				//let player know it was illegal throw and add spoiled throw back into throw counter
				cout << "Illegal Throw, try another." << endl;
				i--;
			}

		}
		else if (player->getCurrentScore() < 2) //if player's current score is less than 2,
		{
			//let player know it was illegal throw and add spoiled throw back into throw counter
			cout << "Illegal Throw, try another." << endl;
			i--;
		}
		break;
	case 'd': //if character 'd' is entered, run the throwDouble() function
		do {
			cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
			cin >> d;
		} while (aim_valid(d) == false);
		//Doubles Throw
		cout << "Double chosen - ";
		holding_score = throw_double(player->getSuccess(), d);

		if (holding_score < player->getCurrentScore()) //if holding score is more than the player's current score
		{
			//legal throw, set current score to (currentscore - holdingscore)
			cout << "You scored, " << holding_score << endl;
			player->setCurrentScore(player->getCurrentScore(), holding_score);
		}
		else if (holding_score > player->getCurrentScore())
		{
			//let player know it was illegal throw and add spoiled throw back into throw counter
			cout << "Illegal throw, try another." << endl;
			i--;
		}
		else if (holding_score = player->getCurrentScore())
		{
			//player has won, set the player's current score to (currentscore - holdingscore)
			player->setCurrentScore(player->getCurrentScore(), holding_score);
		}
		break;
	case 't': //if character 't' is entered, run the throwTriple() function
		do {
			cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
			cin >> d;
		} while (aim_valid(d) == false);

		//Triple Throw
		if (player->getCurrentScore() >= 6) //if player's current score is more than or equal to 6
		{
			cout << "Triple chosen - ";
			holding_score = throw_triple(player->getSuccess(), d);

			if (holding_score > player->getCurrentScore()) //if holding score is more than player's current score
			{
				//let player know it was an illegal throw and add spoiled throw back into throw counter
				cout << "Illegal Throw, try another." << endl;
				i--;
			}
			else
			{
				//legal throw, set currentscore to (currentscore - holdingscore)
				cout << "You scored, " << holding_score << endl;
				player->setCurrentScore(player->getCurrentScore(), holding_score);
			}
		}
		else if (player->getCurrentScore() < 5)//if current score is less than 5
		{
			//let player know it was an illegal throw and add spoiled throw back into throw counter
			cout << "Illegal Throw, try another." << endl;
			i--;
		}
		break;

		return player->getCurrentScore(); //return player's current score
	}
}

int game::oddGuess(int j)
{
	int r = j % 2;
	bool isOdd = true;

	if (r == 0)
	{
		isOdd = false;
	}
	else
	{
		isOdd = true;
	}

	return isOdd;
}

int game::botTurn()
{
	int current_score = player2->getCurrentScore();
	char throw_type;

		for (int i = 1; i >= 0; --i)
		{
			for (int j = 20; j >= 0; --j)
			{
				if (current_score - 50 == 0) //if hitting bull will finish game, throwBUll.
				{ 
					botTakeTurn('b', 0);
					return 0;
				}
				else if (current_score - (bd[i][j] * 2) == 0) //if hitting double will finish game, hit double
				{ 
					botTakeTurn('d', j);
					return 0;
				}
				else if (current_score - (j * 3) >= 2) //if hitting triple brings the score down to 2, hit triple
				{ 
					botTakeTurn('t', j);
					return 0;
				}
				else if (current_score - (j * 2) >= 2) //if hitting triple is too much but a double brings the score down to 2, hit double
				{
					botTakeTurn('d', j);
					return 0;
				}
				else if (current_score - j >= 2 && oddGuess(j) == true) //if hitting a single will leaves at least 2 aim is an odd number, hit single
				{ 
					botTakeTurn('s', j); 
					return 0;
				};
			}
		}
}

int game::botTakeTurn(char throw_type, int dart_number)
{
		int d = 0; //initialise chosen number variable as 0

		switch (throw_type)
		{
		case 'b': //if character b is entered, run the throwBull function

			//Bullseye Function
				cout << "Bullseye chosen, " << endl;
				holding_score = throw_bull(player2->getSuccess()); //pass player success into throwBull() function using player pointer and set it to the holding score
				cout << "You scored, " << holding_score << endl;
				player2->setCurrentScore(player2->getCurrentScore(), holding_score); //set player's current score as player's current score and holding score to calculate it.
			
			break;
		case 's': //if character s is entered, run the throwSingle function
			//Singles Function
			cout << "Single chosen - ";
			holding_score = throw_single(player2->getSuccess(), dart_number); //pass player success into throwSingle() function using player pointer and set it to the holding score
		
			cout << "You scored, " << holding_score << endl;
			player2->setCurrentScore(player2->getCurrentScore(), holding_score);

			break;
		case 'd': //if character 'd' is entered, run the throwDouble() function
			//Doubles Throw
			cout << "Double chosen - ";
			holding_score = throw_double(player2->getSuccess(), dart_number);

			if (holding_score < player2->getCurrentScore()) //if holding score is more than the player's current score
			{
				//legal throw, set current score to (currentscore - holdingscore)
				cout << "You scored, " << holding_score << endl;
				player2->setCurrentScore(player2->getCurrentScore(), holding_score);
			}
			else if (holding_score = player2->getCurrentScore())
			{
				//player has won, set the player's current score to (currentscore - holdingscore)
				player2->setCurrentScore(player2->getCurrentScore(), holding_score);
			}
			break;
		case 't': //if character 't' is entered, run the throwTriple() function
			//Triple Throw
			if (player2->getCurrentScore() >= 6) //if player's current score is more than or equal to 6
			{
				cout << "Triple chosen - ";
				holding_score = throw_triple(player2->getSuccess(), dart_number);
				cout << "You scored, " << holding_score << endl;
				player2->setCurrentScore(player2->getCurrentScore(), holding_score);
				
			}
			return player2->getCurrentScore(); //return player's current score
		}
}

void game::playGame()
{
	int i = 0; //set turn counter to 0;
	bool loop = true; //set loop to true

	while (loop) //while loop condition is true...
	{
		for (i = 0; i < 3; i++) //gives player1 3 turns
		{
			if (player1->getCurrentScore() == 0) //if player one's current score is 0
			{
				loop = false; //break the while loop
				break; //break out of for loop
			}
			else if (player2->getCurrentScore() == 0) //if player two's current score is 0
			{
				loop = false; //break the while loop
				break; //break out of for loop
			}

			takeTurn(player1, i); //run takeTurn() function and pass in player1 and i
		}

		//display player's final score for the round
		cout << "*****************************************" << endl;
		cout << player1->getName() << ", your final score this round is: " << player1->getCurrentScore() << endl;
		cout << "*****************************************" << endl;

		for (i = 0; i < 3; i++) //gives player2 3 turns
		{
			if (player1->getCurrentScore() == 0) //if player one's current score is 0
			{
				loop = false; //break the while loop
				break; // break the for loop
			}
			else if (player2->getCurrentScore() == 0) //if player two's current score is 0
			{
				loop = false; //break the while loop
				break; //break the for loop
			}

			botTurn(); //run bot's turn
		}

		//display player's final score for the round
		cout << "*****************************************" << endl;
		cout << player2->getName() << ", your final score this round is: " << player2->getCurrentScore() << endl;
		cout << "*****************************************" << endl;
	}

	if (player1->getCurrentScore() == 0) //if player one's current score is 0
	{
		dartsWinner(player1->getName());
	}
	else if (player2->getCurrentScore() == 0) //if player two's current score is 0
	{
		dartsWinner(player2->getName());
	}
}

int game::dartsWinner(string name) //declares who the winner is
{
	cout << "Congratulations, " << name << ", you have won this game!" << endl; //declare the winner using their name

	return 0; //exit the program
}


