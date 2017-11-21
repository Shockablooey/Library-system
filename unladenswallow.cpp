/********************************************************************* 
 ** Program Filename: unladenswallow.cpp
 ** Author: Chase Stubblefield
 ** Date: 30 April 2017
 ** Description: a computer system for a mini library
 ** Input: 4 different files 
 ** Output: information to shell and rewriting of files
 *********************************************************************/
#include "library.h"
#include "errorcheck.h"

void end_program(bool *again);
void pretty_login_stuff();

int main(int argc, char** argv){
	bool again = true;
	int choice;
	Error e; // Error class object so we can use its functions
	Library lib; // for access to class functions
	Library lib2 = lib;
	
	while(again == true){
		pretty_login_stuff();
		choice = e.userinput_int(0,3," "); // get a good int between 0 and 3

		if (choice == 1)
			lib.view_hours();	
		else if (choice == 2)
			lib.patron_login();
		else if (choice == 3)
			lib.librarian_login();	
		else
			end_program(&again);
	}

	return 0;
} // end of main function

/********************************************************************* 
 ** Function: pretty_login_stuff
 ** Description: purely aesthetics
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void pretty_login_stuff(){
	cout << endl << endl;
	cout << "====================================================================================================" << endl;
	cout << "| Welcome to the library.  What would you like to do?                                              |" << endl;
	cout << "====================================================================================================" << endl;
	cout << "|                                                                                                  |" << endl;
	cout << "|   View Library Hours (1)   |   Patron Login (2)   |   Librarian Login (3)   |      Quit (0)      |" << endl;
	cout << "|                                                                                                  |" << endl;
	cout << "====================================================================================================" << endl << "| ";		 
}
/********************************************************************* 
 ** Function: end_program
 ** Description: aesthetics and ends loop
 ** Parameters: bool for continuing while loop
 ** Pre-Conditions: proper function call
 ** Post-Conditions: bool is changed and loop ends
 *********************************************************************/
void end_program(bool *again){
	*again = false; // end while loop
	cout << "| Thank you for visiting the library.                                                              |" << endl;
	cout << "====================================================================================================" << endl;
}
