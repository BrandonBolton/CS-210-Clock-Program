/*	The SystemFunctions.cpp file contains all of the functions to
 * 	manipulate the clock. Functions are declared in the SystemFunctions.h file
 * 	to be used elsewhere.
 */

#include <iostream>
#include <string>
#include <chrono> // For cross platform pausing
#include <thread> // For cross platform pausing
#include <cstdlib>	// For cross platform clearing of screen	


#include "TimeFunctions.h"

using namespace std;

void SleepTime() {
	
	/*	The purpose of this function is to be called whenever
	 * 	the program needs to sleep for 1 second.
	 */
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void ClearScreen() {
	
	/* 	The purpose of this function is to clear the screen
	 * 	in order for the time from the clock to update. This method works
	 * 	on both Mac, Linux, and Windows.
	 */

	// Clears the screen on a Windows computer
	std::system("clear");
	std::system("cls");
}
