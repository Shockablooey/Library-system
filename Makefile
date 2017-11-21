CC = g++
exe = wow
$(exe): unladenswallow.o library.o librarian.o cart.o patron.o errorcheck.o
	$(CC) unladenswallow.o library.o librarian.o cart.o patron.o errorcheck.o -o $(exe)
unladenswallow.o: unladenswallow.cpp
	$(CC) -c unladenswallow.cpp
library.o: library.cpp
	$(CC) -c library.cpp
librarian.o: librarian.cpp
	$(CC) -c librarian.cpp
cart.o: cart.cpp
	$(CC) -c cart.cpp
patron.o: patron.cpp
	$(CC) -c patron.cpp
errorcheck.o: errorcheck.cpp
	$(CC) -c errorcheck.cpp
clean:
	rm -f *.out *.o $(exe)
