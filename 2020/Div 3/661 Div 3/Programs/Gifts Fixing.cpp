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
	cio;
	lli t,n,i,ma,mb,k,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		ma=1e18;
		mb=1e18;
		ans=0;
		lli a[n],b[n];
		for(i=0;i<n;i++){
			cin>>a[i];
			ma=min(ma,a[i]);
		}
		for(i=0;i<n;i++){
			cin>>b[i];
			mb=min(mb,b[i]);
		}
		for(i=0;i<n;i++){
			while(a[i]!=ma||b[i]!=mb){
				if(a[i]>ma&&b[i]>mb){
					k=min(a[i]-ma,b[i]-mb);
					ans+=k;
					a[i]=a[i]-k;
					b[i]=b[i]-k;
				}
				else if(a[i]>ma){
					k=a[i]-ma;
					ans+=k;
					a[i]=ma;
				}
				else if(b[i]>mb){
					k=b[i]-mb;
					ans+=k;
					b[i]=mb;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
