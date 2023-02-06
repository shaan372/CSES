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
ll mod_add(ll a, ll b, ll m){ll res = (a % m + b % m + m) % m;return res;}
ll mod_mul(ll a, ll b, ll m){ll res = (a % m * b % m) % m;return res;}
ll mod_sub(ll a, ll b, ll m){ll res = (a % m - b % m + m) % m;return res;}
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

const ll max_n = 8e5 + 10;
ll seg[max_n] = {0};
void build(ll l, ll r, ll i, vector<ll> &v)
{
    if (l == r)
    {
        seg[i] = v[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, 2 * i + 1, v);
    build(mid + 1, r, 2 * i + 2, v);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
void update(ll i, ll l, ll r, ll ind, ll val)
{
    if (l == r)
    {
        if (l == ind)
            seg[i] += val;
        return;
    }
    if (ind < l || ind > r)
        return;
    ll mid = (l + r) >> 1;
    update(2 * i + 1, l, mid, ind, val);
    update(2 * i + 2, mid + 1, r, ind, val);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
ll sum(ll i, ll l, ll r, ll low, ll high)
{
    if (l >= low && r <= high)
        return seg[i];
    if (l > high || r < low)
        return 0;
    ll mid = (l + r) >> 1;
    ll left = sum(2 * i + 1, l, mid, low, high);
    ll right = sum(2 * i + 2, mid + 1, r, low, high);
    ll ans = left + right;
    return ans;
}
void run_case()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[i] += x;
        v[i + 1] -= x;
    }
    build(0, n - 1, 0, v);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll l, r, u;
            cin >> l >> r >> u;
            update(0, 0, n - 1, l - 1, u);
            update(0, 0, n - 1, r, -u);
        }
        else
        {
            ll k;
            cin >> k;
            ll ans = sum(0, 0, n - 1, 0, k - 1);
            cout << ans << nl;
        }
    }
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