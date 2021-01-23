#include <bits/stdc++.h>
#include <vector>
using namespace std;
void printSubset(vector <int>& subset)
{
    if (subset.size() == 0){
        cout << "{}" << endl;
    }else{
        cout << "{";
        for (int i = 0; i<subset.size(); i++)
        {
           cout << subset.at(i);
        }
        cout << "}" << endl;
    }
}
void subsets (vector <int>& A, vector<int>& subset, int index)
{
    printSubset(subset);
    for (int i = index; i < A.size(); i++)
    {
        subset.push_back(A[i]);
        subsets(A, subset, i+1);
        subset.pop_back();
    }
}


int main (void)
{
   vector <int> A = {1,2,3};
   vector <int> subset;
   subsets (A, subset, 0);
}



