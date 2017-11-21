/********************************************************************* 
 ** LIBRARIAN. H
 *********************************************************************/
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "structs.h"
#include "cart.h"
#include "errorcheck.h"

class Librarian{
	private:
		string name; 	
		string id;
	public:	
		Librarian(); // default constructor
		Librarian(const string, const string); // constructor

		void librarian_display(); // purely aesthetics
		void add_books();
		void view_checkouts();
		void remove_books();

		void set_name(const string); // setter
		void set_id(const string); // setter
		string get_name()const; // getter
		string get_id()const; // getter
};

#endif 
