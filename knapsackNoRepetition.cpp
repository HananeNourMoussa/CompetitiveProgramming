#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T[100][100];

int knapsack (int* weights, int* values, int W, int i)
{
   if (T[W][i] == -1)
   {
       if (i == 0)
       {
           T[W][i] = 0;
       }
       else
       {
           T[W][i] = knapsack (weights, values, W, i-1);
           if (W>= weights[i-1])
       {
           T[W][i] = max(T[W][i], knapsack(weights, values, W-weights[i-1], i-1)+values[i-1]);
       }
       }


   }
   return T[W][i];
}

int main (void)
{
    int weights[] = {6,3,4,2};
    int values[] = {30,14,16,9};
    memset(T, -1, sizeof(T));
    cout << knapsack(weights, values, 10, 4)<< endl;
    return 0;
}
