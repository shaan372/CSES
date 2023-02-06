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

void google_case(ll i){cout<<"Case #"<<i<<": ";}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll inv(ll n, ll m) {ll res = expo(n, m-2, m); return res;}
ll mod_add(ll a, ll b, ll m){ll res = (a % m + b % m) % m;return res;}
ll mod_mul(ll a, ll b, ll m){ll res = (a % m * b % m) % m;return res;}
ll mod_sub(ll a, ll b, ll m){ll res = (a % m - b % m + m) % m;return res;}
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

void get_lev(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &level, vector<vector<ll>> &dp)
{
    level[node] = par == -1 ? 0 : 1 + level[par];
    dp[node][0] = par;
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        get_lev(child, node, adj, level, dp);
    }
}
ll find_lca(vector<vector<ll>> &dp, vector<ll> &level, ll a, ll b)
{
    if (level[b] < level[a])
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
void dfs(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &ans)
{
    ll x = ans[node];
    for (auto child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node, adj, ans);
        x += ans[child];
    }
    ans[node] = x;
}
void run_case()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> e(n + 1);
    ll l = log2(n) + 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(l, -1));
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    vector<ll> level(n + 1, 0);
    get_lev(1, -1, e, level, dp);
    for (ll j = 1; j < l; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            ll x = dp[i][j - 1];
            if (x != -1)
                dp[i][j] = dp[x][j - 1];
        }
    }
    vector<ll> ans(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ll x = find_lca(dp, level, u, v);
        ans[u]++;
        ans[v]++;
        ans[x]--;
        ll y = dp[x][0];
        if (y != -1)
            ans[y]--;
    }
    dfs(1, -1, e, ans);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        // google_case(i);
        run_case();
    }
    return 0;
}