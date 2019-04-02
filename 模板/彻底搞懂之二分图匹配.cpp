#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,m,e,x,y,line[1200][1200],used[1200],girl[1200];
bool find(int x) {
	For(j,1,m) if(line[x][j] && !used[j]) {
		used[j]=1;
		if((!girl[j]) || find(girl[j])) {
			girl[j]=x;
			return 1;
		}
	}
	return 0;
}
void mx_match() {
	int ans=0;
	For(i,1,n) {
		memset(used,0,sizeof used);
		if(find(i)) ans++;
	}
	cout<<ans;
}
signed main(){
	cin>>n>>m>>e;
	For(i,1,e) {
		cin>>x>>y;
		if(x>=1 && y>=1 && x<=n && y<=m) line[x][y]=1;
	}
	mx_match();
	return 0;
}
//https://blog.csdn.net/dark_scope/article/details/8880547
