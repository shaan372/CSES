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
ll a[n];
f(i,0,n){
    cin>>a[i];
}
vi dp(s+1,0);
dp[0]=1;
f(i,1,s+1){
    f(j,0,n){
        if(i-a[j]>=0)
        dp[i]=(dp[i]+dp[i-a[j]])%M;
    }
}
cout<<dp[s];
return 0;
}
