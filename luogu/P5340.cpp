#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
#define to sxd[i].to
#define fi first
#define se second


const int N=100005;
int t,n,m,k,cnt,head[N],a[N],u,v,w;
struct node {int next,to,w;} sxd[N<<1];
inline void add(int u,int v,int w) {sxd[++cnt]=(node) {head[u],v,w}; head[u]=cnt;}

queue <pair <int,int> > q;
int dis[N][25];//两者之差要加上k (1)-(2)
bool vis[N][25];

inline int spfa() {
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[u][k+a[u]]=0;
	q.push(make_pair(u,k+a[u]));
	int ok=0,mn=0x3f3f3f3f;
	while(!q.empty()) {
		pair <int,int> x=q.front(); q.pop();
		vis[x.fi][x.se]=0;
		for(register int i=head[x.fi];i;i=sxd[i].next) {
			if(x.se+a[to]<0 || x.se+a[to]>k*2) continue;
			if(dis[to][x.se+a[to]]>dis[x.fi][x.se]+sxd[i].w) {
				dis[to][x.se+a[to]]=dis[x.fi][x.se]+sxd[i].w;
				if(to==v) ok=1;
				if(!vis[to][x.se+a[to]]) {
					vis[to][x.se+a[to]]=1;
					q.push(make_pair(to,x.se+a[to]));	
				}
			}
		}
	}
	if(!ok) return -1;
	For(i,0,2*k) mn=min(mn,dis[v][i]);
	return mn;
}

signed main() {
	t=read();
	while(t--) {
		cnt=0;
		memset(head,0,sizeof head);
		
		n=read(),m=read(),k=read();
		For(i,1,n) a[i]=(read()==1)?1:-1;
		For(i,1,m) {
			u=read(),v=read(),w=read();
			add(u,v,w),add(v,u,w);
		}
		u=read(),v=read();
		
		write(spfa());
		puts("");
	}
	return 0;
}

