#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,ch[120000][2],val[120000],dis[120000],fa[120000],opt,x,y;
int merge(int x,int y) {
	if(!x || !y) return x+y;
	if(val[x]>val[y] || (val[x]==val[y] && x>y)) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	fa[ch[x][1]]=x;
	if(dis[ch[x][0]]<dis[ch[x][1]]) swap(ch[x][0],ch[x][1]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
int find(int x) {
	while(fa[x]) x=fa[x];
	return x;
}
void pop(int x) {
	val[x]=-1;	
	fa[ch[x][0]]=fa[ch[x][1]]=0;
	merge(ch[x][0],ch[x][1]);
}
signed main() {
	cin>>n>>m;
	dis[0]=-1;
	For(i,1,n) cin>>val[i];
	For(i,1,m) {
		cin>>opt;
		if(opt==1) {
			cin>>x>>y;
			if(val[x]==-1 || val[y]==-1) continue;
			int xx=find(x),yy=find(y);
			if(xx==yy) continue;
			merge(xx,yy);
		} else {
			cin>>x;
			if(val[x]==-1) puts("-1");
			else {
				int xx=find(x);
				cout<<val[xx]<<'\n';
				pop(xx);	
			}
		}
	}
	return 0;
}

