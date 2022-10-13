#include <iostream>
#include <cstdlib>
#include "Array2D.h"

// This constructor is delegated to by other constructors and does all of the 
// allocation, showing an example of a delegating constructor..  
Array2D::Array2D(int numR, int numC, char differentiator) : numRows(numR), numCols(numC) {
   ary = new int*[numRows];
   for (int i = 0; i < numRows; i++) {
      ary[i] = new int[numCols];
      for (int j = 0; j < numCols; j++) {
            ary[i][j] = -1;
      }
   }
}

Array2D::Array2D(int numR, int numC) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = i;
      }
   }
}

Array2D::Array2D(int numR, int numC, int val) : Array2D(numR, numC, 'c') { 
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = val;
      }
   }
}

int& Array2D::operator( )(int row, int col) {
   return ary[row][col];
}
      
int Array2D::operator( )(int row, int col) const {
   return ary[row][col];
}

bool Array2D::sameSize(const Array2D& other)const{
   return (numRows == other.getNumRows( ) && numCols == other.getNumCols( ));
}

void Array2D::deleteAry(int** ary) {
   for (int i = 0; i < numRows; i++) {
      delete [ ] ary[i];
   }
   delete [ ] ary;
}

int Array2D::getNumRows() const{
   return numRows;
}

int Array2D::getNumCols()const {
   return numCols;
}

std::ostream& operator<<(std::ostream& os, Array2D& array){
   for(int i = 0; i < array.getNumRows(); ++i){
      for(int j = 0; j < array.getNumCols(); ++j){
         os<<" "<<array.ary[i][j];
      }
      os <<endl;
   }
   return os;
}

Array2D Array2D::operator*( const Array2D& array ){
   //more mem being allocated here
   
   if (numCols != array.getNumRows()){
      Array2D arr(numRows, numCols, -1);
      return arr;
   }
   else{
      Array2D arr(numRows, array.getNumCols(), 0);
      for(int i = 0; i < numRows; ++i){
        for(int j = 0; j < array.getNumCols(); ++j){
            for(int k = 0; k < array.getNumRows(); ++k)
            {
               arr.ary[i][j] += ary[i][k] * array.ary[k][j];
            }
        }
      }
      return arr;
   }
}

bool Array2D::operator==( const Array2D& array ){
   if (!sameSize(array)) return false;
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         if (ary[i][j] != array.ary[i][j]){
            return false;
         }
      }
   }
   return true;
}


Array2D& Array2D::operator= ( const Array2D& array ){
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         ary[i][j] = array.ary[i][j];
      }
   }
   return *this;
}



Array2D::~Array2D(){
   // delete numRows;
   // delete numCols;
   deleteAry(ary);

}

Array2D::Array2D(const Array2D& other): Array2D(other.getNumRows(), other.getNumCols(), 'c'){
   for (int i = 0; i < other.getNumRows(); i++) {
      for (int j = 0; j < other.getNumCols(); j++) {
         ary[i][j] = other.ary[i][j];
      }
   }
}
