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
    ll a[n];
    f(i, 0, n)
    {
        cin >> a[i];
    }
    vi dp(s+1,0);
    dp[0]=1;
    f(j,0,n){
        f(i,1,s+1){
            if(i-a[j]>=0)
                dp[i] = (dp[i]+dp[i-a[j]])%M;
        }
    }
    cout<<dp[s];
    return 0;
}
