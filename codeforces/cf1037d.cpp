#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=500000;
int n,x,y,a[N],mp[N],head[N],cnt,last;
struct node {
	int next,to;
} sxd[N];
void add(int u,int v) {
	sxd[++cnt].next=head[u];
	sxd[cnt].to=v;
	head[u]=cnt;
}
vector <int> w;
bool cmp(int a,int b) {
	return mp[a]<mp[b];
}
queue <int> q ;
bool vis[N];
signed main() {
	cin>>n;
	For(i,1,n-1) {
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	For(i,1,n) {
		cin>>a[i];
		mp[a[i]]=i;
	}
	if(a[1]!=1) return puts("No"),0;
	q.push(1);
	vis[1]=true;
	last=0;
	while(!q.empty()) {
		int at=q.front();
		q.pop();
		w.clear();
		vis[at]=1;
		if(at!=a[++last]) return puts("No"),0;
		for(int i=head[at];i;i=sxd[i].next) if(!vis[sxd[i].to]) w.push_back(sxd[i].to);
		int siz=w.size();
		sort(w.begin(),w.end(),cmp);
		For(i,0,siz-1) {
			q.push(w[i]);
		}
	}
	puts("Yes");
	return 0;
}
