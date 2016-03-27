#pragma once
#include<vector>
using namespace std;
class matMul
{
public:
	matMul(void);
	~matMul(void);
	vector<vector<int>> matrix_multiply(const vector<vector<int> >&a, int row_a, int cln, const vector<vector<int> >&b, int cln_b);
	vector<vector<int>> matrix_multiply_strassen(vector<vector<int> >a, vector<vector<int> >b);
};

