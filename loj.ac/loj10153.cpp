#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120;
int n,m,cnt,x,y,z;
int head[N],apple[N],f[N][N];
struct node {int next,to,w;} sxd[N<<1];
void add(int u,int v,int w) {
	sxd[++cnt]=(node){head[u],v,w};
	head[u]=cnt;
}
void dfs(int at,int ff,int app) {
	vector <int> son;
	bool flag=0;
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==ff) continue;
		flag=true;
		son.push_back(i);
		dfs(sxd[i].to,at,sxd[i].w);
	}
	if(!flag) return;
	For(i,1,m) For(j,0,i) {
		int now=0;
		if(j>=1) now+=sxd[son[0]].w;
		if(i-j-1>=0) now+=sxd[son[1]].w;
		if(j) f[at][i]=max(f[at][i],f[sxd[son[0]].to][j-1]+f[sxd[son[1]].to][i-j-1]+now);
		else f[at][i]=max(f[at][i],f[sxd[son[1]].to][i-j-1]+now);
	}
}
signed main() {
	cin>>n>>m;
	For(i,1,n-1) {
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	cout<<f[1][m];
	return 0;
}