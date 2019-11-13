#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=200005;
int t,n,m,k,p,cnt,cnt2,head[N],head2[N],u,v,w,ans,f[N][51],dis[N];
bool vis[N];
struct node {int next,to,w;} sxd[N],xkx[N];
inline void add(int u,int v,int w) {sxd[++cnt]=(node) {head[u],v,w}; head[u]=cnt;}
inline void add2(int u,int v,int w) {xkx[++cnt2]=(node) {head2[u],v,w}; head2[u]=cnt2;}

inline void spfa() {
	queue <int> q;
	dis[1]=0;
	q.push(1);
	memset(vis,0,sizeof vis);
	while(!q.empty()) {
		int x=q.front(); q.pop();
		vis[x]=0;
		for(register int i=head[x];i;i=sxd[i].next) {
			if(dis[sxd[i].to]>dis[x]+sxd[i].w) {
				dis[sxd[i].to]=dis[x]+sxd[i].w;
				if(!vis[sxd[i].to]) {q.push(sxd[i].to); vis[sxd[i].to]=1;}
			}
		}
	}
}

bool used[N][51];

inline int dp(int at,int rest) {
	if(rest<0 || rest>k) return 0;
	if(used[at][rest]) {
		used[at][rest]=0;
		return -1;	
	}
	if(f[at][rest]!=-1) return f[at][rest];
	used[at][rest]=1;
	int tot=0;
	for(register int i=head2[at];i;i=xkx[i].next) {
		int val=dp(xkx[i].to,rest+dis[at]-dis[xkx[i].to]-xkx[i].w);
		if(val==-1) {
			used[at][rest]=0;
			return -1;
		}
		tot=(tot+val)%p;
	}
	used[at][rest]=0;
	if(at==1 && rest==0) tot++;
	f[at][rest]=tot;
	return tot;
}

signed main() {
	t=read();
	while(t--) {
		cnt=cnt2=0;
		memset(head,0,sizeof head);
		memset(head2,0,sizeof head2);
		n=read(),m=read(),k=read(),p=read();
		For(i,1,m) {
			u=read(),v=read(),w=read();
			add(u,v,w),add2(v,u,w);
		}
		memset(dis,0x3f3f3f3f,sizeof dis);
		spfa();
		ans=0;
		memset(f,-1,sizeof f);
		For(i,0,k) {
			int now=dp(n,i);
			if(now==-1) {puts("-1"); goto L1;}
			ans=(ans+now)%p;
		}
		cout<<ans<<'\n';
		L1:;
	}
}

