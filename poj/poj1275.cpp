#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120000;
int t,n,head[N],cnt,need[30],em[30],x,dis[N],times[N];
struct node {
	int next,to,w;
} sxd[N<<1];
void add(int u,int v,int w) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	sxd[cnt].w=w;
	head[u]=cnt;
}
bool vis[N];
queue <int> q;
bool spfa(int x) {
	memset(times,0,sizeof times);
	while(!q.empty()) q.pop();
	memset(dis,-0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push(0);
	vis[0]=1;
	dis[0]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=head[now]; i; i=sxd[i].next) {
			int to=sxd[i].to;
			if(dis[to]<dis[now]+sxd[i].w) {
				dis[to]=dis[now]+sxd[i].w;
				if(!vis[to]) {
					q.push(to);
					vis[to]=1;
					times[to]++;
					if(times[to]>24) return 0;//�ж������� Ҫ����Ӵ���
				}
			}
		}
		vis[now]=0;
	}
	return (dis[24]==x);
}
signed main() {
	cin>>t;
	while(t--) {
		memset(em,0,sizeof em);
		For(i,1,24) cin>>need[i];
		cin>>n;
		For(i,1,n) {
			cin>>x;
			em[x+1]++;
		}
		int l=0,r=n,ans=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			memset(head,0,sizeof head);
			cnt=0;
			add(0,24,mid);
			For(i,1,24) {
				add(i-1,i,0);//a[i]-a[i-1]>=0(招到�?
				add(i,i-1,-em[i]);//a[i]-a[i-1]<=em[x](招的人数有上�?
				//最小值就是最长路。。这个可以自己推，所以负环没有什�?�?
			}
//			cout<<"mid="<<mid<<'\n';
			For(i,1,8) add(i+16,i,need[i]-mid);
			For(i,9,24) add(i-8,i,need[i]);//a[i]-a[i-8]>=need[x](人数要达�?
			//a[i]-a[i+16]>=need-mid
			//推一�?
			//mid+a[i]-s[i+16]>=need
			if(spfa(mid)) {
				ans=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(ans==-1) puts("No Solution");
		else cout<<ans<<'\n';
	}
	return 0;
}
