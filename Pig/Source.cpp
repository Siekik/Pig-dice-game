// MP2 (Pig) - 10/20/2022 - Jonathan Heinlein
//This is a dice rolling game where a player and bot compete to get a global score to 100 or above
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

//Needed functions
int rollDie(void);
bool isTurnScoreLost(int die1value, int die2value);
bool isTotalScoreLost(int die1value, int die2value);
char getUserInput(void);
bool isWinningScore(int score);

int main() {
	int won = 0;
	int dievalue;
	int die2value;
	int score = 0;
	int currentscore;

	// Odd turn number indicates player turn
	int turn = 1;
	
	//Loops while game is still going
	while (won == 0) {
		int i = 0;
		srand(time(0));
		char start;
		
		//Player turn:
		if (turn % 2 != 0) {
			int reroll = 1;
			currentscore = 0;
			
			//Making it wait for the player makes it easier to look at
			cout << "Enter anything to start your turn.";
			cin >> start;
			while (reroll == 1) {
				
				//Rolling dice and show results
				
				dievalue = rollDie();
				die2value = rollDie();

				cout << "You rolled a " << dievalue << " and a " << die2value;
				
				isTurnScoreLost(dievalue, die2value);
				isTotalScoreLost(dievalue, die2value);
				
				//Rections for different game events
				if (isTurnScoreLost(dievalue, die2value) == false && isTotalScoreLost(dievalue, die2value) == false) {
				//current score refers to the dice total for the turn. Not the whole game
					currentscore = currentscore + dievalue + die2value;
					cout << "\nYour score is: " << currentscore;
					reroll = getUserInput();
					if (reroll == 0) {
						//As long as the player has not rolled a 1 and finishes roll, score is updated
						score = score + currentscore;
					}
				}
				else if (isTurnScoreLost(dievalue, die2value) != false) {
					cout << "\nYou rolled a 1, you do not score";
					reroll = 0;
				}
				else if (isTotalScoreLost(dievalue, die2value) != false) {
					cout << "\nYou rolled two 1's, score reset";
					score = 0;
					reroll = 0;
				}
			}
			//Switches turn
			turn++;
			//Checks if the game has been won by the player
			if (isWinningScore(score) == false) {
				//Updates progress of the game
				cout << "\nCurrent score: " << score << endl << endl;
			}
			if (isWinningScore(score) != false) {
				cout << "YOU WIN! Final score is: " << score << endl;
				return 1;
			}
		}
		//Bot turn:
		if (turn % 2 == 0) {
			int reroll = 1;
			currentscore = 0;
			//Giving the player control of when the bot rolls makes it easier to look at
			cout << "Enter anything to start bot's turn.";
			cin >> start;
			while (reroll == 1) {

				dievalue = rollDie();
				die2value = rollDie();

				cout << "Bot rolled a " << dievalue << " and a " << die2value;

				isTurnScoreLost(dievalue, die2value);
				isTotalScoreLost(dievalue, die2value);

				if (isTurnScoreLost(dievalue, die2value) == false && isTotalScoreLost(dievalue, die2value) == false) {
					currentscore = currentscore + dievalue + die2value;
					cout << "\nBot score is: " << currentscore << endl;
					if (currentscore < 20) reroll = 1;
					if (currentscore >= 20) reroll = 0;
					if (reroll == 0) {
						score = score + currentscore;
					}
				}
				else if (isTurnScoreLost(dievalue, die2value) != false) {
					cout << "\nBot rolled a 1, Bot doesn't score";
					reroll = 0;
				}
				else if (isTotalScoreLost(dievalue, die2value) != false) {
					cout << "\nBot rolled two 1's, score reset";
					score = 0;
					reroll = 0;
				}
			}
			turn++;
			//checks if game has been won by the bot
			if (isWinningScore(score) == false) {
				cout << "\nCurrent score: " << score << endl << endl;
			}
			if (isWinningScore(score) != false) {
				cout << "Bot WIN! Final score is: " << score << endl;
				return 1;
			}
		}
	}
}

int rollDie(void) {
	//Dice roll program
	int die1;

	die1 = rand() % (6 - 1 + 1) + 1;
	return die1;
}
bool isTurnScoreLost(int die1value, int die2value) {
	//Checks if the player rolled a 1
	if (die1value == 1 || die2value == 1) {
		return true;
	}
	else return false;
}
bool isTotalScoreLost(int die1value, int die2value) {
	//checks if the player rolled two 1's
	if (die1value == 1 && die2value == 1) {
		return true;
	}
	else return false;
}
char getUserInput(void) {
	//asks player to reroll or not
	char menuchoice;
	int result;

	cout << "\nInput R to roll again or Q to stop: ";
	cin >> menuchoice;

	switch (menuchoice)
	{
	default:
	//I made the deafault reroll again because it was funny
		cout << "Unknown input, rolling again";
		return 1;
		break;
	//R's for if the player rerolls
	case('r'): {
		return 1;
		break;
		}
	case('R'): {
		return 1;
		break;
	}
	//Q's for if player cashes out
	case('q'): {
		return 0;
		break;
	}
	case('Q'): {
		return 0;
		break;
	}
	}
}
bool isWinningScore(int score) {
//checks if current score is or is above 100
	if (score >= 100) {
		return true;
	}
	else return false;
}
