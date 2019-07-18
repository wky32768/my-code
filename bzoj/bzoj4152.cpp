#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=200005;
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();	
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;	
}
struct node {
	int next,to,w;
} sxd[N<<2];
struct dian {
	int x,y,id;	
} pfy[N];
int n,head[N<<1],cnt;
inline void add(int u,int v,int w) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	sxd[cnt].w=w;
	head[u]=cnt;
}
inline bool cmp1(dian a,dian b) {
	return a.x<b.x;	
}
inline bool cmp2(dian a,dian b) {
	return a.y<b.y;	
}
struct xkx {
	int id,w;
	friend bool operator < (xkx a,xkx b) {
		return a.w>b.w;
	}
};
priority_queue <xkx> q;
int dis[N];
void dij() {
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push((xkx){1,0});
	while(!q.empty()) {
		xkx now=q.top();
		q.pop();
		dis[now.id]=min(dis[now.id],now.w);
		for(int i=head[now.id];i;i=sxd[i].next) {
			if(dis[sxd[i].to]>dis[now.id]+sxd[i].w) {
				dis[sxd[i].to]=dis[now.id]+sxd[i].w;	
				q.push((xkx) {sxd[i].to,dis[sxd[i].to]});
			}
		}
	}
	cout<<dis[n];	
}
signed main() {
	cin>>n;
	For(i,1,n) {
		pfy[i].x=read(),pfy[i].y=read();
		pfy[i].id=i;	
	}
	sort(pfy+1,pfy+n+1,cmp1);
	For(i,1,n-1) {
		add(pfy[i].id,pfy[i+1].id,pfy[i+1].x-pfy[i].x);
		add(pfy[i+1].id,pfy[i].id,pfy[i+1].x-pfy[i].x);	
	}
	sort(pfy+1,pfy+n+1,cmp2);
	For(i,1,n-1) {
		add(pfy[i].id,pfy[i+1].id,pfy[i+1].y-pfy[i].y);
		add(pfy[i+1].id,pfy[i].id,pfy[i+1].y-pfy[i].y);	
	}
	dij();
}
