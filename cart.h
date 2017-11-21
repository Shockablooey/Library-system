/********************************************************************* 
 ** CART. H
 *********************************************************************/
#ifndef CART_H
#define CART_H

#include "structs.h"

class Cart{
	private:
		int numBooks; 	
		book* books; 
	public:
		Cart(); // default constructor
		Cart(const Cart &oldCart); //copy constructor
		void operator=(const Cart &c); // copy assignment overload
		~Cart(); // destructor

		void checkout_book(const string);
		void return_part3(const string, const string, const int);
		void num_copies_dec(const string, ofstream&, const string, ifstream&);
		void num_copies_add(const string, ofstream&, ifstream&, const int);
		
		void return_check(const string);
		void return_book(const string, const string);

		book* get_books() const; // get pointer for array
		void set_num_books(const int mainInput); 
		int get_num_books() const; 
		
};
#endif
