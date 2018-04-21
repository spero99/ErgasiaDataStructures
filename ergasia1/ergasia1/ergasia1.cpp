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
int ArrElements(int Array,string filename) {
	ifstream myfile;
	myfile.open(filename);
	
	int i = 0;
	char output[100];
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			myfile >> output;
			if i < 4 or (i > 15 and i <= 22) {
				Array[i] = output;
				i++;
			}
			else if (i > 22) { break; }
			cout << output << endl;
		}
	}
	myfile.close();
	
}
template <typename T>
int distance(T x1, T x2,T y1,T y2)  //
{
	float dis;
	dis = ((x1 + x2)**2 + (y1 + y2)**2)**0.5;
	return dis;
}
int main()
{
	
	/*int Dataptr* = ArrElements("t101.txt");
	cout << Dataptr[0];*/
	int Data[10];
	ArrElements(Data, "t101.txt");
	cout << Data[0];
	return 0;
}



