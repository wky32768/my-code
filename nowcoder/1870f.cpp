#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Dep(i,a,b) for(register int i=a;i>=b;i--)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
char ch[50];
signed main() {
	scanf("%s",ch+1);
	if(ch[1]=='-') {
		cout<<"-";
		int now=strlen(ch+1);
		while(ch[now]=='0') now--;
		Dep(i,now,2) cout<<ch[i];
	} else {
		int now=strlen(ch+1);
		while(ch[now]=='0') now--;
		Dep(i,now,1) cout<<ch[i];	
	}
	return 0;
}

