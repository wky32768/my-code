/*
s[i]:f[1]+f[2]...+f[n];
p[i]=(i-1)*f[1]+(i-2)*f[2]..+f[n];
p[i+1]=p[i]+s[i]
ans=n*s[n]-p[n]

p[i]
s[i]
f[i]
f[i-1]
1 1 0 0
0 1 1 0
0 0 1 1
0 0 1 0
p[i+1]
s[i+1]
f[i+1]
f[i]
推演较难手推
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mod;
struct matrix {
	int w[120][120];
} a,b,c,ans;
matrix cheng(matrix a,matrix b) {
	matrix ans;
	memset(ans.w,0,sizeof ans.w);
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			for(int k=1; k<=4; k++) {
				ans.w[i][j]=(ans.w[i][j]+a.w[i][k]*b.w[k][j]%mod)%mod;
			}
	return ans;
}
matrix ksm(matrix a,int b) {
	matrix ans;
	for(int i=0; i<=4; i++) ans.w[i][i]=1;
	while(b) {
		if(b&1) ans=cheng(ans,a);
		a=cheng(a,a);
		b>>=1;
	}
	return ans;
}
signed main() {
	scanf("%lld%lld",&n,&mod);
	a.w[1][1]=a.w[1][2]=a.w[2][2]=a.w[2][3]=a.w[3][3]=a.w[3][4]=a.w[4][3]=1;
	b.w[2][1]=b.w[3][1]=b.w[4][1]=1;
	a=ksm(a,n-1);
	ans=cheng(a,b);
	printf("%lld",(n*ans.w[2][1]-ans.w[1][1]+mod)%mod);
	return 0;
}