#include <bits/stdc++.h>

#define ll long long
#define vi vector<ll>
#define gi greater<ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define pb push_back
#define eb emplace_back
#define pii pair<ll, ll>
#define spi set<pii>
#define si set<int>
#define mpci map<char, ll>
#define mpii map<ll, ll>
#define f(i, a, n) for (ll i = a; i < n; i++)
#define fi(i, n, a) for (ll i = n - 1; i >= 0; i--)
#define M 1000000007
#define inf INT_MAX
#define nl endl

using namespace std;

ll sumofdigit(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        ll r = n % 10;
        s += r;
        n = n / 10;
    }
    return s;
}
ll gcd(ll a, ll b)
{
    if (b % a == 0)
    {
        return a;
    }
    else
    {
        return gcd(b % a, a);
    }
}
ll POW(ll x, ll y)
{
    ll ans = 1;
    for (ll i = 0; i < y; i++)
    {
        ans = ans * x;
    }
    return ans;
}
ll ndigit(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        s++;
        n = n / 10;
    }
    return s;
}

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

ll dp[501][125501];
ll solve(ll a[], ll n, ll s)
{
    if (s == 0)
        return 1;
    else if (n == 0)
        return 0;
    else if (dp[n - 1][s] != -1)
        return dp[n - 1][s];
    else
    {
        if (a[n - 1] <= s)
            return dp[n - 1][s] = (solve(a, n - 1, s - a[n - 1]) + solve(a, n - 1, s)) % M;
        else
            return dp[n - 1][s] = solve(a, n - 1, s) % M;
    }
}
int main(int argc, char const *argv[])
{
    ll n, s;
    cin >> n;
    ll a[n];
    memset(dp, -1, sizeof(dp));
    f(i, 0, n)
    {
        a[i] = i + 1;
    }
    if ((n + 1) % 4 == 0 || n % 4 == 0)
    {
        s = (n * (n + 1) / 4);
        cout << ((solve(a, n, s)) * 500000004) % M << nl;
    }
    else
    {
        cout << 0 << nl;
    }
    return 0;
}
