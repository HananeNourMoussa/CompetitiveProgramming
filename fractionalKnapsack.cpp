#include <bits/stdc++.h>

using namespace std;
//greedy algorithm to solve the fractional knapsack problem
struct Item
{
    int value, weight;


    Item(int value, int weight)
        : value(value)
        , weight(weight)
    {
    }
};

// Comparison function to sort Item according to value/weight
// ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item, add fractional part
        // of it
        else
        {
            int remain = W - curWeight;
            finalvalue
                += arr[i].value
                   * ((double)remain / (double)arr[i].weight);
            break;
        }
    }


    return finalvalue;
}

int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(arr) / sizeof(arr[0]);


    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}
