#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 2 || n == 3)
        cout << "NO SOLUTION"
             << "\n";
    else if (n % 2 == 0)
    {

        for (ll i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (ll i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
    }
    else
    {

        for (ll i = n - 1; i > 0; i -= 2)
        {
            cout << i << " ";
        }
        for (ll i = n; i > 0; i -= 2)
        {
            cout << i << " ";
        }
    }

    return 0;
}
