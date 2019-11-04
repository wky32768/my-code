#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int a1,a2,k1,k2,n;
signed main() {
	cin>>a1>>a2>>k1>>k2>>n;
	int ans1=0;
	if(n<=(k1-1)*a1+(k2-1)*a2) ans1=0;
	else ans1=min(a1+a2,(n-(k1-1)*a1-(k2-1)*a2));
	int ans2=0;
	if(k1<k2) {
		ans2+=min(a1,n/k1);
		n-=min(a1,n/k1)*k1;
		ans2+=min(a2,n/k2);
	} else {
		ans2+=min(a2,n/k2);
		n-=min(a2,n/k2)*k2;
		ans2+=min(a1,n/k1);	
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
 
