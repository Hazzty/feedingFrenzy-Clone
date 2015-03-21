#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string intToStr(int integer)
{
	ostringstream convert; 
	convert << integer;      
	return convert.str();
}

#endif
