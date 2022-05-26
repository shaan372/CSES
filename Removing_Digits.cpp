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
#define nl endl

using namespace std;

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    vi dp(n + 1);
    dp[0] = 0;
    f(i, 1, n + 1)
    {
        int t = i;
        ll m = 1000002;
        while (t != 0)
        {
            int d = t % 10;
            t=t/10;
            if (d == 0)
                continue;
            else
            {
                m = min(m, 1 + dp[i - d]);
            }
        }
        dp[i]=m;
    }
    cout << dp[n];
    return 0;
}
