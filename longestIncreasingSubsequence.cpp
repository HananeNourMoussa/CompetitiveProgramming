#include <bits/stdc++.h>
#include <iostream>
//DP solution to the longest increasing subsequence problem using tabulation
using namespace std;
int T[100];
void LIS (int* A)
{
    for (int i  = 0; i < 13; i++)
    {
        T[i]  = 1;
        for (int j = 0; j < i; j++)
        {
            if((A[j] < A[i]) && (T[i] < T[j]+1))
            {
                T[i] = T[j] + 1;
            }
        }
    }
}
int main (void)
{
    memset(T, 0, sizeof(T));
    int A[] = {7, 2, 1, 3, 8, 4, 9, 1, 2, 6, 5, 9, 3};
    LIS(A);
    /*int maxi = 0;
    for (int i = 0; i<13; i++)
    {
            if (T[i] > maxi)
                maxi = T[i];
    }
    cout << maxi;*/
    cout << *max_element(T, T+13);

    return 0;
}
