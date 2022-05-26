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
#define fi(i, n, a) for (ll i = n - 1; i >= a; i--)
#define M 1000000007
#define nl endl

using namespace std;

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    int dp[n + 1][n + 1];
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {

            if (i == n && j == n)
                dp[i][j] = 1;
            else
            {
                int op1 = (i == n) ? 0 : dp[i + 1][j];
                int op2 = (j == n) ? 0 : dp[i][j + 1];
                dp[i][j] = (op1 + op2) % M;
                if (a[i][j] == 1)
                    dp[i][j] = 0;
            }
        }
    }
    if (a[n][n] == 1)
        cout << 0;
    else
        cout << dp[1][1];
    return 0;
}
