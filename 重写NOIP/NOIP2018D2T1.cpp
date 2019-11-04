#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=5001;
int n,m,x,y,cnt,head[N],temp[N],ans[N],cant1,cant2,b1[N],b2[N];
bool vis[N];
vector <int> a[N];
void dfs1(int x,int f) {
	ans[++ans[0]]=x;
	vis[x]=1;
	For(i,0,a[x].size()-1) if(a[x][i]!=f && vis[a[x][i]]==0) dfs1(a[x][i],x);
}
inline int smaller() {
	int have=0;
	For(i,1,n) {
		if(temp[i]>ans[i]) return 0;
		if(temp[i]<ans[i]) return 1;
	}
	return 0;
}
void dfs2(int x,int f) {
	temp[++temp[0]]=x;	
	if(temp[0]==n) {
		if(smaller()==1) For(j,1,n) ans[j]=temp[j];		
		return;
	}
	vis[x]=1;
	For(i,0,a[x].size()-1)  if(a[x][i]!=f && vis[a[x][i]]==0 && !((x==cant1 && a[x][i]==cant2) || (x==cant2 && a[x][i]==cant1)) ) dfs2(a[x][i],x);
}
signed main() {
	n=read(),m=read();
	For(i,1,m) {
		x=b1[i]=read(),y=b2[i]=read();
		a[x].push_back(y),a[y].push_back(x);
	}
	For(i,1,n) sort(a[i].begin(),a[i].end());
	if(m==n-1) dfs1(1,0);
	else {
		memset(ans,0x3f,sizeof ans);
		For(i,1,m) {
			cant1=b1[i],cant2=b2[i];
			memset(vis,0,sizeof vis);
			temp[0]=0;
			dfs2(1,0);
		}
	}
	For(i,1,n) {write(ans[i]); putchar(' ');}
	return 0;
}

