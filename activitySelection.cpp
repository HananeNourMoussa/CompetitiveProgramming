#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//greedy approach to fit in the max number of meetings
//we select the meeting with the earliest finish time, remove all intersecting ones, and repeat
int selectActivities (int* start, int* finish)
{
    int i, j;
    cout<< "Selected Activities: ";
    i = 0;
    cout << i<<" ";
    for (j = 1; j < 6; j++)
    {
        if (start[j] >= finish[i])
        {
            cout <<j<<" ";
            i = j;
        }

    }
}

int main (void)
{
    int start[] = {1,3,0,5,8,5};
    int finish[] = {4,2,6,9,7,9}; // the finish array should be sorted
    sort(finish, finish+6);
    selectActivities(start, finish);
    return 0;
}
