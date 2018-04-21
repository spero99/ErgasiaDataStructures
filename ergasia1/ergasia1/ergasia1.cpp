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
	dis = sqrt((x1 + x2)**2 + (y1 + y2)**2);
	return dis;
}
int benefit_factor (score,distance1 ,distance2 ,distance3,tourtime)		//συναρτηση με την οποια υπολογιζεται το οφελςο της προσθηκης ενοσ αξιοθεατου(αi)μεταξυ δυο διαδοχικων(αq, αr) στο προγραμμα της μερας
{																		//distance1 distance2 distance3 ειναι οι αποστασεις  αq->αi ,αi->αr, αq->αr
	float benefit;
	benefit = score * *2 / (distance1 + distance2 + tourtime - distance3);
	return benefit;

}

int main()
{




	return 0;
}



