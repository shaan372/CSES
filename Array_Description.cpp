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
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fi(i,n,a) for(ll i=n-1;i>=0;i--)
#define M 1000000007
#define inf INT_MAX
#define nl endl

using namespace std;

ll sumofdigit(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll POW(ll x, ll y){ll ans=1;for(ll i=0;i<y;i++){ans=ans*x;}return ans;}
ll ndigit(ll n){ll s=0;while(n>0){s++;n=n/10;}return s;}
ll arraysum(ll a[], ll n){ll s = 0;f(i, 0, n){s = s + a[i];}return s;}



/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/



int main(int argc, char const *argv[])
{
ll n,m;
cin>>n>>m;
ll a[n];
f(i,1,n+1){
    cin>>a[i];
}
ll dp[n+1][m+1];
memset(dp,0,sizeof(dp));
f(i,1,n+1){
    f(j,1,m+1){
        if(i==1){
            if(a[i]==0||a[i]==j)
                dp[i][j]=1;
            else
                dp[i][j]=0;    
        }
        else{
            if(a[i]==0||a[i]==j)
                dp[i][j]=((dp[i-1][j]+dp[i-1][j-1])%M+dp[i-1][j+1])%M;
            else
                dp[i][j]=0;
        }
    }
}
ll ans=0;
f(i,1,m+1){
    ans=(ans+dp[n][i])%M;
}
cout<<ans;
return 0;
}
