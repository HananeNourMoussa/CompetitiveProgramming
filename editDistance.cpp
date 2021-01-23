#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

//DP solution that tackles the edit distance problem
//it returns the minimum number of edits (deletions, insertions, and character changes) to turn string A into string B

using namespace std;

int T[100][100];

int distance (string A, string B, int lena, int lenb)
{
    if (T[lena][lenb]== -1)
    {
       if(lena == 0)
       {
           T[lena][lenb] = lenb;
       }
       else if (lenb == 0)
       {
           T[lena][lenb] = lena;
       }
       else
       {
           int diff;
           A.at(lena-1) == B.at(lenb-1)? diff = 0: diff = 1;
           T[lena][lenb] = min({distance(A,B,lena-1, lenb)+1, distance(A,B,lena, lenb-1)+1, distance(A,B,lena-1, lenb-1)+diff});
       }
    }
    return T[lena][lenb];
}

int main (void)
{
    string A = "editing";
    string B = "distance";
    memset(T, -1, sizeof(T));
    cout << distance(A,B, A.size(), B.size());
    return 0;
}
