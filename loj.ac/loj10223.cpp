#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mod;
struct matrix {
	int w[2][2];
} a={1,1,1,0},t={1,0,0,1};
matrix cheng(matrix a,matrix b) {
	matrix ans;
	memset(ans.w,0,sizeof ans.w);
	for(int i=0; i<=1; i++)
		for(int j=0;j<=1; j++)
			for(int k=0; k<=1; k++)
				ans.w[i][j]=(ans.w[i][j]+a.w[i][k]*b.w[k][j]%mod)%mod;
	return ans;
}
matrix ksm(matrix a,int b) {
	matrix sum=t;
	while(b) {
		if(b&1) sum=cheng(sum,a);
		a=cheng(a,a);
		b>>=1;
	}
	return sum;
}
signed main() {
	mod=10000;
	while(cin>>n && n!=-1) {
		if(!n) {
			puts("0");
			continue;	
		}
		matrix ans=ksm(a,n-1);
		cout<<ans.w[0][0]%mod<<'\n';
	}
	return 0;
}
