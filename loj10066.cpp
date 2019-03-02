#include <bits/stdc++.h>
using namespace std;
int n,m,fa[240000],w[120000],cnt,mn=0x3f3f3f3f;
struct node {int u,v,w;friend bool operator < (node a,node b) {return a.w<b.w;} } sxd[240000];
int find(int x) {
    if(fa[x]==x) {
        return x;	
    }
    return fa[x]=find(fa[x]);
}
int kruskal() {
    int ans=0,times=0;
    sort(sxd+1,sxd+m+1);
    for(int i=1;i<=m;i++) {
        int uu=find(sxd[i].u),vv=find(sxd[i].v);
        if(uu==vv) continue;
        ans+=sxd[i].w;
        fa[uu]=vv;
        times++;
        if(times==n) break;
    }
    return ans;
}
signed main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&w[i]);sxd[++cnt].u=0;sxd[cnt].v=i;sxd[cnt].w=w[i];}
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        int x;
        scanf("%d",&x);
        if(!x) continue;
        sxd[++cnt].u=i;
        sxd[cnt].v=j;
        sxd[cnt].w=x;
    }
    m=cnt;
    cout<<kruskal();
    return 0;
}