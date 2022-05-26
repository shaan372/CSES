#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    ll n = s.length();
    ll x = 1;
    ll mx = 1;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            x++;
        else
            x = 1;
        mx = max(mx, x);
    }

    cout << mx << "\n";
    return 0;
}
