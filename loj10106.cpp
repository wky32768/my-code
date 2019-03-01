#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=12000;
int ru[N],chu[N],fa[N],vis[N],t,n;
char ch[1200];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main() {
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		memset(ru,0,sizeof ru);
		memset(chu,0,sizeof chu);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=26;i++) fa[i]=i;
		for(int i=1;i<=n;i++) {
			scanf("%s",ch+1);
			int xx=ch[1]-'a'+1,yy=ch[strlen(ch+1)]-'a'+1;
			chu[xx]++,ru[yy]++;
			vis[xx]=vis[yy]=1;
			int x=find(xx),y=find(yy);
			if(x!=y) fa[x]=y;
		}
		int laoda=0,sted=0,cannot=0;
		for(int i=1;i<=26;i++) {
			if(vis[i] && fa[i]==i) laoda++;
			if(abs(ru[i]-chu[i])==1) sted++;	
			else if(ru[i]!=chu[i]) cannot++;
		}
		/*
		如果Laoda>=2即有两个及以上不相交的环，肯定不行
		如果ru[i]-chu[i]=+-1,则为奇点，可以做开始点或结束点
		如果Abs>2显然不行啊 
		*/
		if(laoda>=2 || sted>=3 || cannot) puts("The door cannot be opened.");
		else puts("Ordering is possible.");
	}
	return 0;
}