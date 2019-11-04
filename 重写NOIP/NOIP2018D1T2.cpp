#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int t,a[105],f[30005],n,ans;
signed main() {
	t=read();
	while(t--) {
		n=read();
		For(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		memset(f,0,sizeof f);
		f[0]=1;
		ans=0;
		For(i,1,n) {
			if(!f[a[i]]) ans++;	
			for(register int j=a[i];j<=a[n];j++) f[j]|=f[j-a[i]];
		}
		write(ans);
		puts("");
	}
	return 0;
}

