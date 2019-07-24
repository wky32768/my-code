#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,k,ans=-0x3f3f3f3f,w[120][120],f[120][12][5];
signed main() {
	cin>>n>>m>>k;
	For(i,1,n) For(j,1,m) cin>>w[i][j];
	memset(f,-0x3f3f3f3f,sizeof f);//注意判断负数的情况
	For(i,0,n) For(j,0,k) f[i][j][0]=0;//不要忘记判0
	if(m==1) {
		For(i,1,n) For(j,1,k) {
			f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j][1])+w[i][1];			
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
		}
		cout<<max(f[n][k][0],f[n][k][1]);
	}
	if(m==2) {
		For(i,1,n) For(j,1,k) {
			f[i][j][0]=max(max(max(max(f[i-1][j][0],f[i-1][j][1]),f[i-1][j][2]),f[i-1][j][3]),f[i-1][j][4]);//两个都不选
			f[i][j][1]=max(max(max(max(f[i-1][j-1][0],f[i-1][j][1]),f[i-1][j-1][2]),f[i-1][j][3]),f[i-1][j-1][4])+w[i][1];//选左
			f[i][j][2]=max(max(max(max(f[i-1][j-1][0],f[i-1][j-1][1]),f[i-1][j][2]),f[i-1][j][3]),f[i-1][j-1][4])+w[i][2];//选右
			f[i][j][3]=max(max(f[i-1][j-1][1],f[i-1][j-1][2]),f[i-1][j][3])+w[i][1]+w[i][2];//左右单独都选
			if(j>=2) f[i][j][3]=max(f[i][j][3],max(f[i-1][j-2][4],f[i-1][j-2][0])+w[i][1]+w[i][2]);
			f[i][j][4]=max(max(max(max(f[i-1][j-1][0],f[i-1][j-1][1]),f[i-1][j-1][2]),f[i-1][j-1][3]),f[i-1][j][4])+w[i][1]+w[i][2];//左右何在一起选
		}
		cout<<max(max(max(max(f[n][k][0],f[n][k][1]),f[n][k][2]),f[n][k][3]),f[n][k][4]);
	}
	return 0;
}
