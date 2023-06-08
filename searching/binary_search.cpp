#include <bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    // binary search is for sorted  array.
    int a[] = {1, 2, 5, 15, 20, 87, 112, 556};
    int low = 0;
    int high = sizeof(a) / sizeof(a[0]);
    int k;
    cout << "Enter number you want to search in array:";
    cin >> k;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (a[mid] == k)
        {
            cout << "number is at index " << mid;
            break;
        }
        else if (a[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}
