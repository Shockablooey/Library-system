/********************************************************************* 
 ** LIBRARIAN. C P P 
 *********************************************************************/
#include "librarian.h"

/********************************************************************* 
 ** Function: remove_books 
 ** Description: rewrites books file, omitting book specified
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: file rewritten
 *********************************************************************/
void Librarian::remove_books(){
	ifstream input;
	ofstream output;
	input.open("books");
	output.open("temp");
	int numLines = 0;
	string userInput;
	string temp; // everything else in the line
	string tempBook; // name of book

	while(!input.eof()){
		numLines++;
		getline(input, temp);
	} // count lines in file
	input.close();
	input.open("books"); // close and repopen file

	cout << "What book would you like to remove?" << endl;
	cin.ignore();
	getline(cin, userInput); // get title to remove

	for(int i=0; i < (numLines-1); i++){
		getline(input,tempBook,'|'); // get name
		if(tempBook != userInput){ // if not match
			getline(input, temp); // take rest of line
			output << tempBook << "|" << temp << endl; // rewrite identical line
		}
		else // if match, do not rewrite
			getline(input, temp); // take the rest of the line and do nothing
	}
	remove("books");
	rename("temp","books");
	input.close(); // CLOSE INPUT
	output.close(); // CLOSE OUTPUT
}
/********************************************************************* 
 ** Function: view_checkouts
 ** Description: displays the checkedout file
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void Librarian::view_checkouts(){
	ifstream input;
	input.open("checkedout");
	int numLines = 0;
	string temp;
	string tempBook;
	string tempName;

	while(!input.eof()){
		numLines++;
		getline(input, temp);
	}
	input.close();
	input.open("checkedout"); // close and repopen file

	cout << "==================================================" << endl;
	for(int i=0; i < (numLines-1); i++){
		getline(input,tempBook,'|');
		getline(input,tempName);
		
		cout << "| " << tempBook << " is checked out by " << tempName << endl;	
	}
	cout << "==================================================" << endl;
	
	input.close(); // CLOSE INPUT
}
/********************************************************************* 
 ** Function: add_books 
 ** Description: line is appended to books file in proper format
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: line is appended to books file in proper format
 *********************************************************************/
void Librarian::add_books(){
	ofstream output;
	output.open("books",ios::app); // append mode 
	string tempBook;
	string tempAuthor;
	string tempYear;
	string tempCopies;
	
	cout << "Name of book? ";
	cin.ignore();
	getline(cin,tempBook);
	cout << "Author/Authors? ";
	getline(cin,tempAuthor);
	cout << "Year? ";
	getline(cin,tempYear);
	cout << "Number of copies to add to library? ";
	getline(cin,tempCopies);
	
	output << tempBook << "|" << tempAuthor << "|" << tempYear << "|" << tempCopies << endl;
	output.close(); // CLOSE OUTPUT
}
/********************************************************************* 
 ** Function: librarian_display
 ** Description: purely aesthetics
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
void Librarian::librarian_display(){
	cout << endl << endl;
	cout << "====================================================================================================" << endl;
	cout << "| " << name << ", what would you like to do?                                                        " << endl;
	cout << "====================================================================================================" << endl;
	cout << "|                                                                                                  |" << endl;
	cout << "|   Add book to database (1)   |    View all currently checked out books (2)    |    Logout (0)    |" << endl;  
	cout << "|                                                                                                  |" << endl;
	cout << "|      Change library's hours of operation (3)      |       Remove book from circulation (4)       |" << endl;  
	cout << "|                                                                                                  |" << endl;
	cout << "====================================================================================================" << endl << "| ";		 
	
}
/********************************************************************* 
 ** Function: object default constructor
 ** Description: name and id are set at proper values
 ** Parameters: none
 ** Pre-Conditions: object has been created
 ** Post-Conditions: name and id are set at proper values
 *********************************************************************/
Librarian::Librarian(){ // default contructor
	name = "default name";
	id = "0";
}
/********************************************************************* 
 ** Function: object constructor
 ** Description: name and id are set at proper values that are given by parameters
 ** Parameters: name and id
 ** Pre-Conditions: object has been created
 ** Post-Conditions: name and id are set at proper values
 *********************************************************************/
Librarian::Librarian(const string inputName, const string inputID){
	name = inputName;
	id = inputID;
}
/********************************************************************* 
 ** Function: set_name
 ** Description: mutator function for name
 ** Parameters: name of librarian
 ** Pre-Conditions: proper function call
 ** Post-Conditions: name is changed
 *********************************************************************/
void Librarian::set_name(const string inputName){
	name = inputName;
}
/********************************************************************* 
 ** Function: set_id
 ** Description: mutator function for id
 ** Parameters: id for librarian
 ** Pre-Conditions: proper function call
 ** Post-Conditions: id is changed
 *********************************************************************/
void Librarian::set_id(const string inputID){
	id = inputID;
}
/********************************************************************* 
 ** Function: get_id
 ** Description: accessor function for id
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
string Librarian::get_id() const{
	return id;
}
/********************************************************************* 
 ** Function: get_name
 ** Description: accessor function for name
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables are altered
 *********************************************************************/
string Librarian::get_name() const{
	return name;
}

