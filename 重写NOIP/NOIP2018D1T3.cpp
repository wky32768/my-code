#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=50005;
int head[N],cnt,n,m,x,y,z,mx,now;
struct node {int next,to,w;} sxd[N];
inline void add(int u,int v,int w) {sxd[++cnt]=(node) {head[u],v,w}; head[u]=cnt;}

inline int dfs1(int x,int fa) {
	int sum1=0,sum2=0;//最长与次长 
	for(register int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=fa) {
		sum2=max(sum2,dfs1(sxd[i].to,x)+sxd[i].w);
		if(sum2>sum1) swap(sum1,sum2);
	}
	mx=max(mx,sum1+sum2);//最长链长 
	return sum1;
}

multiset <int> s[N];

inline int dfs2(int x,int fa,int k) {
	s[x].clear();
	for(register int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=fa) {
		int v=dfs2(sxd[i].to,x,k)+sxd[i].w;
		if(v>=k) now++;			
		else s[x].insert(v);
	}
	int mx=0;
	while(!s[x].empty()) {
		if(s[x].size()==1) return max(mx,*s[x].begin());
		multiset <int> :: iterator it=s[x].lower_bound(k-*s[x].begin());
		if(it==s[x].begin() && s[x].count(*it)==1) it++;
		if(it==s[x].end()) {//可以不经过所有点，所以可以把较小的牺牲掉 
			mx=max(mx,*s[x].begin());
			s[x].erase(s[x].find(*s[x].begin()));
		} else {
			now++;
			s[x].erase(s[x].find(*it));
			s[x].erase(s[x].find(*s[x].begin()));	
		}
	}
	return mx;
}

inline bool ok(int x) {
	now=0;
	dfs2(1,0,x);
	return now>=m;
}

signed main() {
	freopen("track.in","r",stdin); freopen("track.out","w",stdout);
	n=read(),m=read();
	For(i,1,n-1) {
		x=read(),y=read(),z=read();
		add(x,y,z),add(y,x,z);
	}
	dfs1(1,0);
	int l=1,r=mx,ans=0;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(ok(mid)) ans=mid,l=mid+1;
		else r=mid-1;		
	}
	return cout<<ans,0;	
}
