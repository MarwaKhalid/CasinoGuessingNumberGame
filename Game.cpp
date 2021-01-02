#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int main() {
	bool replay; // declaring boolean called replay
	string answer; // declaring string called answer
	int money; // declaring an int called money

	// Welcome statement
	cout << "Welcome to Casino Number Guessing Game!\n"
		<< "\nHere are the rules:"
		<< "\n1. You will enter the amount of money you wish to play with. You must start with $5000"
		<< "\n2. The computer will generate a random hidden number, and you must guess what the number is (1-10)"
		<< "\n3. If your number matches you win $10,000! and the game ends."
		<< "\nHowever, if you guess wrong, you will lose $5000 and you can play until your money runs out or quit.\n\n"
		<< "Let's start!"
		<< "\nPlease enter the amount of money you wish to play with (starting at $5000): ";
	cin >> money; // storing the input in int money

	while (money < 5000) { // while the money entered is less than 5000 keep prompting
		cout << "Sorry, the amount you entered is less than 5000, please try again: ";
		cin >> money; // storing the input in int money
	}

	do {
		int randomNum = rand() % 10 + 1; // Generating a random number (1-10 inclusively)
		answer = "yes"; // answer becomes yes
		replay = true; // replay becomes true

		int num; // declaring an int called num
		cout << "Guess the number you think the computer has generated. The values are inclusively 1-10: ";
		cin >> num; // storing the input in int num

		while (num > 10 || num < 1) { // if the number isnt 1-10 inclusively then keep prompting
				cout << "You entered a value outside of 1-10, please re-enter: ";
				cin >> num; // storing the input in int num
			}

		if (num == randomNum) { // if the user guess correct number
			money = money + 10000; // adding $10000 to their initial amount
			cout << "\nCongratulations! You've won $10,000"
				<< "\nThis is the amount you've ended the game with: " << money
				<< "\nThank you for playing!";
			break; // breaking out of the do-while loop
		}
		else { // if the user didnt guess the correct number
			cout << "\nYou guessed the wrong number!";
			money = money - 5000; // removing $5000 from their initial amount
			if (money < 5000) { // if the amount they have left is less than $5000
				cout << " Sorry, you do not have enough money to play again."
					<< "\nThis is the amount you've ended the game with: " << money
					<< "\nThank you for playing!";
				break; // breaking out of the do-while loop
			}
			else { // they have enough money to replay
				cout << "\nWould you like to re-enter a value or quit, please enter \"q\" if you wish to quit: ";
				cin >> answer; // storing the answer in string answer

				if (answer == "q") { // if the answer is "q"
					replay = false; // replay becomes false
					cout << "\nThis is the amount you've ended the game with: " << money
						<< "\nThank you for playing!";
				}
				else { // if the answer is anything other than "q"
					cout << "\nOkay, time to replay!\n";
				}
			}
		}
	} while (replay != false); // keep looping until replay becomes false
	return 0;
}