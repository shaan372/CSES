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
    ll n, s;
    cin >> n >> s;
    ll a[n], b[n];
    f(i, 1, n+1)
    {
        cin >> a[i];
    }
    f(i, 1, n+1)
    {
        cin >> b[i];
    }
    int dp[n + 1][s + 1];
    f(i, 0, n+1)
    {
        f(j, 0, s + 1)
        {
            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else
            {
                int op1 = (i == 1) ? 0 : dp[i - 1][j];
                int op2 = (j < a[i]) ? 0 : b[i] + dp[i - 1][j - a[i]];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    cout << dp[n][s];
    return 0;
}
