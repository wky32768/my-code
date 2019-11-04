#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=100005;
int n,ans,one,zero;
char ch[N];
signed main() {
	n=read();
	scanf("%s",ch+1);
	For(i,1,n) if(ch[i]=='n') one++; else if(ch[i]=='z') zero++;
	For(i,1,one) cout<<"1 ";
	For(i,1,zero) cout<<"0 ";
	return 0;
}

