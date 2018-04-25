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
	dis = sqrt((x1 + x2)**2 + (y1 + y2)**2);
	dis = dis * 10
	if (dis + 0.5) >= (int(dis) + 1)
		dis = (int(dis) + 1) / 10;
	else
		dis = int(dis) / 10;



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
	
	//δημιουργια της κλασσης που θα χρησιμοποιησουμε για τις συνδεδεμενς λιστες
	template<class T>
	class ListNode {
		friend List<t>;
	private:
		T data
			ListNode<t> *link;
	};

	template<class T>
	class List {
	public:
		list() { first = 0; }
		~List();
		bool IsEmpty() const { return first == 0; }
		int Length() const;
		bool Find (int k, T& x) const;
		int Search(const T& x);
		Chain<T>& Delete(int k, T& x);
		Chain<T>& Insert(int k,const  T& x);
		void Output(ostream& out) const;
	private:
		ListNode<T> *first //δεικτης στο πρωτο κομβο
	};

	template<class T>
	List<T>::~List()
	{//
		ListNode<t>*next;
		while (first) {
			next = first->link;
			delete first;
			first = next;
		}
	}

	template<class T>
	int List<T>::Length() const
	{//
		ListNode<T> *current = first;
		int len = 0;
		while (current) {
			len++;
			current = current->link;
		}
		return len;
	}

	template<class T>
	bool List<T>::Find(int k, T& x) const
	{//
	 //
		if (k < 1) return false;
		ListNode<T>*current = first;
		int index = 1;
		while (index < k && current) {
			current = current->link;
			index++
		}
		if (current){ x = current->data; return true; }
		return false;//
	}

	template<class T>
	int List<T>::Search(const T & x)
	{
		
		ListNode<t>*current = first;
		int index = 1;
		while (current && current->data != x) {
			current = current->link;
			index++
		}
		if (current) return index;
		return 0; return 0;
	}

	

	template<class T>
	void List<T>::Output(ostream& out) const
	{//
		ListNode<T> *current;
		for (current = first; current; current = current->link;)
			out << current->data << " ";
	}
	
	//overload<<
	template<class T>
	ostream& operator<<(opstream&  out ,const List<T>& x)
	{
		x.Output(out); return out;
	}

	template<class T>
	Chain<T>& List<T>::Delete(int k, T & x)
	{
		//
		//
		if (k < 1 || !first)
			throwOutOfBOunds();//
		//
		ListNode<T> *p = first;
		
		//
		if (k == 1)//
			first = first->link; //
		else {//
			ListNode<T>*q = first;
			for (int index = 1; index < k - 1 && q; index++)
				q = q->link;
			if (!q || !q->link)
				throw OutOfBounds();
			p = q->link;
			q->link = p->link;
		}
		x = p->data;
		delete p;
		return *this;
	}

	template<class T>
	Chain<T>& List<T>::Insert(int k, const T & x)
	{
		//
		//
		//
		if (k < 0) throw OutOfBounds();
		//
		ListNode<t> *p = first;
		for (int index = q; index < k &&p; index++)//
			p = p->link;
		if (k < 0 && !p) throw OutOfBounds();
		ListNode<T> *y = newListNode<T>
			y->data = x;
		if (k) { y->link; = p->link; p->link = y; }
		else { y->link = first; first = y; }
		return *this;
	}




    return 0;
}



