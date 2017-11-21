/********************************************************************* 
 ** LIBRARY. H
 *********************************************************************/
#ifndef LIBRARY_H 
#define LIBRARY_H

#include "patron.h"
#include "cart.h"
#include "librarian.h"
#include "errorcheck.h"

class Library{
	private:
		Patron p;
		Librarian l;
		Error e;
		Cart c; // default constructor
		Cart c2(Cart c); // copy constructor
		hours week[7]; // static array for library hours
		book* books;
		int numBooks;
	public:
		Library(); // default constructor
		~Library(); // destructor
		Library(const Library &); //copy constructor
		void operator= (const Library &); // copy assignment overload	
	
		void view_hours();
		void change_hours();

		void patron_login();
		void patron_menu(const string, const string);
		void librarian_login();
		void librarian_menu(const string, const string);
};
#endif
