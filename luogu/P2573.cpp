#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=1200000;
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) {
		f|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f?-x:x;
}
int head1[N<<1];
struct node {
	int next,to,w;
} sxd1[N<<1];
int h[N],u,v,k,cnt1,cnt2,tot,n,m;
void add1(int u,int v,int k) {
	sxd1[++cnt1].next=head1[u];
	sxd1[cnt1].to=v;
	sxd1[cnt1].w=k;
	head1[u]=cnt1;
}
queue <int> q;
bool vis[N];
struct bian {
	int x,y,w;
	friend bool operator < (bian a,bian b) {
		if(h[a.y]!=h[b.y]) return h[a.y]>h[b.y];
		else return a.w<b.w;
	}
} b[N<<1];
int zong,fa[N];
int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void bfs() {
	q.push(1);
	tot++;
	vis[1]=1;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int i=head1[x]; i; i=sxd1[i].next) {
			int y=sxd1[i].to;
			b[++zong]=(bian) {
				x,y,sxd1[i].w
			};
			if(!vis[y]) {
				vis[y]=1;
				tot++;
				q.push(y);
			}
		}
	}
}
void kruskal() {
	sort(b+1,b+zong+1);
	int ans=0;
	for(int i=1; i<zong; i++) {
		int x=find(b[i].x),y=find(b[i].y);
		if(x!=y) {
			ans+=b[i].w;
			fa[x]=y;
		}
	}
	cout<<tot<<" "<<ans<<'\n';
}
signed main() {
	cin>>n>>m;
	For(i,1,n) {
		h[i]=read();
		fa[i]=i;
	}
	while(m--) {
		u=read(),v=read(),k=read();
		if(h[u]>=h[v]) add1(u,v,k);
		if(h[u]<=h[v]) add1(v,u,k);
	}
	bfs();
	kruskal();
	return 0;
}
