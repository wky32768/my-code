//先建树，然后尽量按照相反进行搜索（因为这样异或以后就是1了）
//x到y的异或就相当于d[x]^d[y](LCA以上的算了两次等于没算)然后求解即可。
#include <bits/stdc++.h>
#define int long long
using namespace std;
int trie[5200000][5],x,y,z,head[120000];
int n,ans,cnt=0;
void insert(int x) {
	int p=0;
	for(int k=30;k>=0;k--) {
		int now=(x>>k)&1;
		if(trie[p][now]==0) trie[p][now]=++cnt;
		p=trie[p][now];
	}
}
int solve(int x) {
	int p=0,ans=0;
	for(int k=30;k>=0;k--) {
		int now=(x>>k)&1;
		if(trie[p][now^1]) {
			p=trie[p][now^1];
			ans|=1<<k;
		} else p=trie[p][now];
	}
	return ans;
}
struct node {int next,to,w;} sxd[1200000];
void add(int u,int v,int w) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	sxd[cnt].w=w;
	head[u]=cnt;
}
void dfs(int at,int f,int zhi) {
	insert(zhi);
	ans=max(ans,solve(zhi));
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==f) continue;
		dfs(sxd[i].to,at,zhi^(sxd[i].w));
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}