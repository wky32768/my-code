/*
x,y 都为奇数。那么 lcm(x, y)肯定是奇数，所以可以
x, y 为一奇一偶。那么lcm(x,y) 为偶数，所以不行。
x, y 都为偶数。可以转化为前面两种情况。求lcm会痛除以2，就相当于把两个数都除以2
所以只要二进制下有相同位数的零即可。 
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,a[200005],tot[200005],tong[105],mx,mxat,now;
signed main() {
	n=read();
	For(i,1,n) {
		a[i]=read(); now=a[i];
		while(now && now%2==0) {
			tot[i]++;
			now/=2;
		}
		tong[tot[i]]++;
		if(tong[tot[i]]>mx) mx=tong[tot[i]],mxat=tot[i];
	}
	write(n-mx); puts("");
	For(i,1,n) if(tot[i]!=mxat) write(a[i]),putchar(' ');
	return 0;
}

