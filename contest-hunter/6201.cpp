//模拟最小生成树的过程，在两个集合之间的所有边都修成w+1即可
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,x,y,z,ans,cnt;
int fa[120000],sz[1200000];
struct node {
    int x,y,z;
} sxd[240000];
bool cmp(node a,node b) {
    return a.z<b.z;
}
int find(int x) {
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
signed main() {
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        ans=cnt=0;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<n;i++) {
            cnt++;
            scanf("%lld%lld%lld",&sxd[cnt].x,&sxd[cnt].y,&sxd[cnt].z);
        }
        sort(sxd+1,sxd+n,cmp);
        for(int i=1;i<n;i++) {
            int x=find(sxd[i].x),y=find(sxd[i].y);
            if(x==y) continue;
            ans+=(sxd[i].z+1)*(sz[x]*sz[y]-1);
            fa[x]=y;
            sz[y]+=sz[x];
        }
        cout<<ans<<'\n';
    }
    return 0;
}