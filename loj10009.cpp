#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
priority_queue <int> q;
int n,ans,t,fish[1200],les[1200],tim[1200];
signed main() {
	cin>>n>>t;
	For(i,1,n) cin>>fish[i];
	For(i,1,n) cin>>les[i];
	For(i,2,n) {
		cin>>tim[i];
		tim[i]+=tim[i-1];
	}
	For(last,1,n) {
		while(!q.empty()) q.pop();
		int w=t*12-tim[last],now=0;
		For(j,1,last) For(i,1,(les[j]==0?1200:fish[j]/les[j]+1)) if(fish[j]-(i-1)*les[j]>0) q.push(fish[j]-(i-1)*les[j]);
		For(i,1,w) if(!q.empty()) {
			now+=q.top();
			q.pop();
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
