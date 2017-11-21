/********************************************************************* 
 ** PATRON. C P P 
 *********************************************************************/
#include "patron.h"
#include <iomanip> // for setw

/********************************************************************* 
 ** Function: search
 ** Description: goes through books file and only prints elements that match search
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered 
 *********************************************************************/
void Patron::search(){
	string userInput;
	ifstream input;
	input.open("books");
	string temp;
	string tempBook;
	string tempAuthor;
	string tempYear;
	string tempCopies;
	bool foundBooks = false;
	int numLines = 0;
		
	while(!input.eof()){
		numLines++;
		getline(input, temp);
	}
	input.close();
	input.open("books"); // close and repopen file
		
	cout << endl << "Search by either title, author(s), or year." << endl;
	cin.ignore();
	getline(cin, userInput);

	for(int i=0; i < (numLines-1); i++){
		getline(input, tempBook, '|');
		getline(input, tempAuthor, '|');
		getline(input, tempYear, '|');
		getline(input, tempCopies); // getline to end of line, getting copies and discarding endline
			
		if(userInput == tempBook || userInput == tempAuthor || userInput == tempYear ){
			foundBooks = true;
			cout << "| " << tempBook << " by " << tempAuthor << ". (" << tempYear << ") -> " << tempCopies << endl;	
		}
	}
	if(foundBooks == false)
		cout << "unable to find books that matched your search." << endl;
	cout << endl;
	
}
/********************************************************************* 
 ** Function: view_all 
 ** Description: prints the books file in a pretty way
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void Patron::view_all(){
	ifstream input;
	input.open("books");
	string temp;
	string tempBook;
	string tempAuthor;
	string tempYear;
	string numCopies;
	int numLines = 0;
	
	while(!input.eof()){
		numLines++;
		getline(input, temp);
	}
	input.close();
	input.open("books"); // close and repopen file

	cout << endl << endl;
	cout << "====================================================================================================" << endl;
	cout << "| Database:                                                                                        |" << endl;
	cout << "====================================================================================================" << endl;
	
	for(int i=0; i < (numLines-1); i++){
		getline(input, tempBook, '|');
		getline(input, tempAuthor, '|');
		getline(input, tempYear, '|');
		getline(input, numCopies); // get info for a book
		cout << "| Book: ";
		cout << setw(20); // set width of tempBook
		cout << tempBook;
		cout << " | Author(s): ";
		cout << setw(32); // set width of tempAuthor
		cout << tempAuthor;
		cout << " | Year: ";
		cout << setw(6); // set width of tempYear
		cout << tempYear;
		cout << " |    ";
		cout << setw(3);	
		cout << numCopies;
		cout << " |" << endl;										  
	}
	cout << "====================================================================================================" << endl;
	cout << endl;
}
/********************************************************************* 
 ** Function: view_own 
 ** Description: prints the books that the current patron has checked out
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Condition: no variables are altered
 *********************************************************************/
void Patron::view_own(){
	ifstream input;
	input.open("checkedout");
	string tempBook;
	string tempName;
	string temp;
	bool foundBooks = false; 
	int numLines = 0;
	
	while(!input.eof()){
		numLines++;
		getline(input, temp);
	}
	input.close(); 
	input.open("checkedout"); // close and reopen file
	
	
	cout << "==================================================" << endl;
	for(int i=0; i < (numLines-1); i++){
		getline(input, tempBook, '|'); // get book
		getline(input, tempName); // get name
		if (tempName == name && tempName != "" && tempName != "\n"){
			cout << "| " << tempBook << endl;
			foundBooks = true; // we found at least one book 
		} // if match, print book
	}
	if(foundBooks == false) // no books found
		cout << "| We found no books under your name.             |" << endl;	
	cout << "==================================================" << endl;
	
	input.close(); // CLOSE FILE
}
/********************************************************************* 
 ** Function: patron_display
 ** Description: purely aesthestics 
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void Patron::patron_display(){
	cout << endl << endl;
	cout << "====================================================================================================" << endl;
	cout << "| " << name << ", what would you like to do?                                                        " << endl;
	cout << "====================================================================================================" << endl;
	cout << "|                                                                                                  |" << endl;
	cout << "|   Check out a book (1)     |     View personal checked out books (2)     |     Checkout (0)      |" << endl;  
	cout << "|                                                                                                  |" << endl;
	cout << "|   Search for a book (3)    |     Return a book (4)     |      View all books in library (5)      |" << endl;  
	cout << "|                                                                                                  |" << endl;
	cout << "====================================================================================================" << endl << "| ";		 
	
}
/********************************************************************* 
 ** Function: object default constructor
 ** Description: name and id are set to default values 
 ** Parameters: none
 ** Pre-Conditions: object is created
 ** Post-Conditions: same as description
 *********************************************************************/
Patron::Patron(){ // default contructor
	name = "default name";
	id = "0";
}
/********************************************************************* 
 ** Function: object constructor
 ** Description: name and id are set at parameters given
 ** Parameters: name and id to set
 ** Pre-Conditions: object has been created
 ** Post-Conditions: object created with proper values
 *********************************************************************/
Patron::Patron(const string inputName, const string inputID){
	name = inputName;
	id = inputID;
}
/********************************************************************* 
 ** Function: set_name
 ** Description: mutator function for setting name
 ** Parameters: name of patron 
 ** Pre-Conditions: proper function call
 ** Post-Conditions: name of patron is set
 *********************************************************************/
void Patron::set_name(const string inputName){
	name = inputName;
}
/********************************************************************* 
 ** Function: set_id
 ** Description: mutator function for setting name
 ** Parameters: id of patron
 ** Pre-Conditions: proper function call
 ** Post-Conditions: id of patron is set
 *********************************************************************/
void Patron::set_id(const string inputID){
	id = inputID;
}
/********************************************************************* 
 ** Function: get_id
 ** Description: accessor function for id
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
string Patron::get_id() const{
	return id;
}
/********************************************************************* 
 ** Function: get_name
 ** Description: accessor function for name
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
string Patron::get_name() const{
	return name;
}

