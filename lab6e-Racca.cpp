// Emerson Racca
// 10/06/2021
// Lab 6e - Pick a Winner

/*
Lab... create an app that chooses a random person from a list of user defined people.

1. Ask the user for names of people in the drawing.  In a looping structure, populate an array of strings with the user names.  Make the size 50 and break out of the loop if the user wants to input less than 50 names.

2. Choose a random person from this list and display the winner on screen.

3. Ask the user if they would like to pick another winner from the SAME LIST.
*/

#include<iostream>
#include<cstdlib> // srand(), rand()
#include<ctime> // time()
#include<string>

using namespace std;


int main(void) {
	srand((unsigned int) time(0));

	char goAgain, enterAnother;

	const int size = 50;
	int peopleNum = 0; // Tracks how many was put in the array.
	string person[size];

	cout << "Pick a Winner\n";
	cout << "Enter up to 50 names, and this app picks a winner.\n\n";

	enterAnother = 'y'; // To make sure that at least 2 names are entered.

	do {
		cout << "\nEnter a name: ";
		getline(cin, person[peopleNum]);

		//cout << "Index " << peopleNum << " = "<< person[peopleNum] << endl; // For testing.

		peopleNum++;

		// 2 entries is the needed minimum to pick a valid winner.
		// Maximum is 50.
		if (peopleNum >= 50){
			cout << "\nMaximum entries reached. You have 50 names.\n";
			enterAnother = 'n';
		}
		else if (peopleNum > 1) { 
			cout << "\nWould you like to add another name (y or n)? ";
			cin >> enterAnother;
			cin.ignore();
		}
	} while (enterAnother == 'y');

	cout << "\n---------------------------------------------";
	cout << "\nThere were " << peopleNum << " names added to the list.\n";

	do {
		cout << "\nThe winner is: " << person[rand() % (peopleNum)]; // Possible repetition of a winner.

		cout << "\n\nWould you like to pick another winner from the list (y or n)? ";
		cin >> goAgain;
	} while (goAgain == 'y');
	
	return 0;
}