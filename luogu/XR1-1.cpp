#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=105;
const int mod=1e9+7;
const int m=100;
int n,a[N],b[N],cnt1,cnt2;
struct mat {int w[N][N];} temp,f;

mat cheng(mat a,mat b) {
	mat ans;
	memset(ans.w,0,sizeof ans.w);
	For(i,1,m) For(j,1,m) For(k,1,m) ans.w[i][j]=(ans.w[i][j]+a.w[i][k]*b.w[k][j]%mod)%mod;
	return ans;
}
mat ksm(int b) {
	while(b) {
		if(b&1) f=cheng(f,temp);
		temp=cheng(temp,temp);
		b>>=1;
	}
	return f;
}

signed main() {
	n=read();
	cnt1=read();
	For(i,1,cnt1) a[read()]|=1;
	cnt2=read();
	For(i,1,cnt2) b[read()]|=1;
	For(i,1,100) a[i]=(a[i] && b[i]);
	
	f.w[1][m]=1;
	For(i,2,m+1) temp.w[i][i-1]=1;
	For(i,1,m) if(a[i]) temp.w[m-i+1][m]=1;
	
	return cout<<ksm(n).w[1][m],0;
}
