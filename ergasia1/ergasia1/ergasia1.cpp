#include "stdafx.h"
#include <math.h>
#include <iostream> 
#include <list>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//functions:


template <typename T>
//Aπλη εφαρμογη του μαθηματικου τυπου για την αποσταση
T distance(T x1, T x2, T y1, T y2)  //
{
	T dis;
	dis = sqrt(((x1 + x2)**2 + (y1 + y2)**2));
	return dis;
}


//---------------------------------------------------------------------------------------------//

int main()
{	
	
	
	//ΑΠΟΘΗΚΕΥΣΗ ΤΩΝ ΣΤΟΙΧΕΙΩΝ ΣΕ ΔΟΜΕΣ//
	//-----------------------------------------------------------------------------------------------//
	
	
	
	
	//βαζουμε ενα ενα τα στοιχεια των πρωτων 2 γραμμων σε ενα string array
	string Data[25];
	//ενα στρινκ
	string a;

	//καθε φορα το output θα εχει ενα μονο στοιχειο του .txt αρχειου μας και ετσι θα αποφευγονται τα whitespaces.
	char output[100];

	//vectors που θα εχουμε τα στοιχεια μας, τυπου string .
	vector<vector<string>>Stoixeia;
	vector<string> temp;

	//ifstream ωστε να κανουμε read το αρχειο μας.
	ifstream myfile;

	//δεικτες

	int j = 0;
	int z = 0;
	//ανοιγμα του αρχειου για επεξεργασια
	myfile.open("t101.txt");
	//ελεγχος αν ειναι ανοιχτο
	if (myfile.is_open()) {
		//while loop μεχρι να φτασει στο τελος του αρχειου.eof() ------> επιστρεφει boolean
		while (!myfile.eof()) {
			myfile >> output;
				a = output;
				
				//στον πινακα Data θα βαλουμε τα πρωτα 22 στοιχεια με το δεικτη z να ξεκιναει απο το 0.Καθε φορα που μπαινει
				
				if (j < 23) {
					//cout << a;
					Data[j] = a;
					j++;
				}
				//Tα δευτερευοντα στοιχεια θα βρισκονται σε vector μεσα σε vector( που εχει Ν-2 γραμμες και (Ν-2)*21 στηλες καθως οι στηλες μετα τη δευτερη γραμμη ειναι σταθερες και 21 σε αριθμο)
				//στο vector stoixeia περναμε το  vector temp
				//o δεικτης z για τις στηλες ξεκιναει απο το 0 ---> φτανει στο 20
				
				

				else {
					// ο δεικτης αυξανεται κατα 1.οταν z%20 == 0 δηλαδη η ακ διαιρεση του z  με το 20 εχει υπολοιπο 0
					//κανουμε push το vector temp στο stoixeia , ο z μηδενιζεται και ο temp ξανα δηλωνεται οποτε ειναι και παλι κενος 
					//η διαδικασια επαναλαμβανεται μεχρι να φτασουμε στο τελος του αρχειου.
					
					temp.push_back(a);
					z++;
					if (z % 20 == 0) {
						Stoixeia.push_back(temp);
						z = 0;
						vector<string> temp;
					}

				}
				
			
			
		}
		myfile.close();
	}


		//Απο το .txt αρχειο για το format:

		//The first line contains the following data:

	//k M SD N C B E1 E2 E3 E4 E5 E6 E7 E8 E9 E10
	//Where
	//	k = 20 (meres)
	//	M = number of tours
	//	SD = start day(from 0 to 6)
	//	N = number of vertices
	/*The second line associates with start / end point(typically hotel) :

		i x y d S 0 C

		Where
		i = vertex number = 0
		x = x coordinate
		y = y coordinate
		d = visiting duration = 0
		S = score of the location = 0
		O = opening of time window(start of the tour)
		C = closing of time window(end of the tour)*/
		
		
		
	//εκχωρουμε μια μια τις μεταβλητες απο το Data array αφου πρωτα κανουμε cast apo string σε int με την stoi()
	//γινεται προσπελαση σε συγκεκριμενες θεσεις του array ακολουθωντας την σειρα 
	//που υπαρχει και στο αρχειο format_description_TTDP.txt
	
	int k = stoi(Data[0]);
	int  M = stoi(Data[1]);
	int SD = stoi(Data[2]);
	const int N = stoi(Data[3]);
	int i = stoi(Data[16]);
	int x = stoi(Data[17]);
	int y = stoi(Data[18]);
	int d = stoi(Data[19]);
	int S = stoi(Data[20]);
	int  O = stoi(Data[21]);
	int C = stoi(Data[22]);

	/*for (int x = 0; x < Stoixeia.size(); x++) {
		for (int i = 0; i < Stoixeia[x].size(); i++) {
			cout << Stoixeia[x][i] + " ";
		}
		cout << "" << endl;
	}*/
	//-------------------------------------------------------------------------------------------------------//
	
	
	
    return 0;
}



