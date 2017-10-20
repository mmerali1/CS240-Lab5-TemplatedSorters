#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Insertion Sort
void Sorter::insertionSortI() {
   cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;
   unsigned int  j, i;
   int tempNum;
   for(i=1; i<numElements; i++){
		tempNum=array[i];
		j=i;
        while((j>0) && (array[j-1] > tempNum)){        
            swap(j, j-1);
			j = j-1;
        }

   }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
   cout << "Sorter::selectionSortI()" << endl << endl;
   unsigned int indMin, i, j;
    for (i=0; i<numElements-1;i++){
        indMin = i;
        for(j=i+1; j<numElements;j++){
            if (array[j] < array[indMin]) {indMin=j;}
        }        
        swap(i,indMin);   
        
        
    } 
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
   //cout << "Sorter::bubbleSortI() not implemented yet." << endl << endl;
   for (int i=(numElements-1); 0 <=i ; i--){
	for (int j=1; j<i-1; j++){
		if (array[j-1] > array[j]){
			swap(j-1, j);
		}
	}
   }
   
}
    
// Recursive Insertion Sort
void Sorter::insertionSortR() {
   //cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;	
	if (insertSortR(1)){
		insertionSortR();
	}	
}

bool Sorter::insertSortR(unsigned int i){
	unsigned int j;
	int tempNum = array[i];
	if (i>=numElements){
		return false;	
	}
	j=i;
	bool isGrt = array[j-1] > tempNum;
	if (isGrt){
		swap(j, j-1);
		j=j-1;
	}
	return isGrt or insertSortR(i+1);	
}

// Recursive Selection Sort
void Sorter::selectionSortR() {
    //cout << "Sorter::selectionSortR() not implemented yet." << endl << endl;
	if (selSortR(0)){
		selectionSortR();
	}
}

bool Sorter::selSortR(unsigned int strt){
	if (strt >= numElements-1){
		return false;
	}
	int min = strt, j=strt+1;
	bool isGtr = array[j] < array[min];	
	if (isGtr){
		min = j;
	}	        
	swap(strt,min);   
	return isGtr or selSortR(strt+1);
}	

// Recursive Bubble Sort
void Sorter::bubbleSortR() {
   //cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
   if( bubbleNest1(0) ){
		bubbleSortR();
   }
}

bool Sorter::bubbleNest1(unsigned int i){
	if (i>=numElements-1){
		return false;
	}
	bool bub = array[i] > array[i+1];
	if (bub){
		swap(i, i+1);
	}
	return bub or bubbleNest1(i+1); 

}
	


