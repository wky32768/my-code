/*考虑如果有一个字母出现了k次，那么这个子串的循环节个数一定是k的约数，
我们把所有的k取一个gcd，再找约数,以此剪枝
太神奇了，只需要比较l~r-len和l+len+1~r就可以了
ab ?? ?? ??
?? ab ?? ??

ab ab ?? ??
?? ab ??　??

ab ab ?? ??
?? ab ab ??

ab ab ab ??
?? ab ab ??

ab ab ab ??
?? ab ab ab

所以??一定是ab，因此的证。
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,x,y,ans,gg,tot,f[520000],s[520000],prime[520000],bg[520000];
char ch[520000];
bool vis[520000];
inline bool check(int l,int r,int len) {
	int ha1=f[r-len]-f[l-1]*s[r-l+1-len];
	int ha2=f[r]-f[l+len-1]*s[r-l+1-len];
	return (ha1==ha2);
}
inline int read() {
	int x=0;
	char ch=getchar();
	while(!(ch>='0' && ch<='9')) ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void write(int x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main() {
	scanf("%d",&n);
	scanf("%s",ch+1);
	scanf("%d",&m);
	s[0]=1;
	For(i,1,n) f[i]=f[i-1]*131+ch[i]-'a',s[i]=s[i-1]*131;
	For(i,2,n) {
		if(!bg[i]) bg[i]=i,prime[++tot]=i;
		for(register int j=1;j<=m;j++) {
			if(prime[j]>bg[i] || prime[j]>n/i) break;
			bg[i*prime[j]]=prime[j];
		}
	}
	while(m--) {
		x=read(),y=read();
		int ans=y-x+1,now=y-x+1;
		while(now!=1) {
			if(check(x,y,ans/(bg[now]))) ans/=bg[now];
			now/=bg[now];
			if(now==1) break;
		}
		write(ans);
		puts("");
	}
	return 0;
}