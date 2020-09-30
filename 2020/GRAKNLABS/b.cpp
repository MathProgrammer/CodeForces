#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define     ll          long long int
#define     ld          double
#define     REP(i,x,n)    for(ll i=x;i<n;i++)
#define     SZ(v)       (ll)v.size()
#define     endl        "\n"
#define     ff          first
#define     ss          second
#define     PQ_MIN      priority_queue <ll, vector<ll>, greater<ll> >
#define     PQ          priority_queue <int>
#define     pbds        tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define     setbit(x)   __builtin_popcount(x)
#define     prec(n)     fixed<<setprecision(n)
#define     pb(n)       push_back(n)
#define     mp(a,b)     make_pair(a,b)
#define     clr(n)      memset(n,0,sizeof(n))
#define     reset(n)    memset(n,-1,sizeof(n))
#define     ii          pair<ll,ll>
#define     vll         vector<ll>
#define     PI          3.1415926535897932384626433832795028841971693993751

using namespace std;
using namespace __gnu_pbds;
bool comp(pair<ll,ll> a,pair<ll,ll> b) {       }
const ll MOD=1e9+7;
void print(vector<vector<ll> >&v)
{
    ll n=v.size();
    ll m=v[0].size();
    cout<<"\n";
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}
void print(vector<ll>&v)
{
    ll n=v.size();
    cout<<"\n";
    for(ll i=0;i<n;i++)
    {
            cout<<v[i]<<" ";
    }
        cout<<"\n";

}
void print(set<ll>&s)
{

cout<<endl;

set<ll>::iterator it;
for(it=s.begin();it!=s.end();it++)
    cout<<*it<<" ";
cout<<endl;
}
ll __lcm(ll a,ll b)
{
    return ((a*b)/__gcd(a,b));
}
ll power(ll a,ll p)
{
    ll res=1;
    while(p>0)
    {
        if(p&1){
            res=(res*a)%MOD;
            p--;
        }
            a=(a*a)%MOD;
            p/=2;
    }

    return res%MOD;
}
const ll INF=1e9+2;
const ll nxm=2e5+5;

ll spf[nxm];
void sieve()
{
    memset(spf,-1,sizeof(spf));

    spf[0]=spf[1]=1;

    for(ll i=2;i<nxm;i++)
    {
        if(spf[i]==-1)
            spf[i]=i;
        for(ll j=i*i;j<nxm;j+=i)
        {
            if(spf[j]==-1)
                spf[j]=i;

        }

    }
//    while(x>1)
//    {
//        ll s=spf[x];
//        temp[s]++;
//        x/=s;
//    }


// log n prime factor
}
void solve(){
ll n,k;
cin>>n>>k;
ll a[n];
ll ans=0;
REP(i,0,n) cin>>a[i];
while(ans<=n)
{
    ll cnt=1,ind=-1;
    for(ll i=1;i<n;i++)
    {
            if(a[i]!=a[i-1])
            {
                cnt++;

            }
            if(cnt>k)
            {
                ind=i;break;
            }
    }
    ans++;
    if(ind==-1)
    {
        cout<<ans<<endl;return;
    }
    for(ll j=0;j<ind;j++)
    {
        a[j]=0;
    }
}
cout<<-1<<endl;

}


int main(){
//    freopen("timber_input", "r", stdin);
//    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
	cin>>t;
    REP(i,1,t+1)
    {
//    cout<<"Case #"<<i<<": ";
		solve();
    }
	return 0;
}
