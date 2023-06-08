#include <bits/stdc++.h>
using namespace std;

// #define int long long int
int mySqrt(int x)
{
    long long int i = 1;
    if (x == 1 || x == 2)
    {
        return 1;
    }
    else
    {
        while (i < (x))
        {
            if (x < (i * i))
            {
                return (i - 1);
                break;
            }
            i++;
        }
    }
    return 0;
}
int bs_sqrt(int x)
{
}
signed main()
{
    cout << mySqrt(8);
}