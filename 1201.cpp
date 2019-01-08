#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[450000],sum[450000];
struct node {
	int x,at;
	friend bool operator < (node a,node b) {
		return a.x>b.x;	
	}
};
priority_queue <node> q;
signed main() {
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;i<=m;i++) {
		q.push((node) {sum[i],i});
		ans=max(ans,sum[i]-q.top().x);
	}
	for(int i=m;i<=n;i++) {
		node w=q.top();
		while(w.at<max(0ll,i-m) && !q.empty()) {
			q.pop();
			w=q.top();
		}
		ans=max(ans,sum[i]-w.x);
		q.push((node){sum[i],i});
	}
	cout<<ans;
	return 0;
}
