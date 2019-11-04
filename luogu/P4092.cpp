#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dep(i,a,b) for(register int i=a;i>=b;i--)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}

const int N=200005;
int n,q,cnt,head[N],u,v,a[N],f[N],ans[N],fa[N];
struct node {int next,to;} sxd[N];
struct ASK {char opt;int c;} ask[N];

inline void add(int u,int v) {sxd[++cnt]=(node) {head[u],v};head[u]=cnt;}
inline void dfs(int x) {
	for(register int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=fa[x]) {
		fa[sxd[i].to]=x;
		dfs(sxd[i].to);
	}
}

inline int find(int x) {if(f[x]==x) return x; return f[x]=find(f[x]);}

signed main() {
	n=read(),q=read();
	For(i,1,n-1) {
		u=read(),v=read();
		add(u,v);
	}
	dfs(1);
	a[1]=1;
	For(i,1,q) {
		cin>>ask[i].opt; ask[i].c=read();
		if(ask[i].opt=='C') a[ask[i].c]++;
	}
	
	f[1]=1;
	For(i,2,n) f[i]=(a[i]>=1?i:fa[i]);
	Dep(i,q,1) {
		if(ask[i].opt=='C') {
			a[ask[i].c]--;	
			if(!a[ask[i].c]) f[ask[i].c]=fa[ask[i].c];
		} else ans[i]=find(ask[i].c);
	}
	
	For(i,1,q) if(ask[i].opt=='Q') {write(ans[i]); puts("");}
	return 0;
}

