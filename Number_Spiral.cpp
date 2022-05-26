#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 1 && y == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        if (y > x)
        {
            if (y % 2 != 0)
            {

                ll a = y * y - x + 1;
                cout << a << "\n";
            }
            else
            {
                ll a = (y - 1) * (y - 1) + x;
                cout << a << "\n";
            }
        }
        else
        {
            if (x % 2 == 0)
            {
                ll a = x * x - y + 1;
                cout << a << "\n";
            }
            else
            {

                ll a = (x - 1) * (x - 1) + y;
                cout << a << "\n";
            }
        }
    }
    return 0;
}
