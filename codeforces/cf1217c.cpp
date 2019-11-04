#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
char ch[200005];
int t,ans,sum[200005];
signed main() {
	t=read();
	while(t--) {
		scanf("%s",ch+1);
		ans=0;
		int n=strlen(ch+1);
		For(i,1,n) sum[i]=sum[i-1]+(ch[i]=='1');
		For(i,1,n) if(ch[i]=='1') {
			int at=0;
			For(j,i,min(n,i+20)) {
				at=at*2+(ch[j]=='1');
				int front=j-at+1;//若值要相等，就要往前推到这一位
				if(front<=0) break; 
				if(sum[i-1]-sum[front-1]==0) ans++;//i前面是前导0 
			}
		}
		write(ans);
		puts("");
	}
}

