#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
const int N=500005;
int n,ans[N];
char ch[N],mn;
signed main() {
	scanf("%s",ch+1);
	n=strlen(ch+1);
	mn='z'+1;
	For(i,1,n) {if(ch[i]>mn) ans[i]=1;mn=min(mn,ch[i]);}
	For(i,1,n) puts(ans[i]==1?"Ann":"Mike");
}

