/********************************************************************* 
 ** CART. C P P 
 *********************************************************************/
#include "cart.h"

/********************************************************************* 
 ** Function: return_check
 ** Description: checks to see if book and name is in checkedout file
 ** Parameters: name of patron
 ** Pre-Conditions: proper function call 
 ** Post-Conditions: user input book name is given to return_book()
 *********************************************************************/
void Cart::return_check(const string name){
	string userInput;
	string tempBook;
	string tempName;
	ifstream input;
	input.open("checkedout");
	bool good = false;

	cout << "What book would you like to return, " << name << "?" << endl;
	cin.ignore();
	getline(cin, userInput); // take user input

	while(!input.eof()){
		getline(input, tempBook,'|'); // get book
		if(userInput == tempBook){ // compare books
			getline(input, tempName); // get name
			if(name == tempName){ // compare names
				good = true;
			}
		}
		getline(input, tempName); // get name and do nothing
	}
	input.close(); // CLOSE INPUT
	if(good == true){
		cout << "returning book..." << endl << endl;
		return_book(userInput, name); // calls function with name of user and name of book
	}
	else
		cout << "That book is not checked out under your name." << endl;
}
/********************************************************************* 
 ** Function: return_book
 ** Description: rewrites checkedout file, omitting the book that was returned
 ** Parameters: name of book and name of patron
 ** Pre-Conditions: book name and patron name have been properly set
 ** Post-Conditions: file rewritten
 *********************************************************************/
void Cart::return_book(const string book, const string name){
	ifstream input;
	input.open("checkedout");
	ofstream output;
	output.open("temp");

	string temp;
	string tempBook;
	string tempName;
	int numLines = 0;
	int booksToAdd = 0;

	while(!input.eof()){
		getline(input, temp);
		numLines++; // get a count for number of lines
	}
	input.close(); // CLOSE INPUT
	input.open("checkedout"); // OPEN INPUT	
	for (int i=0; i < (numLines-1); i++){ // numLines -1 to account for eof extra line
		getline(input, tempBook, '|'); // get book
		getline(input,tempName); // get name
		if(book == tempBook && name == tempName){ // if not a match, spit out the whole line
			booksToAdd++;
		}
		else{
			output << tempBook << "|" << tempName << endl;
		}	
	}
	output.close(); // CLOSE OUTPUT
	input.close(); // CLOSE INPUT
	remove("checkedout"); // delete old books file
	rename("temp","checkedout"); // make temp the new books file
	return_part3(book, name, booksToAdd); // calls function with book, name, and how many
}
/********************************************************************* 
 ** Function: return_part3
 ** Description: loops through books file and finds the lines that must be altered
 ** Parameters: name of book, name of patron, and how many books were returned
 ** Pre-Conditions: names and number of books to add are properly set
 ** Post-Conditions: books file is rewritten
 *********************************************************************/
void Cart::return_part3(const string book, const string name, const int booksToAdd){
	ifstream input;
	ofstream output;
	input.open("books");
	output.open("temp");

	string temp;
	string tempBook;
	string tempAuthor;
	string tempYear;
	string tempNum;
	int numLines = 0;

	while(!input.eof()){
		numLines++;
		getline(input, temp); // count lines in books file
	}	
	input.close();
	input.open("books"); // close and reopen

	for(int i = 0; i < (numLines - 1); i++){ // numLines-1 to account for eof extra
		getline(input, tempBook, '|'); // get book
		if(tempBook == book){ // if match
			num_copies_add(book, output, input, booksToAdd); // calls function with book to add copies to and how many
		}
		else{ // if not match
			getline(input,tempAuthor,'|'); // get author
			getline(input,tempYear,'|'); // get year
			getline(input,tempNum); // get numCopies
			output << tempBook << "|" << tempAuthor << "|" << tempYear << "|" << tempNum << endl;
		}
	}
	input.close(); // CLOSE INPUT
	output.close(); // CLOSE OUTPUT
	remove("books");
	rename("temp","books");
}
/********************************************************************* 
 ** Function: num_copies_add
 ** Description: adds however many copies necessary to line of books file
 ** Parameters: names of books and io stream and books to add 
 ** Pre-Conditions: streams have been opened properly.  names are set. number of books is given
 ** Post-Conditions: return of book complete
 *********************************************************************/
void Cart::num_copies_add(const string bookName, ofstream& output, ifstream& input, const int booksToAdd){
	string tempAuthor;
	string tempYear;
	string temp;
	int tempInt;

	getline(input,tempAuthor,'|'); // get author
	getline(input,tempYear,'|'); // get year
	getline(input,temp); // get numCopies
	tempInt = atoi(temp.c_str()); // stoi on numCopies input

	tempInt+=booksToAdd; // increment number of Copies
	output << bookName << "|" << tempAuthor << "|" << tempYear << "|" << tempInt << endl;
	cout << "return successful." << endl;
}
/********************************************************************* 
 ** Function: checkout_book
 ** Description: loops through file, finding what line must be edited
 ** Parameters: name of patron
 ** Pre-Conditions: proper function call
 ** Post-Conditions: file overwritten
 *********************************************************************/
void Cart::checkout_book(const string name){
	string userInput;
	ifstream input;
	input.open("books");
	ofstream output;
	output.open("temp");
	string tempName;
	string tempAuthor;
	string tempYear;
	string tempInt;
	string temp;
	int numLines = 0;

	while(!input.eof()){
		getline(input, temp);
		numLines++; // get a count for number of lines
	}
	input.close(); // CLOSE INPUT
	input.open("books"); // OPEN INPUT	
	cout << "What book would you like to checkout?" << endl;
	cin.ignore(); // clear buffer
	getline(cin, userInput); // take user input
	for (int i=0; i < (numLines-1); i++){ // numLines -1 to account for eof extra line
		getline(input, tempName, '|'); // get book name
		if(userInput == tempName){ // if match
			num_copies_dec(tempName, output, name, input);
		}
		else{
			getline(input, tempAuthor,'|'); // get author
			getline(input,tempYear,'|'); // get year
			getline(input,tempInt); // get numCopies
			output << tempName << "|" << tempAuthor << "|" << tempYear << "|" << tempInt << endl;
		} // if not a match, spit out the whole line	
	}
	output.close(); // CLOSE OUTPUT
	input.close(); // CLOSE INPUT
	remove("books"); // delete old books file
	rename("temp","books"); // make temp the new books file
}
/********************************************************************* 
 ** Function: num_copies_dec
 ** Description: takes line into 1D array, decrements numCopies IF it is not 0,
 ** otherwise gives an error message, and prints the line into the external file
 ** Parameters: names and io streams
 ** Pre-Conditions: streams opened properly, names set
 ** Post-Conditions: number of copies for proper element decremented, unless 0
 *********************************************************************/
void Cart::num_copies_dec(const string bookName, ofstream& output, const string name, ifstream& input){
	string tempAuthor;
	string tempYear;
	string temp;
	int tempInt;

	getline(input,tempAuthor,'|'); // get author
	getline(input,tempYear,'|'); // get year
	getline(input,temp); // get numCopies
	tempInt = atoi(temp.c_str()); // stoi on numCopies input

	if (tempInt != 0){
		tempInt--; // decrement number of copies
		output << bookName << "|" << tempAuthor << "|" << tempYear << "|" << tempInt << endl; // add edited line to books file

		ofstream output2; // ofstream for checkedout file
		output2.open("checkedout",ios::app); // open checkedoutfile in append mode
		output2 << bookName << "|" << name << endl;
		cout << bookName << " checked out successfully." << endl;
		output2.close();
	}

	else{
		cout << "There are no available copies of " << bookName << "." << endl; 
		output << bookName << "|" << tempAuthor << "|" << tempYear << "|" << tempInt << endl; // add edited line to books file
	}
}
/********************************************************************* 
 ** Function: object default contructor
 ** Description: sets pointer to null and number of books to 0
 ** Parameters: none
 ** Pre-Conditions: an object is created
 ** Post-Conditions: same as description
 *********************************************************************/
Cart::Cart(){ // default contructor
	books = NULL;
	numBooks = 0;
}
/********************************************************************* 
 ** Function: accessor for books array
 ** Description: returns the pointer for the books array
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables altered
 *********************************************************************/
book* Cart::get_books() const{
	return books;
}
/********************************************************************* 
 ** Function: mutator for the number of books
 ** Description: changes number of books for array and creates an array of that size
 ** Parameters: number of books 
 ** Pre-Conditions: int is given
 ** Post-Conditions: array is created
 *********************************************************************/
void Cart::set_num_books(const int input){
	numBooks = input; // receive numBooks from main
	books = new book [numBooks]; // make book array
}
/********************************************************************* 
 ** Function: accessor for number of books
 ** Description: returns the number of books
 ** Parameters: none
 ** Pre-Conditions: proper function call
 ** Post-Conditions: no variables altered
 *********************************************************************/
int Cart::get_num_books() const{
	return numBooks;
}
/********************************************************************* 
 ** Function: destructor for books array
 ** Description: deletes the array and frees memory
 ** Parameters: none
 ** Pre-Conditions: array exists
 ** Post-Conditions: memory is freed
 *********************************************************************/
Cart::~Cart(){ // destructor 
	delete[]books; // delete book array
}
/********************************************************************* 
 ** Function: cart copy constructor 
 ** Description: takes an old cart and deep copies
 ** Parameters: cart to be copied
 ** Pre-Conditions: source cart has been created
 ** Post-Conditions: copy cart is created
 *********************************************************************/
Cart::Cart(const Cart &oldCart){ // cart c is passed in and named "oldCart"
	if (oldCart.numBooks == 0){
		books = NULL;
		numBooks = 0;
	}
	else{ 
		numBooks = oldCart.numBooks;
		books = new book[numBooks]; // create array 
		for(int i=0; i < numBooks; i++){ // fill each element of the 1D array
			books[i].title = oldCart.books[i].title;
			books[i].author = oldCart.books[i].author;
			books[i].year = oldCart.books[i].year;
			books[i].numCopies = oldCart.books[i].numCopies;
		}
	}	
}
/********************************************************************* 
 ** Function: copy assignment overload
 ** Description: takes an old cart and deep copies
 ** Parameters: cart to be copied
 ** Pre-Conditions: source cart has been created
 ** Post-Conditions: copy cart is created
 *********************************************************************/
void Cart::operator=(const Cart &oldCart){ // cart c is passed in and named "oldCart"

	delete[]books;

	if (oldCart.numBooks == 0){
		books = NULL;
		numBooks = 0;
	}
	else{ 
		numBooks = oldCart.numBooks;
		books = new book[numBooks]; // create array 
		for(int i=0; i < numBooks; i++){ // fill each element of the 1D array
			books[i].title = oldCart.books[i].title;
			books[i].author = oldCart.books[i].author;
			books[i].year = oldCart.books[i].year;
			books[i].numCopies = oldCart.books[i].numCopies;
		}
	}	
}

