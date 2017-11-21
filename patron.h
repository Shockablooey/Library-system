/********************************************************************* 
 ** PATRON. H
 *********************************************************************/
#ifndef PATRON_H
#define PATRON_H

#include "structs.h"
#include "cart.h"
#include "errorcheck.h"

class Patron{
	private:
		string name; 	
		string id;
	public:	
		Patron(); // default constructor
		Patron(const string, const string); // constructor

		void patron_display(); // purely aesthetics

		void view_own();
		void view_all();
		void search();

		void set_name(const string); // setter
		void set_id(const string); // setter
		string get_name()const; // getter
		string get_id()const; // getter
};

#endif 
