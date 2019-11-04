//预处理，对于每个元素求与它相等的元素中最右的一个，则它们俩一定是一个 block的
//划分出所有的 block 后，每个 block 找众数
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=200005;
int n,q,a[N],last[N],tot[N],f[N],ans;//f:一段中的最后一位 
signed main() {
	n=read(),q=read();
	ans=n;
	For(i,1,n) {
		a[i]=read();
		tot[a[i]]++;
		last[a[i]]=i;
	}
	For(i,1,n) f[i]=max(last[a[i]],f[i-1]);//第一种：他这个数的最后一位。第二种：前面寄托了后面的一位要跟他一样
	int l=1;
	For(i,1,n) if(f[i]==i) {
		int mx=0;
		For(j,l,i) mx=max(mx,tot[a[j]]);	
		ans-=mx;//少换掉了这么多（不用动） 
		l=i+1;
	}
	cout<<ans;
	return 0;
}

