#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
#define M 1000000007
#define inf 1000000000000000005
#define MOD 998244353
#define nl endl

using namespace std;
using namespace __gnu_pbds;

template <class T> using maxheap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T, class V = less<T>> using pbds = tree<T, null_type, V, rb_tree_tag, tree_order_statistics_node_update>; //find_by_order, order_of_key

/*-------------------------------------------------------------------------------------------------------------------------------------*/

ll digitsum(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll inv(ll i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll binExpo(ll a, ll b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

void dfs(ll src, ll par, vector<vector<ll>> &adj, vector<vector<ll>> &dp, vector<ll> &level)
{
    level[src] = 1 + level[par];
    dp[src][0] = par;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        dfs(child, src, adj, dp, level);
    }
}
ll find_lca(ll a, ll b, vector<vector<ll>> &dp, vector<ll> &level)
{
    if (level[a] > level[b])
        swap(a, b);
    ll k = level[b] - level[a];
    while (k > 0)
    {
        ll j = log2(k);
        b = dp[b][j];
        k = k - (1 << j);
    }
    if (a == b)
        return a;
    ll m = dp[0].size();
    for (ll i = m - 1; i >= 0; i--)
    {
        if (dp[a][i] != -1 && dp[b][i] != -1 && dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> adj(n + 1);
    vector<ll> level(n + 1, 0);
    ll k = log2(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0, adj, dp, level);
    for (ll j = 1; j <= k; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            ll v = dp[i][j - 1];
            if (v != -1)
                dp[i][j] = dp[v][j - 1];
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll l = find_lca(a, b, dp, level);
        ll ans = level[a] + level[b] - 2 * level[l];
        cout << ans << nl;
    }
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t;
    // cin >> t;
    t = 1;
    while (t--)
        solve();
    return 0;
}