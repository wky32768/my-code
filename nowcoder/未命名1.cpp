#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,k,ans;
char ch[1200][1200];
signed main() {
	n=read(),k=read();
	For(i,1,n) {
		scanf("%s",ch[i]+1);
		For(j,1,n) if(ch[i][j]=='A') ans++;
	}
	cout<<ans;
	return 0;
}

