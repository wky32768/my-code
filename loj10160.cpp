#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120000;
int n,w[N],head[N],cnt,x,y,f[N][2],ans;
struct node {int next,to;} sxd[N<<1];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
void dfs(int at,int fa) {
	f[at][1]=w[at];
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==fa) continue;
		dfs(sxd[i].to,at);
		f[at][1]+=f[sxd[i].to][0];
		f[at][0]+=max(f[sxd[i].to][0],f[sxd[i].to][1]);
	}
}
signed main() {
	scanf("%lld",&n);
	For(i,1,n) scanf("%lld",&w[i]);
	For(i,2,n+1) {
		scanf("%lld%lld",&x,&y);
		if(x) add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1]);
	return 0;
}