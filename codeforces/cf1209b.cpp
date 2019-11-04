#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=1005;
char ch[N];
int n,now[N],a[N],b[N],ans;
signed main() {
	n=read();
	scanf("%s",ch+1);
	For(i,1,n) now[i]=(ch[i]=='1');
	For(i,1,n) a[i]=read(),b[i]=read();	
	For(i,1,n) if(now[i]==1) ans++;
	For(i,1,10005) {
		For(j,1,n) {
			if(i==b[j]) now[j]^=1;
			else if(i>b[j] && (i-b[j])%a[j]==0) now[j]^=1;
		}
		int tot=0;
		For(j,1,n) if(now[j]==1) tot++;
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
}

