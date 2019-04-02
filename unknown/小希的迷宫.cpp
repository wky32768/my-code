#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int fa[120000],n,m,a,b,vis[120000],cnt;
int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);	
}
signed main() {
	while(cin>>a>>b) {
		if(a==-1 || b==-1) break;
		bool flag=true;
		for(int i=1;i<=120000;i++) fa[i]=i;
		fa[a]=b;
		if(a==0 && b==0) {
			puts("Yes");
			continue;	
		}
		memset(vis,0,sizeof vis);
		vis[a]=vis[b]=1;
		while(cin>>a>>b) {
			vis[a]=vis[b]=1;
			if(a==0 || b==0) break;
			int aa=find(a),bb=find(b);
			if(aa==bb) flag=false;
			else fa[aa]=bb;
		}
		int geng=-1;
		for(int i=1;i<=110000;i++) if(vis[i]) {
			if(geng==-1) geng=find(i);
			else if(find(i)!=geng) {
				flag=false;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
yyhËÍ¸øÄúµÄÀñÎï 
???
#include <bits/stdc++.h>
using namespace std;
int fa[120000],vis[120000],n,m,a,b;
int find(int x) {
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);    
}
int main() {
    while(cin>>a>>b) {
        if(a==-1 || b==-1) break;
        bool flag=true;
        for(int i=1;i<=120000;i++) fa[i]=i;
        fa[a]=b;
        memset(vis,0,sizeof vis);
        vis[a]=vis[b]=1;
        if(a!=0||b!=0)
        while(cin>>a>>b) {
            vis[a]=vis[b]=1;
            if(a==0 || b==0) break;
            int aa=find(a),bb=find(b);
            if(aa==bb) flag=false;
            else fa[aa]=bb;
        }
        a=-1;
        for(int i=1;i<=120000;i++)if(vis[i]){
            if(a==-1)a=find(i);
            if(a!=find(i))flag=false;
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
*/
