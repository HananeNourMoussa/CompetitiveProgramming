#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T[100];

int knapsack (int* weights, int* values, int W)
{
    if (T[W] == -1)
    {
       T[W] = 0;
       for (int i = 0; i<4; i++)
       {
           if (weights[i] <= W)
           {
                T[W] = max(T[W], knapsack(weights, values, W - weights[i]) + values[i]);
           }
       }
    }
    return T[W];
}
int main(void)
{
    int weights[] = {6,3,4,2};
    int values[] = {30,14,16,9};
    int W = 10;
    memset (T, -1, sizeof(T));
    cout << knapsack (weights, values, W);
    return 0;
}
