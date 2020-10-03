#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
#define pi 3.141592653589793238
using namespace std;
int main()
{
	lli t,n,i,a,k;
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		vector<lli>v;
		for(i=0;i<n;i++){
			cin>>a;
			v.pb(a);
		}
		sort all(v);
		for(i=1;i<n;i++){
			a=v[i]-v[i-1];
			if(a<=1)
			k++;
		}
		if(k==n-1)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
