//一条边不可能全部递增，所以边(u,v)分大小的情况排两种答案即可 
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=200005;
int n,m,x,y,ans[N];
int cnt,head[N];
bool vis1[N],vis2[N],huan;
struct node {int next,to;} sxd[N];
inline void add(int u,int v) {sxd[++cnt]=(node) {head[u],v}; head[u]=cnt;}
//vis1:整个图的搜索情况 
inline void dfs(int x) {
	vis1[x]=vis2[x]=1;
	for(register int i=head[x];i;i=sxd[i].next) {
		if(vis2[sxd[i].to]) huan=1;
		else if(!vis1[sxd[i].to]) dfs(sxd[i].to);
	}
	vis2[x]=0;
}
signed main() {
	n=read(),m=read();
	For(i,1,m) {
		x=read(),y=read();
		add(x,y);	
		ans[i]=(x<y);
	}
	For(i,1,n) if(!vis1[i]) {dfs(i); if(huan) break;}
	if(!huan) {puts("1"); For(i,1,m) {write(1);putchar(' ');} return 0;}
	puts("2"); For(i,1,m) {write(2-ans[i]);putchar(' ');}
	return 0;
}

