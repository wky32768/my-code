#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,a[120000],ans,fu,zero;
signed main() {
	n=read();
	For(i,1,n) {a[i]=read();if(a[i]<0) fu++; else if(a[i]==0) zero++;}
	sort(a+1,a+n+1);
	if(fu%2==0) {
		For(i,1,n) {
			if(i<=fu) ans+=abs(-1-a[i]);	
			else ans+=abs(a[i]-1);
		}
	} else {
		if(zero>=1) {
			For(i,1,n) {
				if(i<=fu) ans+=abs(-1-a[i]);
				else ans+=abs(a[i]-1);	
			}
		} else {
			For(i,1,n) {
				if(i<fu) ans+=abs(-1-a[i]);
				else ans+=abs(a[i]-1);
			}
		}
	}
	cout<<ans;
}


