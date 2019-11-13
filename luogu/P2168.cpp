//哈夫曼树复习 
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}

const int N=100005;
int n,k,w[N],tot,ans;
struct node {
	int w,h;//h是到根的距离 
	friend bool operator < (node a,node b) {return (a.w==b.w)?a.h>b.h:a.w>b.w;}
};
priority_queue <node> q;

signed main() {
	n=read(),k=read();
	For(i,1,n) {w[i]=read();q.push((node) {w[i],1});}
	if((n-1)%(k-1)) {For(i,1,(k-1)-(n-1)%(k-1)) q.push((node) {0,1});tot=(k-1)-(n-1)%(k-1)+n;}
	else tot=n;
	while(tot>=2) {
		int tot_w=0,mx=0;//注意找最高的 
		For(i,1,k) {
			tot_w+=q.top().w;
			mx=max(mx,q.top().h);
			q.pop();
		}
		ans+=tot_w;
		q.push((node) {tot_w,mx+1});
		tot-=(k-1);		
	}
	return cout<<ans<<'\n'<<q.top().h-1,0;
}

