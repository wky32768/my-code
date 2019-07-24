#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sxd,a[55],b[55];
double p[55];
double f[55][12000];
bool ok(double x) {
	//观察性质，要么是赋值，要么是在前一位算过的里面找。因为每一位都进过计算，所以不用赋初值(double赋初值不是0的话就会非常的奇怪) 
	for(int i=n-1;i>=0;i--) {
        for(int j=sxd+1;j<=10000;j++) f[i+1][j]=x;//重玩了，没有进阶到i(不然在i-1就要调用到了，会导致答案错误) 
        for(int j=0;j<=sxd;j++) 
			f[i][j]=min(x,(f[i+1][j+a[i]]+a[i])*p[i]/100.0+(f[i+1][j+b[i]]+b[i])*(100.0-p[i])/100.0);
	}
    return (f[0][0]<x);
}
signed main() {
    cin>>n>>sxd;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>p[i];//因为是倒推，所以算转移i时用的是i-1 
    double l=0,r=1e18;
    for(int i=1;i<=150;i++) {
        double mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid;
    }
    printf("%.10f",l);
    return 0;
}
