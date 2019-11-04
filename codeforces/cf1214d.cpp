#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
vector <int> q[1000005];
int n,m;
char ch[1000005];
bool flag=0;
inline void dfs(int x,int y) {
	if(x==n && y==m) {
		flag=1;return;	
	}
	if(flag==1) return;
	if(x>n || y>m || x<=0 || y<=0 || q[x][y]==0) return;
	if(flag==0 && (x!=1 || y!=1)) q[x][y]=0;
	dfs(x+1,y);
	dfs(x,y+1);
}
signed main() {
	n=read(),m=read();
	For(i,1,n) {
		scanf("%s",ch+1);
		q[i].push_back(0);
		For(j,1,m) {
			q[i].push_back(ch[j]=='.');	
		}
	}
	dfs(1,1);
	if(flag==0) return puts("0"),0;
	flag=0;
	dfs(1,1);
	if(flag==1) return puts("2"),0;
	else return puts("1"),0;
}

