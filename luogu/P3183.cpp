#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=200005;
int n,m,u,v,ru[N],chu[N],f[N],ans;
int cnt,head[N];
struct node {int next,to;} sxd[N];
inline void add(int u,int v) {sxd[++cnt]=(node) {head[u],v}; head[u]=cnt;}

inline int dfs(int x,int fa) {
	if(f[x]!=-1) return f[x];	
	int now=0;
	if(!chu[x] && ru[x]) now=1;
	for(register int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=fa) now+=dfs(sxd[i].to,x);
	f[x]=now;
	return now;
}

signed main() {
	n=read(),m=read();
	For(i,1,m) {
		u=read(),v=read();
		chu[u]++,ru[v]++;
		add(u,v);	
	}
	memset(f,-1,sizeof f);
	For(i,1,n) if(!ru[i]) ans+=dfs(i,0);
	return cout<<ans,0;
}

