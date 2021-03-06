#include "stdafx.h"
#include <math.h>
#include <iostream> 
#include <list>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//functions:

int time_conversion(string time) {
	if (time.length() == 3)
	{
		//μετατρεπουμε το στρινκ σε char στη συνεχεια σε int και πολλαπλασιαζουμε τις ωρες *60 ενω προσθετουμε τα λεπτα
		
		char m = time[0];
		// το '0' αφαιρηται γιατι παιρνουμε την τιμη Ascii του πρωτου στοιχειου του στρινκ
		// για τα ψηφια 0,1,2.....9 οι στιμες ascii ειναι συνεχομενες 48,49.....57 οποτε αφαιροντας το '0' = 48
		// απο το στοιχειο που θελουμε μας δινει την πραγματικη του  int τιμη px αν c = 57 οπου 57 = 9 στην κωδικοποιηση ascii c - '0' == 57-48 == 9
		int minutes = ((int)m - '0') * 60 + stoi(time.substr(1));
		//cout << min;
		return minutes;
	}
	else {
		int minutes = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(2, 2));
		return minutes;

	}
template <typename T>
//Aπλη εφαρμογη του μαθηματικου τυπου για την αποσταση
T distance(T x1, T x2, T y1, T y2)  //
{
	T dis;
	dis = sqrt(pow(2, (x1 + x2)) + pow(2, (y1 + y2)));
	dis = dis * 10;
		if( (dis + 0.5) >= (int(dis) + 1)) {
			dis = (int(dis) + 1) / 10;
		}
		else {
			dis = int(dis) / 10;
		}


	}


template <typename T>
T Benefit(T distanceqi, T distanceir, T visit_time, T distanceqr , T score) {
	float b = pow(2, score) / (distanceqi + visit_time + distanceir - distanceqr);
	return b;
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

	//vectors που θα εχουμε τα στοιχεια μας.
	vector<vector<string>>Stoixeia;
	vector<string> temp;

	//ifstream ωστε να κανουμε read το αρχειο μας.
	ifstream myfile;

	//δεικτες

	int j = 0;
	int z = 0;
	myfile.open("t149.txt");
	if (myfile.is_open()) {
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
	O = opening of time window(start of the tour)=BeginOfTour
	C = closing of time window(end of the tour)=EndOfTour*/



	//εκχωρουμε μια μια τις μεταβλητες απο το Data array αφου πρωτα κανουμε cast apo string σε int με την stoi()
	// k
	int k = stoi(Data[0]);
	//M
	int  tours = stoi(Data[1]);
	//SD 0-6
	int Start_Day = stoi(Data[2]);
	//N
	const int vertices = stoi(Data[3]);
	//i
	int hotel_vertex_num = stoi(Data[16]);
	//Coordinates
	float hotel_x = stof(Data[17]);
	float hotel_y = stof(Data[18]);
	//d
	int hotel_visit_duration = stoi(Data[19]);
	
	//S
	int hotel_location_score = stoi(Data[20]);
	//O
	string  starting_time = Data[21];
	//C
	string  ending_time = Data[22];
	
	/*for (int x = 0; x < Stoixeia.size(); x++) {
		for (int i = 0; i < Stoixeia[x].size(); i++) {
			cout << Stoixeia[x][i] + " ";
		}
		cout << "" << endl;
	}*/
	//-------------------------------------------------------------------------------------------------------//
	

	


	int remaining_time = 1;

	//o διαθεσιμος χρονος που θα εχει ο τουριστας την καθε μερα που κανει επισκεψη
	//θα ειναι η διαφορα της ωρας που θα πρεπει να τελειωσει το tour - την ωρα που θα αρχισει το tour
	int starting_mins = time_conversion(starting_time);
	int ending_mins = time_conversion(ending_time);
	if (starting_mins > ending_mins) {
		int remaining_time = starting_mins - ending_mins;

	}
	//στην περιπτωση που η ωρα που ξεκιναμε ειναι μεγαλυτερη απο την ωρα που τελειωνουμε,αριθμητικα, απλα τις αντιστρεφουμε και αφαιρουμε
	else if (starting_mins < ending_mins) {
		int remaining_time = starting_mins - ending_mins;
	}
	//Αν η ωρα που ξεκιναμε == με ωρα που τελειωνουμε πρφανως εχουμε 12 ωρες στη διαθεση μας δηλαδη 12*60 λεπτα
	else {
		int remaining_time = 12 * 60;
	}
	//cout << remaining_time;
	//-------------------------ΔΗΜΗΙΟΥΡΓΙΑ ΛΙΣΤΑΣ---------------------//
	//Στην αρχη της ημερας η λιστα περιεχει μονο την αρχη και το τελος οπου θα ειναι το Ξενοδοχειο ----> 0.
	for (int i = 0; i < tours; i++) {
		list <int> Dromologia = { 0,0 };

		//η λιστα θα διαμορφωνεται μεσα σε while loop το οποιο θα σταματαει οταν δεν μπορει να εισαχθει αλλο δρομολογιο η δεν μενει αλλος χρονος
		while (remaining_time > 0) {

			//για να παρουμε τον δεικτη που ειναι ανοιχτα τα αξιοθεατα αναλογα με την ημερα που ο τουριστας αποφασιζει. πχ. αν η ημερα ειναι η 0
			//η θεση που βρισκεται η ωρα που ανοιγει το αξιοθεατο στο vector Stoixeia ειναι η 0 + 6 = 6.Αντιστοιχα αν η ημερα ηταν 1 ο δεικτης θα ηταν 
			//1 +6 ==7....
			//Με την ιδια λογικη βρισκουμε το day_closing_index απλα προσθετουμε 13
			int day_opening_index = 2*Start_Day + 6;
			int day_closing_index = 2 * Start_Day + 7;

			//Αν το μεγεθος της λιστας == 2 δηλαδη ειναι αδεια ψαχνουμε  να βρουμε το αξιοθεατο με το μεγαλυτερο οφελος 
			//στο vector μας ωστε να το βαλουμε στη λιστα
			if (Dromologia.size() == 2) {

				float max_benefit = 1;

				for (int x = 0; x < Stoixeia.size(); x++) {
					 //στο δεικτη 3 του Stoixeia βρισκεται η διαρκει της επισκεψης
					//ελεγχος αν η ωρα που ξεκιναει ο τουριστας + την ωρα που θελει να φτασει στο αξιοθεατο +  την ωρα που παιρνει η ξεναγηση ειναι μικροτερη η ιση απο την ωρα που κλεινει το αξιοθεατο
					//αν η ωρα που τελειωνει ο τουριστας ειναι > απο την ωρα που ανοιγει το αξιοθεατο + την ωρα που κανει να φτασει στο αξιοθεατο + την ωρα της ξεναγησης
				//T Benefit(T distanceqi, T distanceir, T visit_time, T distanceqr) 
					if (  (starting_mins + distance(hotel_x,stof(Stoixeia[x][1]),hotel_y,stof(Stoixeia[x][2])) + stoi(Stoixeia[x][3]) <=  time_conversion(Stoixeia[x][day_closing_index])) and (time_conversion(ending_time) > time_conversion(Stoixeia[x][day_opening_index]) + distance(hotel_x, stof(Stoixeia[x][1]), hotel_y, stof(Stoixeia[x][2])) + stoi(Stoixeia[x][3] ) )  )  {
						if (Benefit(distance(hotel_x, stof(Stoixeia[x][1]), hotel_y, stof(Stoixeia[x][2])), distance(stof(Stoixeia[x][1]), hotel_x, stof(Stoixeia[x][2]), hotel_y), stof(Stoixeia[x][3]), (float)0,stof(Stoixeia[x][4])) > max_benefit  ) {			//distance qr == 0 γιατι η αποσταση απο το ξενοδοχειο στο ξενοδοχειο ειναι 0 και το κανουμε cast σε float
							max_benefit = Benefit(distance(hotel_x, stof(Stoixeia[x][1]), hotel_y, stof(Stoixeia[x][2])), distance(stof(Stoixeia[x][1]), hotel_x, stof(Stoixeia[x][2]), hotel_y), stof(Stoixeia[x][3]), (float)0,stof(Stoixeia[x][4]));
						}


					}

					
				}
				cout << max_benefit;
				break;
			}

		}
	}
	
	
	//γινεται προσπελαση σε συγκεκριμενες θεσεις του array ακολουθωντας την σειρα 
	//που υπαρχει και στο αρχειο format_description_TTDP.txt

int meres = stoi(Data[0]);
int  NumberOfTours = stoi(Data[1]);
int SD = stoi(Data[2]);
int NumOfPlaces = stoi(Data[3]);
const int N = stoi(Data[3]);
int i = stoi(Data[16]);
int x = stoi(Data[17]);
int y = stoi(Data[18]);
int d = stoi(Data[19]);
int S = stoi(Data[20]);
int  BeginOfTour = stoi(Data[21]);
int EndOfTour = stoi(Data[22]);


float TimeWindow = (EndOfTour - BeginOfTour) / 100;

/*for (int x = 0; x < Stoixeia.size(); x++) {
	for (int i = 0; i < Stoixeia[x].size(); i++) {
		cout << Stoixeia[x][i] + " ";
	}
	cout << "" << endl;
}*/
//-------------------------------------------------------------------------------------------------------//


	
	}
		


	

	
	
    return 0;
}





