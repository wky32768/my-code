//题意可以化为把石头重新标号，找到逆序对的最小值 
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
int n,a[400005],pre[23][23],tot[23],f[2000005];//pre两个数产生的逆序对数量 
signed main() {
	n=read();
	For(i,1,n) {
		a[i]=read()-1;
		For(j,0,19) pre[a[i]][j]+=tot[j];
		tot[a[i]]++;
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	For(i,0,(1<<20)-1) For(j,0,19) if((i&(1<<j))==0) {//这一位是空的
		int now=f[i];
		For(k,0,19) if((i&(1<<k))>=1) now+=pre[j][k];
		f[i|(1<<j)]=min(f[i|(1<<j)],now);	
	}
	return cout<<f[(1<<20)-1],0;
}

