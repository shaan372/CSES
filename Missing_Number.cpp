#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll x;
    ll s = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> x;
        s = s + x;
    }

    ll v = (n * (n + 1)) / 2 - s;
    cout << v << '\n';
    return 0;
}
