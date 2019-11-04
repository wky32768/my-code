#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
//只使用一个欧元或一个美元 
int n,d,e,ans=0x3f3f3f3f;
signed main() {
	n=read(),d=read(),e=read();
	e*=5;
	for(int i=0;i*e<=n;i++) ans=min(ans,(n-i*e)%d);
	cout<<ans;
	return 0;
}

