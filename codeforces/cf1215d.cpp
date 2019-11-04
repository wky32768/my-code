//https://www.cnblogs.com/gaudar/p/11525874.html
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
int n,tot1,tot2,q1,q2;
char ch[200005];
signed main() {
	n=read();
	scanf("%s",ch+1);
	For(i,1,n/2) {
		if(ch[i]=='?') q1++;
		else tot1+=ch[i]-'0';	
	}
	For(i,n/2+1,n) {
		if(ch[i]=='?') q2++;
		else tot2+=ch[i]-'0';	
	}
	if(q1==q2) return puts((tot1==tot2?"Bicarp":"Monocarp")),0;	
	if(tot1>tot2 && q1>q2) return puts("Monocarp"),0;
	if(tot1<tot2 && q1<q2) return puts("Monocarp"),0;
	if(abs(tot1-tot2)*1.0==abs(q1-q2)*4.5) puts("Bicarp");
	else puts("Monocarp");
	return 0;
}
