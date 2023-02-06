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
#define nl '\n'

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

void run_case()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> a;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (a.size() == 0)
        {
            a.pb(v[i]);
            continue;
        }
        auto it = upper_bound(all(a), v[i]);
        if (it == a.end())
            a.pb(v[i]);
        else
            *it = v[i];
    }
    cout << a.size() << nl;
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