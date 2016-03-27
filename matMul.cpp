#include "matMul.h"

matMul::matMul(void)
{
}


matMul::~matMul(void)
{
}

vector<vector<int>> matMul::matrix_multiply(const vector<vector<int> >&a, int row_a, int cln,
	         const vector<vector<int> >&b, int cln_b)
{
	vector<vector<int> > c(row_a, vector<int>(cln_b));
	int sum=0;
	for(int i = 0; i < row_a; i++)
	  for(int j = 0; j < cln_b; j++){
		for(int k = 0; k < cln; k++){
			sum = sum + a[i][k]*b[k][j];
		}
		c[i][j]=sum;
		sum=0;
	  }

	  return c;

}

 /** Funtion to sub two matrices **/
vector<vector<int>> sub(vector<vector<int> > A, vector<vector<int> > B)
{
	int n = A.size();
    vector<vector<int> > C(n,n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
	return C;
      
}
    /** Funtion to add two matrices **/
vector<vector<int>> add(vector<vector<int> > A, vector<vector<int> > B)
{
    int n = A.size();
    vector<vector<int> > C(n,n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
		}
	return C;
       
}
    /** Funtion to split parent matrix into child matrices **/
void split(vector<vector<int> > P, vector<vector<int> > &C, int iB, int jB) 
{
    for(int i1 = 0, i2 = iB; i1 < C.size(); i1++, i2++)
        for(int j1 = 0, j2 = jB; j1 < C.size(); j1++, j2++){
            C[i1][j1] = P[i2][j2];
		}
}
/** Funtion to join child matrices intp parent matrix **/
void join(vector<vector<int> > &C, vector<vector<int> > &P, int iB, int jB) 
{
    for(int i1 = 0, i2 = iB; i1 < C.size(); i1++, i2++)
        for(int j1 = 0, j2 = jB; j1 < C.size(); j1++, j2++){
            P[i2][j2] = C[i1][j1];
		}
}   

vector<vector<int>> matMul::matrix_multiply_strassen(vector<vector<int> >a,
	        vector<vector<int> >b)
{        
    int n = a.size();

    vector<vector<int>> R(n,n);
    /** base case **/
    if (n == 1){
        R[0][0] = a[0][0] * b[0][0];
	}
    else
    {
			
		vector<vector<int>> A11(n/2,n/2);
        vector<vector<int>> A12(n/2,n/2);
        vector<vector<int>> A21(n/2,n/2);
        vector<vector<int>> A22(n/2,n/2);
        vector<vector<int>> B11(n/2,n/2);
        vector<vector<int>> B12(n/2,n/2);
        vector<vector<int>> B21(n/2,n/2);
        vector<vector<int>> B22(n/2,n/2);
 
        /** Dividing matrix A into 4 halves **/
        split(a, A11, 0 , 0);
        split(a, A12, 0 , n/2);
        split(a, A21, n/2, 0);
        split(a, A22, n/2, n/2);
        /** Dividing matrix B into 4 halves **/
        split(b, B11, 0 , 0);
        split(b, B12, 0 , n/2);
        split(b, B21, n/2, 0);
        split(b, B22, n/2, n/2);
 
			
        vector<vector<int> > M1 (matrix_multiply_strassen(add(A11, A22), add(B11, B22)));
        vector<vector<int> > M2(matrix_multiply_strassen(add(A21, A22), B11));
        vector<vector<int> > M3(matrix_multiply_strassen(A11, sub(B12, B22)));
        vector<vector<int> > M4(matrix_multiply_strassen(A22, sub(B21, B11)));
        vector<vector<int> > M5(matrix_multiply_strassen(add(A11, A12), B22));
        vector<vector<int> > M6(matrix_multiply_strassen(sub(A21, A11), add(B11, B12)));
        vector<vector<int> > M7(matrix_multiply_strassen(sub(A12, A22), add(B21, B22)));
 

        vector<vector<int> > C11(add(sub(add(M1, M4), M5), M7));
            vector<vector<int> > C12(add(M3, M5));
        vector<vector<int> > C21(add(M2, M4));
            vector<vector<int> > C22(add(sub(add(M1, M3), M2), M6));
 
        /** join 4 halves into one result matrix **/
        join(C11, R, 0 , 0);
        join(C12, R, 0 , n/2);
        join(C21, R, n/2, 0);
        join(C22, R, n/2, n/2);
    }
    /** return result **/    
    return R;
}
