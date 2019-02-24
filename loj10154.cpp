#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=520000;
struct node {int next,to;} sxd[N];
int head[N],f[1200][1200],w[1200];
//f[i][j]指根为i,在里面取了j个的最大学分值
int n,m,x,cnt;
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
void dfs(int at,int ff) {
	for(int i=head[at];i;i=sxd[i].next) {
		if(sxd[i].to==ff) continue;
		dfs(sxd[i].to,at);
		for(int j=m;j>=0;j--) for(int k=0;k<=j;k++)
			f[at][j]=max(f[at][j],f[at][j-k]+f[sxd[i].to][k]);
	}
	if(at)for(int i=m;i>=1;i--) f[at][i]=f[at][i-1]+w[at];
	/*
	关于if(at)
	①在其他情况下，根节点是必选的，从m到1算可以避免w[at]的多次累加
	Q：w[0]不是等于0吗，有什么关系？
	A：在为0的情况下，f[at][i]不一定等于f[at][i-1],因为他可以进行自主选择
	*/
}
signed main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&x,&w[i]);
		add(i,x);
		add(x,i);
	}
	dfs(0,-1);
	return printf("%lld",f[0][m]),0;
}