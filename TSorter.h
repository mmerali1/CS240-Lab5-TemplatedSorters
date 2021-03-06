#ifndef TSORTER_H
#define TSORTER_H

#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <vector>
#include <string>
#include "Circle.h"

using namespace std;

template <class T> 
class TSorter {
   private:
      typename vector<T>::iterator iter;
      vector <T> vec;
      unsigned int numElements;
      void swap(typename vector<T>::iterator i, typename vector<T>::iterator j); 

  public:
      TSorter();
      ~TSorter();

      void clear(); 
      void insert(T element); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values

      // Show the first n elements, k per line using << 
      void show(); 

      // "Shuffle" the array elements
      void shuffle(); 

      // These are the functions you should implement for Lab 5
      // You should keep these interfaces the same, but you may add
      // other "helper" functions if necessary.
      void insertionSortI();
      void selectionSortI();
      void bubbleSortI();     
      void insertionSortR(); 
      void selectionSortR();	
      void bubbleSortR();
      
      //Aux functions
      bool insertSortR(typename vector<T>::iterator i); 	
      bool selSortR(typename vector<T>::iterator i);
      bool bubbleNest1(typename vector<T>::iterator i);
};

#endif
