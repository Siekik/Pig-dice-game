#include <iostream>
#include <time.h>
#include <string>
using namespace std;

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

	while (won == 0) {
		int i = 0;
		srand(time(0));
		char start;

		if (turn % 2 != 0) {
			int reroll = 1;
			currentscore = 0;
			cout << "Enter anything to start your turn.";
			cin >> start;
			while (reroll == 1) {

				dievalue = rollDie();
				die2value = rollDie();

				cout << "You rolled a " << dievalue << " and a " << die2value;
				
				isTurnScoreLost(dievalue, die2value);
				isTotalScoreLost(dievalue, die2value);

				if (isTurnScoreLost(dievalue, die2value) == false && isTotalScoreLost(dievalue, die2value) == false) {
					currentscore = currentscore + dievalue + die2value;
					cout << "\nYour score is: " << currentscore;
					reroll = getUserInput();
					if (reroll == 0) {
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
			turn++;
			if (isWinningScore(score) == false) {
				cout << "\nCurrent score: " << score << endl << endl;
			}
			if (isWinningScore(score) != false) {
				cout << "YOU WIN! Final score is: " << score << endl;
				return 1;
			}
		}
		if (turn % 2 == 0) {
			int reroll = 1;
			currentscore = 0;
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
	int die1;

	die1 = rand() % (6 - 1 + 1) + 1;
	return die1;
}
bool isTurnScoreLost(int die1value, int die2value) {
	if (die1value == 1 || die2value == 1) {
		return true;
	}
	else return false;
}
bool isTotalScoreLost(int die1value, int die2value) {
	if (die1value == 1 && die2value == 1) {
		return true;
	}
	else return false;
}
char getUserInput(void) {
	char menuchoice;
	int result;

	cout << "\nInput R to roll again or Q to stop: ";
	cin >> menuchoice;

	switch (menuchoice)
	{
	default:
		cout << "Unknown input, rolling again";
		cin >> menuchoice;
		break;
	case('r'): {
			return 1;
			break;
		}
	case('R'): {
		return 1;
		break;
	}
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
	if (score >= 100) {
		return true;
	}
	else return false;
}