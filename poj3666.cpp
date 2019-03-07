/*

对于前i个数，我们需要关心的有两个值
1.把它变成单调序列需要的土，越少越好
2.第i个数的大小，越小越好
于是dp[i][j]表示考虑前i个数，第i个数
是j时，至少需要的土
第i个数是j时最少需要的土，就等于j和
a[i]差的绝对值+ 第i-1个数小于等于j时
至少需要土的最小值
即转移方程为：
dp[i][j]=abs(j-a[i])+min(dp[i-1][k])
k <= j
到这里问题就基本解决了。但是因为a[i]
的范围太大了，这样枚举k时就会TLE。这
里需要离散化优化
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2100;
int n,ans=0x3f3f3f3f,f[N][N],a[N],b[N];
signed main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) {
		int mn=f[i-1][1];
		for(int j=1;j<=n;j++) {
			mn=min(mn,f[i-1][j]);
			f[i][j]=abs(a[i]-b[j])+mn;
		}
	}
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	cout<<ans;
	return 0;
}