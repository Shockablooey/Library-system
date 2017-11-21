/********************************************************************* 
 ** LIBRARY. C P P 
 *********************************************************************/
#include "library.h"

/********************************************************************* 
 ** Function: patron_menu
 ** Description: menu for the patron to choose between function calls
 ** Parameters: name and id
 ** Pre-Conditions: proper function call
 ** Post-Conditions: functions are called in looping fashion
 *********************************************************************/
void Library::patron_menu(const string inputName, const string inputID){
	int choice;
	bool again = true;
	
	p.set_name(inputName);
	p.set_id(inputID);
	
	while(again == true){
		p.patron_display();
		choice = e.userinput_int(0,5," "); // get a good input
		if(choice == 0)
			again = false; // end loop and go back to root menu
		else if(choice == 1)
			c.checkout_book(p.get_name()); // call function in cart
		else if(choice == 2)
			p.view_own();
		else if(choice == 3)
			p.search();
		else if(choice == 4)
			c.return_check(p.get_name()); // call function in cart
		else if(choice == 5)
			p.view_all();
		else	
			cout << "Dangit. errorchecker did not work." << endl;
	}
	
}
/********************************************************************* 
 ** Function: patron_login
 ** Description: compares user input with external file for proper credientials
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: a good name and id is sent to patron_menu
 *********************************************************************/
void Library::patron_login(){
	string userInput;
	string temp1;
	string temp2;
	ifstream input; // OPEN INPUT
	input.open("patrons");
	bool bad = 1;
	
	cout << "Name? ";
	cin.ignore();
	getline(cin, userInput); // receive user input

	while(!input.eof()){
		getline(input,temp1,'|'); // take a name
		if (temp1 == userInput){ // if match
			cout << "ID Number? ";
			getline(cin, userInput); // receive user input
			getline(input,temp2,'|'); // take ID
			if (temp2 == userInput){ // if match
				bad = 0;
				patron_menu(temp1, temp2); // call the menu, giving name and id
				input.close(); // CLOSE INPUT
			}
		}
		else
			getline(input,temp1,'|'); // get the ID and don't do anything with it
			
		getline(input,temp1); // move to next name regardless
	}
	if(bad != 0)
		cout << "We were unable to find a match in our database." << endl; // if match, while loop will not exit
	return;
}
/********************************************************************* 
 ** Function: librarian_menu
 ** Description: menu for the librarian, chooses between functions and loops
 ** Parameters: name and id of librarian
 ** Pre-Conditions: name and id are given
 ** Post-Conditions: functions are executed in looping fashion
 *********************************************************************/
void Library::librarian_menu(const string inputName, const string inputID){
	int choice;
	bool again = true;
	
	l.set_name(inputName);
	l.set_id(inputID);
	
	while(again == true){
		l.librarian_display();
		choice = e.userinput_int(0,5," "); // get a good input
		if(choice == 0)
			again = false; // end loop and go back to root menu
		else if(choice == 1)
			l.add_books();
		else if(choice == 2)
			l.view_checkouts();
		else if(choice == 3)
			change_hours();
		else if(choice == 4)
			l.remove_books();
		else
			cout << "Dangit. errorchecker did not work." << endl;
	}
}
/********************************************************************* 
 ** Function: librarian_login
 ** Description: compares user input with external file for proper credientials
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: a good name and id is sent to librarian_menu
 *********************************************************************/
void Library::librarian_login(){
	string userInput;
	string temp1;
	string temp2;
	ifstream input; // OPEN INPUT
	input.open("librarians");
	bool bad = 1;
	
	cout << "Name? ";
	cin.ignore();
	getline(cin, userInput); // receive user input

	while(!input.eof()){
		getline(input,temp1,'|'); // take a name
		if (temp1 == userInput){ // if match
			cout << "ID Number? ";
			getline(cin, userInput); // receive user input
			getline(input,temp2,'|'); // take ID
			if (temp2 == userInput){ // if match
				bad = 0;
				librarian_menu(temp1, temp2); // call the menu, giving name and id
				input.close(); // CLOSE INPUT
			}
		}
		else
			getline(input,temp1,'|'); // get the ID and don't do anything with it
		getline(input,temp1); // move to next name regardless
	}
	if(bad != 0)
		cout << "We were unable to find a match in our database." << endl; // if match, while loop will not exit
	return;
}
/********************************************************************* 
 ** Function: cart copy constructor 
 ** Description: takes an old lib and deep copies
 ** Parameters: lib to be copied
 ** Pre-Conditions: source lib has been created
 ** Post-Conditions: copy lib is created
 *********************************************************************/
Library::Library(const Library &oldLib){ // cart c is passed in and named "oldLibrary"
	if (oldLib.numBooks == 0){
		books = NULL;
		numBooks = 0;
	}
	else{ 
		numBooks = oldLib.numBooks;
		cout << numBooks << endl;
		books = new book[numBooks]; // create array 
		for(int i=0; i < numBooks; i++){ // fill each element of the 1D array
			books[i].title = oldLib.books[i].title;
			books[i].author = oldLib.books[i].author;
			books[i].year = oldLib.books[i].year;
			books[i].numCopies = oldLib.books[i].numCopies;
		}
	}	
}
/********************************************************************* 
 ** Function: copy assignment overload
 ** Description: takes an old lib and deep copies
 ** Parameters: cart to be copied
 ** Pre-Conditions: source lib has been created
 ** Post-Conditions: copy lib is created
 *********************************************************************/
void Library::operator=(const Library &oldLib){ // library lib is passed in and named "oldLib"
	
	delete[]books; // delete the old books array so we can make a proper copy
	
	if (oldLib.numBooks == 0){
		books = NULL;
		numBooks = 0;
	}
	else{ 
		numBooks = oldLib.numBooks;
		books = new book[numBooks]; // create array 
		for(int i=0; i < numBooks; i++){ // fill each element of the 1D array
			books[i].title = oldLib.books[i].title;
			books[i].author = oldLib.books[i].author;
			books[i].year = oldLib.books[i].year;
			books[i].numCopies = oldLib.books[i].numCopies;
		}
	}	
}
/********************************************************************* 
 ** Function: object default contructor
 ** Description: sets pointer to null and number of books to 0, also 
 ** sets defaults for time starts and ends
 ** Parameters: none
 ** Pre-Conditions: an object is created
 ** Post-Conditions: same as description
 *********************************************************************/
Library::Library(){ // default contructor
	
	numBooks = 0;
	books = NULL;
	
	for(int i = 0; i < 7; i++){
		week[i].bHr = "05";
		week[i].bMin = "00";
		week[i].eHr = "23";
		week[i].eMin = "59";
	}
}
/********************************************************************* 
 ** Function: destructor for books array
 ** Description: deletes the array and frees memory
 ** Parameters: none
 ** Pre-Conditions: array exists
 ** Post-Conditions: memory is freed
 *********************************************************************/
Library::~Library(){
	delete[]books;
}
/********************************************************************* 
 ** Function: change_hours
 ** Description: allows librarian to change library hours
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: hours array is altered
 *********************************************************************/
void Library::change_hours(){
	int choice;

	cout << "| What day's hours would you like to edit?" << endl;
	cout << "| Sun (1) | Mon (2) | Tue (3) | Wed (4) | Thu (5) | Fri (6) | Sat (7) " << endl;
	choice = e.userinput_int(1,7, " ");
	
	cout << "Beginning hour in 00 format: ";
	cin >> week[choice-1].bHr;
	cout << "Beginning minutes in 00 format: ";
	cin >> week[choice-1].bMin;
	cout << "Ending hour in 00 format: ";
	cin >> week[choice-1].eHr;
	cout << "Ending minutes in 00 format: ";
	cin >> week[choice-1].eMin;
	
	cout << "Updated window: " << week[choice-1].bHr << ":" << week[choice-1].bMin << " to " << week[choice-1].eHr << ":" << week[choice-1].eMin << endl;
}
/********************************************************************* 
 ** Function: view_hours
 ** Description: displays stored values of array in pleasing way
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void Library::view_hours(){
	int choice;

	cout << "| Would you like to view the hours for the week (0) or for a specific day?" << endl;
	cout << "| Sun (1) | Mon (2) | Tue (3) | Wed (4) | Thu (5) | Fri (6) | Sat (7) " << endl;
	choice = e.userinput_int(0,7, " ");

	if (choice == 0){
		cout << "| Sunday ----> | " << week[0].bHr << ":" << week[0].bMin << " to " << week[0].eHr << ":" << week[0].eMin << endl;
		cout << "| Monday ----> | " << week[1].bHr << ":" << week[1].bMin << " to " << week[1].eHr << ":" << week[1].eMin << endl;
		cout << "| Tuesday ---> | " << week[2].bHr << ":" << week[2].bMin << " to " << week[2].eHr << ":" << week[2].eMin << endl;
		cout << "| Wednesday -> | " << week[3].bHr << ":" << week[3].bMin << " to " << week[3].eHr << ":" << week[3].eMin << endl;
		cout << "| Thursday --> | " << week[4].bHr << ":" << week[4].bMin << " to " << week[4].eHr << ":" << week[4].eMin << endl;
		cout << "| Friday ----> | " << week[5].bHr << ":" << week[5].bMin << " to " << week[5].eHr << ":" << week[5].eMin << endl;
		cout << "| Saturday --> | " << week[6].bHr << ":" << week[6].bMin << " to " << week[6].eHr << ":" << week[6].eMin << endl;
	}
	else if(choice == 1)
		cout << "| Sunday ----> | " << week[0].bHr << ":" << week[0].bMin << " to " << week[0].eHr << ":" << week[0].eMin << endl;
	else if(choice == 2)
		cout << "| Monday ----> | " << week[1].bHr << ":" << week[1].bMin << " to " << week[1].eHr << ":" << week[1].eMin << endl;
	else if(choice == 3)
		cout << "| Tuesday ---> | " << week[2].bHr << ":" << week[2].bMin << " to " << week[2].eHr << ":" << week[2].eMin << endl;
	else if(choice == 4)
		cout << "| Wednesday -> | " << week[3].bHr << ":" << week[3].bMin << " to " << week[3].eHr << ":" << week[3].eMin << endl;
	else if(choice == 5)
		cout << "| Thursday --> | " << week[4].bHr << ":" << week[4].bMin << " to " << week[4].eHr << ":" << week[4].eMin << endl;
	else if(choice == 6)
		cout << "| Friday ----> | " << week[5].bHr << ":" << week[5].bMin << " to " << week[5].eHr << ":" << week[5].eMin << endl;
	else if(choice == 7)
		cout << "| Saturday --> | " << week[6].bHr << ":" << week[6].bMin << " to " << week[6].eHr << ":" << week[6].eMin << endl;
}

