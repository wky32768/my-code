#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=100005;
int n,k,a[N],ans;
signed main() {
	n=read(),k=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int l=1,r=n;
	For(i,1,k) {
		if(r-l+1==k-i+1) return cout<<ans,0;
		ans+=a[r]-a[l];
		l++,r--;
	}
	cout<<ans;
}

