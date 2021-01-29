#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int kadane (int* A)
{
    int sum = 0;
    int ans = 0;
    for (int i = 0; i<9; i++)
    {
        sum += A[i];
        ans = max(ans, sum);
        if (sum<0)
        {
            sum = 0;
        }
    }
    return ans;
}

int main (void)
{
    int A[] = {4,-5,4,-3,4,4,-4,4,-5};
    cout << "max 1-D range sum: "<< kadane (A);
    return 0;
}
