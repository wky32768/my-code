#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
int n,a[100005],ans;
signed main() {
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	cout<<ans;
	return 0;
}

