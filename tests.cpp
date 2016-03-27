
#include <vector>
#include <iostream>
#include "matMul.h"
using namespace std;

void testTraditional(matMul x){
	cout<<"Testing Traditional Multiplication";
	vector<vector<int> > a(2, vector<int>(2));
	vector<vector<int> > b(2, vector<int>(2));
    vector<vector<int> > c(2, vector<int>(2));
	vector<vector<int> > d(2, vector<int>(2));
	a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
	b[0][0] = 4; b[0][1] = 3; b[1][0] = 2; b[1][1] = 1;
	c[0][0] = 8; c[0][1] = 5; c[1][0] = 20; c[1][1] = 13;
	d = x.matrix_multiply(a,2,2,b,2);
	if (equal(c.begin(), c.begin()+2, d.begin()))
		cout << "\nTest Passed!" <<endl;
	else
		cout<<"\nTest Failed!"<<endl;
}

void testStrassens(matMul x){
	cout<<"\n\nTesting Strassens Multiplication";
	vector<vector<int> > a(2, vector<int>(2));
	vector<vector<int> > b(2, vector<int>(2));
    vector<vector<int> > c(2, vector<int>(2));
	vector<vector<int> > d(2, vector<int>(2));
	a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
	b[0][0] = 4; b[0][1] = 3; b[1][0] = 2; b[1][1] = 1;
	c[0][0] = 8; c[0][1] = 5; c[1][0] = 20; c[1][1] = 13;
	d = x.matrix_multiply_strassen(a,b);
	if (equal(c.begin(), c.begin()+2, d.begin()))
		cout << "\nTest Passed!" <<endl;
	else
		cout<<"\nTest Failed!"<<endl;
}

void testEquality(matMul x){
	cout<<"\n\nTesting Equality";
	vector<vector<int> > a(2, vector<int>(2));
	vector<vector<int> > b(2, vector<int>(2));
    vector<vector<int> > c(2, vector<int>(2));
	vector<vector<int> > d(2, vector<int>(2));
	a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
	b[0][0] = 4; b[0][1] = 3; b[1][0] = 2; b[1][1] = 1;
	c = x.matrix_multiply(a,2,2,b,2);
	d = x.matrix_multiply_strassen(a,b);
	if (equal(c.begin(), c.begin()+2, d.begin()))
		cout << "\nTest Passed!" <<endl;
	else
		cout<<"\nTest Failed!"<<endl;
}

void main(){
	matMul x;
	testTraditional(x);
	testStrassens(x);
	testEquality(x);
}


