#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=230;
int n,m,a[N],b[N],vis[2300000];
signed main() {
	n=read();
	For(i,1,n) a[i]=read(),vis[a[i]]=1;
	m=read();
	For(i,1,m) b[i]=read(),vis[b[i]]=1;
	For(i,1,n) For(j,1,m) if(vis[a[i]+b[j]]==0) {cout<<a[i]<<" "<<b[j];return 0;}
}

