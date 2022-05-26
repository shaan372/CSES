#include <bits/stdc++.h>
 
#define ll long long
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
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
#define inf 1e18
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
 
 
/*---------------------------------------------------------------------------------------------------------------*/
 
 
/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/
 
int n, m;
 
vector<vector<pair<int, int>>> path;
vector<vector<bool>> vis;
 
int sx, sy, ex, ey;
 
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
bool isValid(int x, int y)
{
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y])
        return false;
    return true;
}
 
void bfs()
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (auto mv : moves)
        {
            int mvx = mv.first;
            int mvy = mv.second;
            if (isValid(cx + mvx, cy + mvy))
            {
                q.push({cx + mvx, cy + mvy});
                vis[cx + mvx][cy + mvy] = true;
                path[cx + mvx][cy + mvy] = {mvx, mvy};
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    fast_io;
    cin >> n >> m;
    path.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; ++i)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            path[i][j] = {-1, -1};
            char c;
            cin >> c;
            if (c == '#')
            {
                vis[i][j] = true;
            }
            if (c == 'A')
            {
                sx = i;
                sy = j;
            }
            if (c == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
 
    if (!vis[ex][ey])
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
 
    vector<pair<int, int>> ans;
    pair<int, int> end = {ex, ey};
 
    while (end.first != sx or end.second != sy)
    {
        ans.push_back(path[end.first][end.second]);
        end.first -= ans.back().first;
        end.second -= ans.back().second;
    }
 
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto c : ans)
    {
        if (c.first == 1 and c.second == 0)
        {
            cout << 'D';
        }
        else if (c.first == -1 and c.second == 0)
        {
            cout << 'U';
        }
        else if (c.first == 0 and c.second == 1)
        {
            cout << 'R';
        }
        else if (c.first == 0 and c.second == -1)
        {
            cout << 'L';
        }
    }
    return 0;
}