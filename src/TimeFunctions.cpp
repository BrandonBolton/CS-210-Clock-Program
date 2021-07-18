/*	The TimeFunctions.cpp file contains all of the functions to
 * 	manipulate the clock. Functions are declared in the TimeFunctions.h file
 * 	to be used elsewhere.
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "SystemFunctions.h"

using namespace std;

int AddTimeValue(int& standardHour, int& militaryHour, int& sharedMinutes, int& sharedSeconds, int selection) {

	/*	The purpose of this function is to handle adding units of time
	*	based off of user input. The options are derived from the
	*	DisplayMenu() function.
	*	
	*	Parameters: 
	*		standardHour -- hours for the 12 hour clock
	*		militaryHour -- hours for the 24 hour clock
	*		sharedMinutes -- shared minutes between 12 and 24 hour clocks
	*		sharedSeconds -- shared seconds for both 12 and 24 hour clocks
	*		selection -- menu selection for how much time to add
	*/

	// Adds an hour to both the 12 hour and 24 hour clocks.  
	if (selection == 1) {
		 standardHour += 1;
		 militaryHour += 1;
	}

	// Adds a minute to current time
	else if (selection == 2) {
		sharedMinutes += 1;
	}
	
	// Adds a second to current time
	else if (selection == 3) {
		sharedSeconds += 1;
	}

	// Adds zero time to the clock if any other number is input 
	else {
		sharedSeconds += 0;
	}
}

int UpdateTime(int& standardHour, int& militaryHour, int& minutes, int& seconds) {
	/*	The purpose of this function is to keep the clock showing proper times.
	 *  Each of the variables are passed through and returned automatically.
	 *
	 * 	Parameters:
	 * 		standardHour -- The hour on a 12 hour clock
	 * 		militaryHour -- The hour on a 24 hour clock
	 * 		minutes -- The minutes value shared between the two clocks
	 * 		seconds -- The seconds value shared between the two clocks
	 */

	// If seconds go over 59, it adds 1 more minute and resets seconds.
	if (seconds > 59) {
		minutes += 1;
		seconds = 0;
	}

	// If minutes go over 59, it adds one more hour to both 12 and 24 hour clocks and resets minutes.
	if (minutes > 59) {
		standardHour += 1;
		militaryHour += 1;
		minutes = 0;
	}

	// If hours go over 12 or 24, both roll over to 1.
	if (standardHour > 12) {
		standardHour = 1;
	}
	if (militaryHour > 24) {
		militaryHour = 1;
	}
}

int DisplayTime(int standardHour, int militaryHour, int minutes, int seconds) {
	
	/*	The purpose of this function is to output the current time
	 * 	in 12 and 24 hour formats to user.
	 *
	 * 	Parameters:
	 * 		standardHour -- The hour on a 12 hour clock
	 * 		militaryHour -- The hour on a 24 hour clock
	 * 		minutes -- The minutes value shared between the two clocks
	 * 		seconds -- The seconds value shared between the two clocks*
	 */

	/* 	This block of code decides to display either AM
	 * 	or PM based off of the hours the 24 clock has.
	 */
	string typography;
	if (militaryHour >= 12 && militaryHour <= 24) {
		typography = " PM";
		}
	if (militaryHour >= 1 && militaryHour < 12) {
		typography = " AM";
		}

	// The clock face
	cout << "\n\n\n\n\t*********************************\t*********************************" << endl;
	cout << "\t*\t  12-Hour Clock\t\t*\t*\t  24-Hour Clock\t\t*" << endl;
	cout << "\t*\t    " << standardHour << ":" << minutes << ":" << seconds << typography << "\t\t*";
	cout << "\t*\t     " <<militaryHour << ":" << minutes << ":" << seconds << "\t\t*" << endl;
	cout << "\t*********************************\t*********************************" << endl;
}

void DisplayMenu() {
	
	/*	The purpose of this function is to output the main menu.
	*	to the user. Options are for adding hours, minutes, and seconds,
	*	or quit the program.
	*/

	cout << "\n\n\t*********************************" << endl;
	cout << "\t*\t1 - Add One Hour\t*" << endl;
	cout << "\t*\t2 - Add One Minute\t*" << endl;
	cout << "\t*\t3 - Add One Second\t*" << endl;
	cout << "\t*\t4 - Exit the program\t*" << endl;
	cout << "\t*********************************" << endl;
}
