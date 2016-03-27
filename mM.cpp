#include <vector>
#include <iostream>
#include <stdio.h>
#include "matMul.h"
using namespace std;

int main()
{

	int row_a = 0;
	int cln_b = 0;
	int cln = 0;
	matMul x;
	cout<< "Enter number of rows for matrix A: ";
	cin>>row_a;
	cout<< "Enter number of columns for matrix A/rows for matrix B: ";
	cin>>cln;
	cout<< "Enter number of columns for matrix B: ";
	cin>>cln_b;

	vector<vector<int> > a(row_a, vector<int>(cln));
	vector<vector<int> > b(cln, vector<int>(cln_b));
	vector<vector<int> > c(row_a, vector<int>(cln_b));
	vector<vector<int> > d(row_a, vector<int>(cln_b));
	int abc;

	cout<<"\nMatrix A:\n";
	for (int i = 0 ; i < row_a ; i++ ){
         for ( int j = 0 ; j < cln ; j++ ){
            a[i][j] = rand()%10 + 1;
			cout << a[i][j]<<"\t";
		 }
		 cout<<"\n";
	}

	cout<<"\nMatrix B:\n";
	for (int i = 0 ; i < cln ; i++ ){
         for ( int j = 0 ; j < cln_b ; j++ ){
            b[i][j] = rand()%10 + 1;
			cout << b[i][j]<<"\t";
		 }
		 cout<<"\n";
	}

	c = x.matrix_multiply(a,row_a,cln,b,cln_b);

	cout<<"\nResult:\n";
	for (int i = 0 ; i < row_a ; i++ ){
		for ( int j = 0 ; j < cln_b ; j++ )
			cout<<c[i][j]<<"\t";
		cout<<endl;
	}

	d = x.matrix_multiply_strassen(a,b);
	cout<<"\nResult using Strassen Algorithm:\n";
	for (int i = 0 ; i < row_a ; i++ ){
		for ( int j=0; j < cln_b ; j++ )
			cout<<d[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}