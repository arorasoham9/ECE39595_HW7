#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
using namespace std;


class Array2D {

public:
   Array2D(int numR, int numC); 
   Array2D(int numR, int numC, int val); 
   Array2D(const Array2D& other); 

   virtual int& operator( )(int row, int col);
   virtual int operator( )(int row, int col) const;
   int getNumRows()const;
   int getNumCols()const;

   
   virtual Array2D operator*( const Array2D& array );
   virtual bool operator==( const Array2D& array );
   virtual Array2D& operator= ( const Array2D& array );
   virtual ~Array2D();
   // Array2D(const Array2D& other);
   int** ary;

private:
   Array2D(int numR, int numC, char differentiator);
   void deleteAry(int** ary);
   bool sameSize(const Array2D& other)const;
   int numRows;
   int numCols;
};
std::ostream& operator<<(std::ostream& os, Array2D& array);
#endif /* ARRAY2D_H_ */
