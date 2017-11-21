/********************************************************************* 
 ** ERRORCHECK. C P P 
 *********************************************************************/
#include "errorcheck.h"

/********************************************************************* 
 ** Function: userinput_int
 ** Description: reprompts until user gives good input and returns it
 ** Parameters: upper bound, lower bound, and prompt
 ** Pre-Conditions: proper function call
 ** Post-Conditions: an integer within bounds is given
 *********************************************************************/
int Error::userinput_int(const int &lowerBound, const int &upperBound, string prompt){
	bool good = true; // assume input is good
	char userInput[256];
	int tempInt;
		
	do{
		good = true; // assume good at beginning of each iteration
		cout << prompt;
		cin >> userInput;
		for(int i=0; i < strlen(userInput); i++)
			if(userInput[i] < '0' || userInput[i] > '9')
				good = false; // if not all numbers, fail
			else{
				tempInt = atoi(userInput);
				if (tempInt < lowerBound || tempInt > upperBound)
					good = false;
			}
	}while(good == false); // go until we get a good int

	return tempInt;
}
