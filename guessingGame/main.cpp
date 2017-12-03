/*-----------------------------------------------------------------------------

Name: Kieran Hodge

Date: 04.12.2014

Lab number: 3

--------------------------------------------------------------------------------
Program Description: This Program will allow the user to guess a number between
0 and 100 within 5 attempts, once the user uses all of their attempts the program 
will prompt the user to restart the program, i will also implement a validation
system which will only allow the user to input numerical value into the guessing
if statements.
--------------------------------------------------------------------------------*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

int guess, randomNumber;		

int main ()
{
	cout << setw (59) << "************Guessing Game************\n\n";
	cout << setw (45) << "Instructions\n";
	cout << setw (75) << "In this game you will need to enter a number between 0 and 100\n";
	cout << setw (55) << "You only have 5 Attempts!\n\n\n";

	// This starts the random number generator.
	srand (time(0));

	while (true)
	{
		// This is where i am setting the parameters for the generator
		randomNumber = rand() % 100 + 0;
		int attempts = 0;
		char answer;  
		string validationString;

		// The Loop that allows the user to input a number whether thier input is above or bellow the number generated.
		// This Loop also includes the validation loop as well.
		while (true)
		{
			system ("color 07");
			//cout << randomNumber << endl; // Used for Debugging.
			cout << setw (38) << "Enter a Number (" << 5 - attempts << " Attempts left): ", cin >> guess;
			cin.ignore();
			while (cin.fail())
			{
				cin.clear();
				getline (cin, validationString);
				system ("color 04");
				cout << setw (64) << "Invalid Input, Please Enter a Numeric Value: ", cin >> guess;
			}
			if (attempts >= 5){
				break;
			}

			if (guess > randomNumber) {
				system ("color 04");
				cout << setw (63) << "You guessed too high enter another number: \n";
				Sleep (500);
			}
			else if (guess < randomNumber){
				system ("color 04");					
				cout << setw (63) << "You guessed too low, enter another number: \n";
				Sleep (500);
			}
			if (guess == randomNumber) {
				system ("color 02");
				cout << setw (50) << "You guessed correctly!\n";
				Sleep (800);
				break;
			}
			attempts++;
			// Checks attempts and if the user has run out this will be displayed.
			if(attempts >= 5) {
				system ("color 04");
				cout << setw (53) << "You have no more attempts\n\n";
				Sleep (2000);
				break;
			}
		}
		// The following Loop displays the restart function.
		while(true) { 
			system ("color 07");
			cout << setw (60) << "Would you like to play again (y/n)\n ";
			cin >> answer;

			// Defining the characters that the user can use, if Y it sends the user back through the program, if N then it will bring up
			// an message and end the program.
			if(answer == 'y' || answer == 'Y' || answer == 'n'|| answer == 'N') {
				system ("cls");
				break;
			}
			else
			system ("color 04");
			cout << setw (47) << "Invalid input\n\n";
			Sleep (500);
		}
		if (answer == 'n' || answer == 'N') {
			system ("color 05");
			cout << "\n\n\n\n\n\n";
			cout << setw (60) << "Thank you for playing, See you next time!";
			Sleep (2000);		
			break;
		}
	}
}