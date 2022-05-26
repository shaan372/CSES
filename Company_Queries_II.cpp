#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define gi greater<ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<ll, ll>
#define spi set<pii>
#define si set<int>
#define mpci map<char, ll>
#define mpii map<ll, ll>
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fi(i,n,a) for(ll i=n-1;i>=0;i--)
#define all(x) (x).begin(), (x).end()
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
#define M 1000000007
#define inf 9223372036854775807
#define MOD 998244353
#define nl endl

using namespace std;


/*------------------------------------SOME BASIC FUNCTION--------------------------------------------------*/

ll sumofdigit(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll POW(ll x, ll y){ll ans=1;for(ll i=0;i<y;i++){ans=ans*x;}return ans;}
ll ndigit(ll n){ll s=0;while(n>0){s++;n=n/10;}return s;}
ll arraysum(ll a[], ll n){ll s = 0;f(i, 0, n){s = s + a[i];}return s;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(int n){if (n <= 1) return false; for (int i = 2; i < n; i++)if (n % i == 0) return false; return true;}
int binExpo(int a, int b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
int fast_mul(int x, int y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}


/*---------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

void dfs(vector<vector<ll>> &e, ll u, ll par, vector<ll> &lev)
{
    lev[u] = lev[par] + 1;
    for (auto v : e[u])
    {
        if (u != par)
            dfs(e, v, u, lev);
    }
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> v(n + 1);
    ll l = log2(n);
    vector<vector<ll>> par(n + 1, vector<ll>(l + 1, -1));
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        v[x].pb(i);
        par[i][0] = x;
    }
    vector<ll> lev(n + 1, 0);
    lev[1] = 0;
    dfs(v, 1, 0, lev);
    for (ll i = 1; i <= l; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll v = par[j][i - 1];
            if (v != -1)
                par[j][i] = par[v][i - 1];
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (lev[a] > lev[b])
            swap(a, b);
        ll k = lev[b] - lev[a];
        while (k > 0)
        {
            ll j = log2(k);
            b = par[b][j];
            k = k - (1 << j);
        }
        if (a == b)
        {
            cout << a << nl;
            continue;
        }
        for (ll i = l; i >= 0; i--)
        {
            if (par[a][i] != -1 && par[b][i] != -1 && par[a][i] != par[b][i])
            {
                a = par[a][i];
                b = par[b][i];
            }
        }
        cout << par[a][0] << nl;
    }
    return 0;
}
