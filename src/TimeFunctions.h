/*	Declares functions to be used for clock functions from TimeFunctions.cpp.
 */

int AddTimeValue(int& standardHour, int& militaryHour, int& sharedMinutes, int& sharedSeconds, int selection);
int UpdateTime(int& standardHour, int& militaryHour, int& minutes, int& seconds);
int DisplayTime(int standardHour, int militaryHour, int minutes, int seconds);
void DisplayMenu();
