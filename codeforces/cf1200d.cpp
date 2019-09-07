#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=2005;
int ans,tot,n,k,a[N][N],hang[N][N],lie[N][N],toth[N][N],totl[N][N];
char ch[N][N];
signed main() {
	n=read(),k=read();
	For(i,1,n) scanf("%s",ch[i]+1);
	For(i,1,n) For(j,1,n) {
		hang[i][j]=hang[i][j-1]+(ch[i][j]=='B');
		lie[i][j]=lie[i][j-1]+(ch[j][i]=='B');
	}
	For(i,1,n) {if(!hang[i][n]) tot++;if(!lie[i][n]) tot++;}
	For(i,1,n) For(j,1,n-k+1) {//连着有几行在删掉j~j+k-1之后可以变成白线 
		toth[i][j]=toth[i-1][j]+(hang[i][j+k-1]-hang[i][j-1]==hang[i][n] && (hang[i][n]>0));
		totl[i][j]=totl[i-1][j]+(lie[i][j+k-1]-lie[i][j-1]==lie[i][n] && (lie[i][n]>0));
	}
	For(i,1,n-k+1) For(j,1,n-k+1) 
		ans=max(ans,tot+toth[i+k-1][j]-toth[i-1][j]+totl[j+k-1][i]-totl[j-1][i]);
	cout<<ans;
	return 0;
}

