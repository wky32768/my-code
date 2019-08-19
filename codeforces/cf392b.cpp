#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int dis[5][5],n,f[5][5][50],w[5][5];
int dfs(int at,int to,int sum) {
	if(f[at][to][sum]) return f[at][to][sum];
	if(sum==1) {
		f[at][to][sum]=dis[at][to];
		return dis[at][to];
	}
	int other=6-at-to;
	int ans=dfs(at,other,sum-1)+w[at][to]+dfs(other,to,sum-1);
	ans=min(ans,dfs(at,to,sum-1)+w[at][other]+dfs(to,at,sum-1)+w[other][to]+dfs(at,to,sum-1));
	f[at][to][sum]=ans;
	return ans;
}
signed main() {
	For(i,1,3) For(j,1,3) {cin>>w[i][j];dis[i][j]=w[i][j];}//不可混用，有时最短路无法取到 
	For(k,1,3) For(i,1,3) For(j,1,3) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//又错一次，不是双向边不能定下顺序。这种错误一定不能犯，比赛的时候就是100分啊 
	cin>>n;
	cout<<dfs(1,3,n);
	return 0;
}
