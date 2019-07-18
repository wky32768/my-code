#include <bits/stdc++.h>
using namespace std;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=2000005;
int head[N<<1],n,m,r,cnt,a,b,c,dis[N];
struct node {
	int next,to,w;
} sxd[N<<1];
void add(int u,int v,int w) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	sxd[cnt].w=w;
	head[u]=cnt;
}
queue <int> q;
bool vis[N];
void spfa() {
	q.push(0);
	memset(dis,-0x3f,sizeof dis);
	dis[0]=0;
	vis[0]=1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(register int i=head[x];i;i=sxd[i].next) {
			int y=sxd[i].to;
			if(dis[y]<dis[x]+sxd[i].w) {
				dis[y]=dis[x]+sxd[i].w;
				if(!vis[y]) {
					q.push(y);
					vis[y]=1;
				}
			}
		}
		vis[x]=0;
	}	
}
signed main() {
	cin>>n>>m>>r;
	while(m--) {
		a=read(),b=read(),c=read();
		add(a,b+r,c);
	}
	for(register int i=0;i<=n+r;i++) add(i,i+1,0);
	spfa();
	cout<<dis[n+r];
	return 0;
}