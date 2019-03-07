#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,at,x,y,z,ans,w[120000],head[120000],f[120000][5];
/*
f[x][0]为w点放置守卫 子树全部被看守的最优解
f[x][1]为x被他的父亲看守可以x节点上无人的最优解，在这种状态下父节点必须放看守
f[x][2] 为x的子节点放置看守 x点无人
*/
struct node {int next,to;} sxd[240000];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
void dfs(int at,int fa) {
	f[at][0]=w[at];
	int mn=0x3f3f3f3f,ok=0,sum1=0,sum2=0;
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==fa) continue;
		dfs(sxd[i].to,at);
		sum1+=min(f[sxd[i].to][0],min(f[sxd[i].to][1],f[sxd[i].to][2]));
		if(f[sxd[i].to][0]<f[sxd[i].to][2]) {
			sum2+=min(f[sxd[i].to][0],f[sxd[i].to][2]);
			ok=1;
		} else {
			sum2+=min(f[sxd[i].to][0],f[sxd[i].to][2]);
			mn=min(mn,f[sxd[i].to][0]-f[sxd[i].to][2]);
		}
	}
	f[at][0]+=sum1;
	f[at][1]=sum2;
	if(!ok) f[at][2]=mn+sum2;
	else f[at][2]=sum2;
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&at);
		scanf("%lld",&w[at]);
		scanf("%lld",&x);
		for(int j=1;j<=x;j++) {
			scanf("%lld",&y);
			add(at,y);
			add(y,at);
		}
	}
	memset(f,0x3f,sizeof f);
	dfs(1,0);
	cout<<min(f[1][0],f[1][2]);
	return 0;
}