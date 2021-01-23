#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
//solving the chain matrix multiplication problem using memoization
using namespace std;

int T[100][100];

int matrixMult (int* m, int i, int j)
{
    if (T[i][j]!= -1)
    {
        return T[i][j];
    }
    if (i==j){
        return 0;
    }
    T[i][j] = INT_MAX;
    for (int k = i; k<j; k++)
    {
        T[i][j] = min(T[i][j], matrixMult(m,i,k)+matrixMult(m,k+1,j)+m[i-1]*m[k]*m[j]);
    }
    return T[i][j];
}


int main(void)
{
    int matrices[] = {50,20,1,10,100};
    memset(T, -1, sizeof(T));
    cout << matrixMult(matrices,1,4);
}
