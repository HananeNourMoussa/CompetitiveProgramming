#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
//a DP solution to the coin change problem in its general case (when the greedy algorithm does not work)
using namespace std;
int T[100];
int change (int value, int n, int* coins)
{
    //did not use memset because cell with index value needs to be included
    for (int k = 0; k<=value; k++)
    {
        T[k] = INT_MAX;
    }
    T[0] = 0; // base case
    for (int i = 1; i <= value; i++) //loop on the values of target value
    {
        for (int j = 0; j < n; j++) //loop on the coins
        {
            if (coins[j] <= i)//if coin can be included in the change
            {
                T[i] = min (T[i], 1 + T[i-coins[j]]);
            }
        }
    }
    return T[value];
}

int main (void)
{
    int value = 50;
    int n = 5;
    int coins[] = {1,2,3,4,5};
    cout << change(value, n, coins);
    return 0;
}

