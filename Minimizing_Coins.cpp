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
#define nl endl

using namespace std;

ll sumofdigit(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll POW(ll x, ll y){ll ans=1;for(ll i=0;i<y;i++){ans=ans*x;}return ans;}
ll ndigit(ll n){ll s=0;while(n>0){s++;n=n/10;}return s;}



/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
ll n,s;
cin>>n>>s;
ll i, j;
ll a[n];
f(i,0,n){
    cin>>a[i];
}
vi dp(s+1,1e9);
dp[0]=0;
for(i=1;i<=s;i++){
    for(j=0;j<n;j++){
        if(i-a[j]>=0)
        dp[i]=min(dp[i],dp[i-a[j]]+1);
    }
}
if(dp[s]==1e9)
cout<<"-1";
else
cout<<dp[s];
return 0;
}
