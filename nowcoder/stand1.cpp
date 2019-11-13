#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
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

const int N=20005;
int n,m,x,y,head[N],cnt;
bool flag,vis[N];
struct node {int next,to;} sxd[N];
inline void add(int u,int v) {
	sxd[++cnt]=(node) {head[u],v};
	head[u]=cnt;	
}

inline void dfs(int x,int f) {
	if(x==n) {flag=1;return;}
	vis[x]=1;
	for(register int i=head[x];i;i=sxd[i].next) {
		if(sxd[i].to!=f && !vis[sxd[i].to]) dfs(sxd[i].to,x);	
	}
}

signed main() {
	while(cin>>n>>m) {
		cnt=0;
		memset(head,0,sizeof head);		
		For(i,1,m) {
			x=read(),y=read();
			add(x,y);
		}
		flag=0;
		dfs(1,0);
		if(flag) puts("Yes");
		else puts("No");
	}
}

