#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dep(i,a,b) for(register int i=a;i>=b;i--)
#define int long long
using namespace std;
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline void write(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

const int N=600005;
const int mod=998244353;
int n,m,head[N],cnt,u,v,w,dep[N],tot[N][55],fa[N][22];
struct node {
	int next,to;
} sxd[N];
inline void add(int u,int v) {
	sxd[++cnt]=(node) {
		head[u],v
	};
	head[u]=cnt;
}

inline int ksm(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

inline void dfs(int x,int f) {
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	For(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
	For(i,1,50) tot[x][i]=(tot[f][i]+ksm(dep[x],i))%mod;
	for(register int i=head[x]; i; i=sxd[i].next) if(sxd[i].to!=f) dfs(sxd[i].to,x);
}

inline int lca(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	Dep(i,20,0) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	Dep(i,20,0) if(fa[x][i]!=fa[y][i] && fa[x][i] && fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

signed main() {
	n=read();
	For(i,1,n-1) {
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	dep[0]=-1;
	dfs(1,0);
	m=read();
	while(m--) {
		u=read(),v=read(),w=read();
		int ll=lca(u,v),now=tot[u][w];
		now=(now+tot[v][w])%mod;
		now=(now-tot[ll][w]+mod)%mod;
		now=(now-tot[fa[ll][0]][w]+mod)%mod;
		write(now);
		puts("");
	}
	return 0;
}

