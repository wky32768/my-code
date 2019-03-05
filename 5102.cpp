#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(register int i=a;i<=b;i++)
int n,q,ans=0x3f3f3f3f,dis[230][230],ask[1200],f[1005][205][205];
signed main() {
	scanf("%d%d",&n,&q);
	For(i,1,n) For(j,1,n) scanf("%d",&dis[i][j]);
	For(i,1,q) scanf("%d",&ask[i]);
	ask[0]=3;
	memset(f,0x3f,sizeof f);
	f[0][1][2]=0;
	For(i,1,q) For(x,1,n) For(y,1,n) if(f[i-1][x][y]!=0x3f3f3f3f){
		int z=ask[i-1];
		if(y!=ask[i] && z!=ask[i]) f[i][y][z]=min(f[i][y][z],f[i-1][x][y]+dis[x][ask[i]]);
		if(x!=ask[i] && z!=ask[i]) f[i][x][z]=min(f[i][x][z],f[i-1][x][y]+dis[y][ask[i]]);
		if(x!=ask[i] && y!=ask[i]) f[i][x][y]=min(f[i][x][y],f[i-1][x][y]+dis[z][ask[i]]);
	}
	For(i,1,n) For(j,1,n) ans=min(ans,f[q][i][j]);
	printf("%d\n",ans);
	return 0;
}
/*
通过从i个到i-1的过度可以优化内存和时间
注意题目里提到的特殊条件
可以通过竖列比较发现自己有没有打错
*/