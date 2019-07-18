#include <bits/stdc++.h>
using namespace std;
int c[1055][1055],n,x,y,a,b;
bool vis[1055][1055];
priority_queue <pair <int,pair <int,int> > > q;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
int read() {
	int x=0,f=0;
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
void bfs(int x,int y) {
	q.push(make_pair(0,make_pair(-x,-y)));
	vis[x][y]=1;
	while(!q.empty()) {
		int x=-q.top().second.first,y=-q.top().second.second,w=q.top().first;
		q.pop();
		for(register int i=0;i<4;i++) {
			int ww=w;
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<0 || xx>1051 || yy<0 || yy>1051 || vis[xx][yy]) continue;
			if(c[xx][yy]==1) ww--;
			if(xx==0 && yy==0) {
				cout<<-w;
				exit(0);
			}
			vis[xx][yy]=1;
			q.push(make_pair(ww,make_pair(-xx,-yy)));
		}
	}
}
signed main() {
	cin>>n>>x>>y;
	while(n--) {
		a=read(),b=read();
		c[a][b]=1;
	}
	bfs(x,y);
	return 0;
}
