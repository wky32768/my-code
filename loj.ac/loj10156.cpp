#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=120000;
int n,cnt,at,x,y,z,f[N][2],head[N];//[0]:自己不选；【1]:自己选
struct node {int next,to;} sxd[N<<1];
void add(int a,int b) {
	sxd[++cnt].next=head[a];
	sxd[cnt].to=b;
	head[a]=cnt;
}
void dfs(int at,int fa) {
	f[at][1]=1,f[at][0]=0;
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==fa) continue;
		dfs(sxd[i].to,at);
		f[at][1]+=min(f[sxd[i].to][0],f[sxd[i].to][1]);
		f[at][0]+=f[sxd[i].to][1];
	}
}
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&at,&x);
		at++;
		for(int j=1;j<=x;j++) {
			scanf("%lld",&y);
			y++;
			add(at,y);
			add(y,at);
		}
	}
	memset(f,0x3f,sizeof f);
	dfs(1,0);
	cout<<min(f[1][0],f[1][1]);
}