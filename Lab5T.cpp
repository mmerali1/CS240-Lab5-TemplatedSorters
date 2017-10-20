#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>

#include "TSorter.h"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main (int argc, char **argv) {
unsigned int numValues = DEFAULT_NUMVALUES; 
	int value;

	if (argc > 1)
		numValues = atoi(argv[1]);  
	if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
		cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
		cerr << ", " << MAX_NUMVALUES << endl; 
		cerr << "\nUsage: " << argv[0] << " {numValues}" << endl; 
	}
	if (argc > 2) 
		cerr << "Ignoring extra command line arguments." << endl; 

	cout << endl << "Generating " << numValues << " values for sorting." << endl; 
	
	TSorter<int> t;

	srand(time(NULL)); // use this line for pseudo-random numbers 
	// srand(23);      // use this line for deterministic "random" numbers
  
	//TEST CASES FOR INTEGER TYPE
	for (unsigned int i=0; i < numValues; i++) {
		value = rand() % 100;  
		t.insert(value); 
	} 
	t.show();
	t.shuffle();
	cout << "After shuffle:"<<endl;
	t.show();
	cout << "After iterative insertion sort:"<<endl;
	t.insertionSortI();
	t.show();
	t.shuffle();
	t.show();
	cout << "After iterative selection sort:"<<endl;	
	t.selectionSortI();
	t.show();
	t.shuffle();
	t.show();
	cout << "After iterative bubble sort:"<<endl;
	t.bubbleSortI();
	t.show();
	t.shuffle();
	t.show();
	cout << "After recursive insertion sort:"<<endl;
	t.insertionSortR();
	t.show();
	t.shuffle();
	t.show();
	cout << "After recursive selection sort:" << endl;
	t.selectionSortR();
	t.show();
	t.shuffle();
	t.show();
	cout << "After recursive bubble sort:" << endl;
	t.bubbleSortR();
	t.show();


	//TEST CASE FOR STRING TYPE
	TSorter<string> st;
	cout << "Initial sentence" << endl;	
	st.insert("Rest");
	st.insert("In");
	st.insert("Piece");
	st.insert("Harambe");
	st.insert("You");
	st.insert("Will");
	st.insert("Be");
	st.insert("Missed");
	st.show();
	st.shuffle();
	cout << "After shuffle:"<<endl;
	st.show();
	cout << "After iterative insertion sort:"<<endl;
	st.insertionSortI();
	st.show();
	st.shuffle();
	st.show();
	cout << "After iterative selection sort:"<<endl;	
	st.selectionSortI();
	st.show();
	st.shuffle();
	st.show();
	cout << "After iterative bubble sort:"<<endl;
	st.bubbleSortI();
	st.show();
	st.shuffle();
	st.show();
	cout << "After recursive insertion sort:"<<endl;
	st.insertionSortR();
	st.show();
	st.shuffle();
	st.show();
	cout << "After recursive selection sort:" << endl;
	st.selectionSortR();
	st.show();
	st.shuffle();
	st.show();
	cout << "After recursive bubble sort:" << endl;
	st.bubbleSortR();
	st.show();

	
	//TEST CASE FOR TYPE CIRCLE
	TSorter<Circle> ct;
	cout << "Initial sentence" << endl;	
	ct.insert(Circle(2.0));
	ct.insert(Circle(4.0));
	ct.insert(Circle(1.0));
	ct.insert(Circle(2.5));
	ct.insert(Circle(10.0));
	ct.insert(Circle(6.0));
	ct.insert(Circle(6.5));
	ct.insert(Circle(0.5));
	ct.show();
	ct.shuffle();
	cout << "After shuffle:"<<endl;
	ct.show();
	cout << "After iterative insertion sort:"<<endl;
	ct.insertionSortI();
	ct.show();
	ct.shuffle();
	ct.show();
	cout << "After iterative selection sort:"<<endl;	
	ct.selectionSortI();
	ct.show();
	ct.shuffle();
	ct.show();
	cout << "After iterative bubble sort:"<<endl;
	ct.bubbleSortI();
	ct.show();
	ct.shuffle();
	ct.show();
	cout << "After recursive insertion sort:"<<endl;
	ct.insertionSortR();
	ct.show();
	ct.shuffle();
	ct.show();
	cout << "After recursive selection sort:" << endl;
	ct.selectionSortR();
	ct.show();
	ct.shuffle();
	ct.show();
	cout << "After recursive bubble sort:" << endl;
	ct.bubbleSortR();
	ct.show();

	
	return 0;


}

