/*********************************************************************
 ** STRUCTS. H
 *********************************************************************/
#pragma once
#include <iostream> // basic input/output
#include <string> // c++ strings
#include <cstring> // c style strings
#include <fstream> // for file io
#include <cstdlib> // atoi etc
#include <algorithm> // for swap() command
 
using namespace std;

struct book{
	string title;
	string author;
	int year;
	int numCopies;
};
struct hours{
	string bHr;
	string bMin;
	string eHr;
	string eMin;
};

