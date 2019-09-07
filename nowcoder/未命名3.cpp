#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=1005;
int n,k,a[N],l=0,r=1e9,ans=0;
bool sxd[N];
inline bool ok(int x) {
	memset(sxd,0,sizeof sxd);	
	For(i,1,n-1) if(a[i+1]-a[i]<=x) sxd[i]=1;
	int now=1,tot=0;
	while(now<n) {
		if(sxd[now]==1) {
			tot++;
			now+=2;	
		} else now++;
	}
	return tot>=k;
}
signed main() {
	n=read();
	For(i,1,n) a[i]=read();
	k=read();
	sort(a+1,a+n+1);
	while(l<=r) {
		int mid=(l+r)>>1;
		if(ok(mid)) {
			ans=mid;
			r=mid-1;	
		} else l=mid+1;
	}
	cout<<ans;
	return 0;
}

