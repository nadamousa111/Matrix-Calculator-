#include <iostream>
#include "Matrix.h"
using namespace std;


class MatrixCalculator {

public:

MatrixCalculator(){
    int choice , matrix1Rows,matrix1Columns,matrix2Rows,matrix2Columns ;
cout << "Welcome to FCI Matrix Calculator" << endl;
    cout << endl ;
    cout << "----------------------" << endl << endl ;
    cout <<"1-perform Matrix Addition" << endl << "2-Perform Matrix subtraction" << endl << "3-Perform Matrix Multiplication" << endl << "4-Matrix Transpose" << endl;


cout << "choose the option of the operation you want to perform" ;
cin >> choice ;
cout << "Enter number of rows and columns of the first matrix ";
cin >> matrix1Rows>>matrix1Columns ;
cout << endl;

Matrix<int> matrix1(matrix1Rows,matrix1Columns);
cout<< "Enter the first matrix";
cin >> matrix1;

cout << endl;
cout << "Enter number of rows and columns of the second matrix ";
cin >> matrix2Rows>>matrix2Columns ;

Matrix<int> matrix2(matrix2Rows,matrix2Columns);
cout<< "Enter the second matrix";
cin >> matrix2;


switch(choice) {

case 1:
if(matrix1Rows!=matrix2Rows || matrix1Columns!=matrix2Columns)
    cout <<"Invalid addition"<<endl ;
else
cout << matrix1 + matrix2 ;
break;

case 2 :
    if(matrix1Rows!=matrix2Rows || matrix1Columns!=matrix2Columns)
    cout <<"Invalid subtraction"<<endl ;
else
cout << matrix1 - matrix2 ;
break ;

case 3 :
    if(matrix1Columns!=matrix2Rows)
        cout << "Invalid multiplication"<< endl ;
    else
cout << matrix1 * matrix2 ;
break;

case 4 :
 cout <<matrix1.Transpose(matrix1);
 cout <<matrix2.Transpose(matrix2) ;
break;
}
}


};

int main()
{

MatrixCalculator m1 ;

    return 0;
}
