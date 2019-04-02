//https://www.cnblogs.com/Le-mon/p/9641230.html 方程推导
//高斯消元就是用计算机进行人为的行列式化简求值
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=120;
int n;
double a[N][N],b[N],c[N][N];
signed main() {
	scanf("%lld",&n);
	For(i,1,n+1) For(j,1,n) scanf("%lf",&a[i][j]);
	For(i,1,n) For(j,1,n) {
		c[i][j]=2ll*(a[i][j]-a[i+1][j]);
		b[i]+=a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j];
	}
	For(i,1,n) {
		For(j,i,n) {
			if(fabs(c[j][i])>1e-8) {
				For(k,1,n) swap(c[i][k],c[j][k]);
				swap(b[i],b[j]);
			}
		}//把当前这位非零的式子放到第i个
		For(j,1,n) {
			if(i==j) continue;
			double xishu=c[j][i]/c[i][i];
			For(k,1,n) c[j][k]-=c[i][k]*xishu;
			b[j]-=b[i]*xishu;
		} 
	}
	For(i,1,n) printf("%.3lf ",b[i]/c[i][i]);
	return 0;
}
