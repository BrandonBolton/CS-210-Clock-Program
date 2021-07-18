/*	Project: 3-1 Project One - Chada Tech
 *	
 *	Date: 2021-3-15
 *	Author: Brandon Bolton
 */

#include <iostream>
#include <string>
#include <chrono> // For cross platform pausing
#include <thread> // For cross platform pausing
#include <cstdlib>	// For cross platform clearing of screen
#include <conio.h>
#include <Windows.h>

#include "TimeFunctions.h"
#include "SystemFunctions.h"

using namespace std;

int main() {

	// Declare variables for user input and place holder times, setting time to 1:59:40 PM by default.
	char menuSelection = '0';
	int standardHour = 1, militaryHour = 13, sharedMinutes = 59, sharedSeconds = 40;
	
	// Loop that runs until user enters 4 as an option to quit. 
	while (menuSelection != 4) {
		
		DisplayTime(standardHour, militaryHour, sharedMinutes, sharedSeconds);

		DisplayMenu();

		cout << "\n\n\t\tSelect your option to edit the clocks.";

		if (kbhit()) {

			if (getch() == '1') {
				AddTimeValue(standardHour, militaryHour, sharedMinutes, sharedSeconds, 1);
				UpdateTime(standardHour, militaryHour, sharedMinutes, sharedSeconds);
			}

			if (getch() == '2') {
				AddTimeValue(standardHour, militaryHour, sharedMinutes, sharedSeconds, 2);
				UpdateTime(standardHour, militaryHour, sharedMinutes, sharedSeconds);
			}

			if (getch() == '3') {
				AddTimeValue(standardHour, militaryHour, sharedMinutes, sharedSeconds, 3);
				UpdateTime(standardHour, militaryHour, sharedMinutes, sharedSeconds);
			}

			if (getch() == '4') {
				cout << "\n\nProgram is exiting.\n\n";
				break;
			}
		}

		else {

			AddTimeValue(standardHour, militaryHour, sharedMinutes, sharedSeconds, 3);
			UpdateTime(standardHour, militaryHour, sharedMinutes, sharedSeconds);
			SleepTime();
			ClearScreen();
		}
	}
}


