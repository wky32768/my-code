//可以一次次地在图里扫描联通块，每一次联通块的第一次有两个被用掉，其他的都是一个 
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=200005;
int cnt,head[N],n,k,x,y,ans,kuai;
struct node {int next,to;} sxd[N];
inline void add(int u,int v) {sxd[++cnt]=(node) {head[u],v};head[u]=cnt;}
bool vis[N];
inline void dfs(int x) {
	vis[x]=1;
	for(register int i=head[x];i;i=sxd[i].next) if(!vis[sxd[i].to]) dfs(sxd[i].to);	
}
signed main() {
	n=read(),k=read();
	For(i,1,k) {
		x=read(),y=read();
		add(x,y); add(y,x);	
	}
	For(i,1,n) if(!vis[i]) dfs(i),kuai++;
	cout<<k-n+kuai;
	return 0;
}

