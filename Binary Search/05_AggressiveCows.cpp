#include <iostream>
#include<algorithm>
using namespace std;

bool canPlaceCows(int *stalls, int n, int cows, int minSeparation)
{
    int lastCow = stalls[0];

    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastCow >= minSeparation) // we can place cow
        {
            lastCow = stalls[i];
            cnt++;
            if (cnt == cows)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    int stalls[] = {1, 2, 4, 8, 9}; // represents the position of stalls

    int cows = 3; // number of cows to be arranged

    int n = sizeof(stalls) / sizeof(int);

    sort(stalls, stalls+n); // first we have to sort the array

    int s = 0;
    int e = stalls[n - 1] - stalls[0];

    int ans = 0;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        bool cowsRakhPaye = canPlaceCows(stalls, n, cows, mid);

        if (cowsRakhPaye)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}