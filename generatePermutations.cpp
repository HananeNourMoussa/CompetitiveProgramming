#include <bits/stdc++.h>
#include <vector>

using namespace std;
//generating all permutations using heap's algorithm
void printArr(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        cout << arr[i];
    }
    cout <<endl;
}
void heapPermutation (int arr[], int len, int n)
{
    if (len == 1)
    {
        printArr (arr,n);
        return;
    }
    else
    {

        for (int i = 0; i<len; i++)
        {
            heapPermutation(arr, len-1, n);
            if (len%2 == 0)
            {
                swap(arr[0], arr[len-1]);
            }
            else
            {
                swap(arr[i], arr[len-1]);
            }
        }
    }

}
int main (void){
    int arr []= {1,2,3};
    heapPermutation(arr, 3, 3);
    return 0;
}





