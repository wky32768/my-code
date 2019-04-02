#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=60;
//https://cdn.luogu.org/upload/pic/30960.png
/*i,j是红色路径的坐标，k,l是黑色路径的坐标
那么对于k，我们只需枚举[i+1, m][i+1,m],l只需枚举[1,j-1][1,j−1]即可
这样就不用判重啦

由于最后dp不到终点，但其实黑色路径走到终点上方的点，红色路径走到终点左边的点就是答案,即f[m-1][n][m][n-1]*/
int f[N][N][N][N],n,m,dis[N][N];
int get() {
	for(int a=1;a<=n;a++) for(int b=1;b<=m;b++) for(int c=1;c<=a-1;c++) for(int d=b+1;d<=m;d++) {
		if((a<m && b<n) && a==c && b==d) continue;
		f[a][b][c][d]=max(max(f[a-1][b][c-1][d],f[a-1][b][c][d-1]),max(f[a][b-1][c-1][d],f[a][b-1][c][d-1]))+dis[a][b]+dis[c][d];
	}
	return f[n][m-1][n-1][m];
}
signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&dis[i][j]);
	cout<<get();
}