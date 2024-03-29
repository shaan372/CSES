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