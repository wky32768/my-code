#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,a[120000],head[120000],length[120000],mx,ans,mxat,vis[120000];
struct node {int next,to;} sxd[240000];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
void build() {
	for(int i=1;i<=n;i++) {
		if(a[i]<i) {
			add(a[i],i);
			add(i,a[i]);
		}
		for(int j=i*2;j<=n;j+=i) a[j]+=i;
	}
}
void dfs(int at,int f) {
	length[at]=length[f]+1;
	if(length[at]>mx) mx=length[at],mxat=at;
	vis[at]=1;
	for(int i=head[at];i;i=sxd[i].next) {
		if(!vis[sxd[i].to]) dfs(sxd[i].to,at);
	}
}
signed main() {
	scanf("%lld",&n);
	build();
	dfs(1,0);
	mx=0;
	memset(vis,0,sizeof vis);
	memset(length,0,sizeof length);
	dfs(mxat,0);
	return printf("%lld",mx-1),0;
}