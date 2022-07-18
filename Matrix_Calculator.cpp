#include "Matrix.h"

template <class T>
Matrix<T>::Matrix(){

 rows = 0 ;
columns = 0 ;
}

template <class T>
Matrix<T>::Matrix(int rows , int columns )
{
this -> rows = rows ;
this -> columns = columns ;
matrixData = new T*[rows];

for (int i=0 ; i<rows;i++)
matrixData[i] = new int[columns] ;

}

template <class T>
Matrix<T>::Matrix(const Matrix& mat)
{
this -> rows = mat.rows ;
this -> columns = mat.columns ;
this->matrixData = new T*[rows];

for (int i=0 ; i<rows;i++)
this->matrixData[i] = new T[columns] ;

for (int i=0 ; i<rows;i++)
    for(int j=0;j<columns;j++)
      this->matrixData[i][j] = mat.matrixData[i][j];

}

template <class Temp1>
 istream & operator >>(istream & matrixInput , Matrix<Temp1> & matrix){
 for(int i =0;i<matrix.rows;i++){
         for(int j =0;j<matrix.columns;j++){
            matrixInput>> matrix.matrixData[i][j] ;
         }

   }
     return matrixInput ;
}


template <class Temp1>
 ostream& operator <<(ostream& matrixOutput ,const  Matrix<Temp1>& matrix){
 for(int i =0;i<matrix.rows;i++){
         for(int j =0;j<matrix.columns;j++){
            matrixOutput<< matrix.matrixData[i][j] << " " ;
         }
    matrixOutput << endl ;
   }
     return matrixOutput ;
}

template <class T>
Matrix<T> Matrix<T>:: operator +(const Matrix & matrixObject){

    Matrix sum(rows,matrixObject.columns);
    for(int i =0;i<rows;i++){
         for(int j =0;j<columns;j++) {
            sum.matrixData[i][j] = matrixData[i][j] + matrixObject.matrixData[i][j];
         }
    }

  return sum ;
}

template <class T>
Matrix<T> Matrix<T>:: operator -(const Matrix& matrixObject){

    Matrix subtraction(rows,matrixObject.columns);
    for(int i =0;i<rows;i++){
         for(int j =0;j<columns;j++) {
            subtraction.matrixData[i][j] = matrixData[i][j] - matrixObject.matrixData[i][j];
         }
    }

  return subtraction ;
}

template <class T>
Matrix<T> Matrix<T>:: operator *(const Matrix& matrixObject2){
    Matrix matrixObject1 = *this ;  // This returns reference of the object
    Matrix multiplication(matrixObject1.rows,matrixObject2.columns);

    for(int i =0;i<matrixObject1.rows;i++){
         for(int j =0;j<matrixObject2.columns;j++) {
                multiplication.matrixData[i][j] = 0;
         for(int k =0;k<matrixObject1.columns;k++)
            multiplication.matrixData[i][j] += matrixData[i][j] * matrixObject2.matrixData[i][j];
         }
    }

  return multiplication ;


}

template <class T>
Matrix<T> Matrix<T>::Transpose(Matrix &matrix){

Matrix transpose(columns,matrix.rows);

for(int i =0;i<rows;i++)
         for(int j =0;j<columns;j++)
             {transpose.matrixData[i][j] = matrix.matrixData[j][i];}

for(int i =0;i<rows;i++)
         for(int j =0;j<columns;j++)
             {matrix.matrixData[i][j] = transpose.matrixData[i][j];}

       return matrix ;
}


template <class T>
Matrix<T>::~Matrix()
{
    for(int i=0;i<rows;i++)
    delete [] matrixData[i] ;

}


template class Matrix<int>;
template std::istream & operator>> <int>(std::istream&,Matrix<int>&);
template std::ostream & operator<< <int>(std::ostream&,Matrix<int> const &);








