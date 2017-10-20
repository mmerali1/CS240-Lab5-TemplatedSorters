#include <iostream>
using namespace std;

#include "TSorter.h"

template <class T> 
void TSorter<T>::swap(typename vector<T>::iterator i, typename vector<T>::iterator j) {
    T tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
   	return; 
}

template <class T> 
TSorter<T>::TSorter() {
	numElements = vec.size();
}

template <class T> 
void TSorter<T>::clear() {
   vec.clear();
   return; 
}

template <class T> 
void TSorter<T>::insert(T element) {
   vec.push_back(element);
	numElements++;
}

template <class T>
TSorter<T>::~TSorter() {
  // if (vec) {
     // delete vec; 
      numElements = 0; 
 //  }
}

// Shuffle array elements
template <class T> 
void TSorter<T>::shuffle() {
	std::random_shuffle(vec.begin(), vec.end());
}

// Show the first n elements, k per line, using << 
template <class T>
void TSorter<T>::show() {
   for (iter=vec.begin();iter!=vec.end();iter++) {
		cout << *iter << " ";  
   }
   cout << endl << endl;
}


// Iterative Insertion Sort
template <class T>
void TSorter<T>::insertionSortI() {
	//cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;
	typename vector<T>::iterator i, j;
	T temp;
   	for(i=(vec.begin()+1);i!=vec.end();i++){
		temp=*i;
		j=i;
        while((j!=vec.begin()) && (*(j-1) > temp)){        
            swap(j, j-1);
			j = j-1;
        }

   }
}

// Iterative Selection Sort
template <class T>
void TSorter<T>::selectionSortI() {
   //cout << "Sorter::selectionSortI()" << endl << endl;
	typename vector<T>::iterator i,j , min;
    for (i=vec.begin(); i!=vec.end()-1;i++){
        min = i;
        for(j=i+1; j<vec.end();j++){
            if (*j < *min) {min=j;}
        }        
        swap(i,min);   
        
        
    } 
}

// Iterative Bubble Sort
template <class T>
void TSorter<T>::bubbleSortI() {
   //cout << "Sorter::bubbleSortI() not implemented yet." << endl << endl;
	typename vector<T>::iterator i,j , min;
   for (i=vec.end(); vec.begin()!=i ; i--){
		for (j=vec.begin()+1; j!=i; j++){
			if (*(j-1) > *j){
				swap(j-1, j);
			}
		}
   }
}
   
//Recursive Insertion Sort
template <class T>
void TSorter<T>::insertionSortR() {
   //cout << "Sorter::insertionSortI() not implemented yet." << endl << endl;	
	if (insertSortR(vec.begin()+1)){
		insertionSortR();
	}	
}

template <class T>
bool TSorter<T>::insertSortR(typename vector<T>::iterator i){
	typename vector<T>::iterator j;
	T temp;
	if (i>vec.end()-1){
		return false;
	}
	temp = *i;
	j=i;
	bool isGrt = (*(j-1) > temp);
	if (isGrt){
		swap(j, j-1);
		j=j-1;
	}
	return isGrt or insertSortR(i+1);	
}


// Recursive Selection Sort
template <class T>
void TSorter<T>::selectionSortR() {
    //cout << "Sorter::selectionSortR() not implemented yet." << endl << endl;
	if (selSortR(vec.begin())){
		selectionSortR();
	}
}
template <class T>
bool TSorter<T>::selSortR(typename vector<T>::iterator i){
	if (i >= vec.end()-1){
		return false;
	}
	typename vector<T>::iterator min = i, j=i+1;
	bool isGtr = *j < *min;	
	if (isGtr){
		min = j;
	}	        
	swap(i,min);   
	return isGtr or selSortR(i+1);
}	

// Recursive Bubble Sort
template <class T>
void TSorter<T>::bubbleSortR() {
   //cout << "Sorter::bubbleSortR() not implemented yet." << endl << endl;
   if(bubbleNest1(vec.begin())){
		bubbleSortR();
   }
}
template <class T>
bool TSorter<T>::bubbleNest1(typename vector<T>::iterator i){
	if (i>=vec.end()-1){
		return false;
	}
	bool bub = (*i > *(i+1));
	if (bub){
		swap(i, i+1);
	}
	return bub or bubbleNest1(i+1); 

}
	


template class TSorter<int>;
template class TSorter<string>;
template class TSorter<Circle>;
