// ergasia1.cpp : Defines the entry point for the console application.
//
#include <math.h>
#include <iostream> 

#include "stdafx.h"
#include <list>
#include <fstream>
#include <string>
using namespace std;

//Συναρτηση με την οποια μετρουνται οι γραμμες που εχει το καθε αρχειο.
//με την getline διαβαζεται η καθε γραμμη του αρχειου και ταυτοχρονα αυξανεται ο δεικτης i 
int LineCount(string filename)
{	
	int i = 0;
	string line;
	ifstream myfile;
	myfile.open(filename);
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			while (getline(myfile, line)) {
				i++;
			}
		}
		myfile.close();
	}
	return i;

}
int distance(x1, x2, y1, y2)  //
{
	float dis;
	dis = ((x1 + x2)**2 + (y1 + y2)**2)**0.5;
	return dis;
}
int main()
{




	return 0;
}



