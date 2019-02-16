#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=800000;
struct node {
    int next,to,w,id;
} sxd[N];
struct bian {
    int x,y,w,id;
} pfy[N];
int n,m,x,y,z,ans,cnt,cnt2,mp[N];
bool vis[N];
void add_bian(int u,int v,int w,int id) {
    pfy[++cnt2]=(bian) {
        u,v,w,id
    };
}
bool cmp(bian a,bian b) {
    return a.w<b.w;
}
int bing[800000],fa[N][25],mx1[N][25],mx2[N][25],head[N],depth[N],ok[800000],tot=21474836472147483647;
int find(int x) {
    if(bing[x]==x) return x;
    else return bing[x]=find(bing[x]);
}
void add(int u,int v,int w,int id) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    sxd[cnt].w=w;
    sxd[cnt].id=id;
    head[u]=cnt;
}
int lca(int x,int y) {
    if(depth[x]>depth[y]) swap(x,y);
    for(int i=20; i>=0; i--) if(depth[x]<=depth[y]-(1<<i)) y=fa[y][i];
    if(x==y) return x;
    for(int i=20; i>=0; i--) if(fa[x][i]!=fa[y][i]) {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
void zuixiao() {
    for(int i=1; i<=n; i++) bing[i]=i;
    sort(pfy+1,pfy+m+1,cmp);
    int at=0;
    for(int i=1; i<n; i++) {
        L1:;
        at++;
        int x=pfy[at].x,y=pfy[at].y;
        int xx=find(x),yy=find(y);
        if(xx==yy) goto L1;
        ok[pfy[at].id]=true;
        ans+=pfy[at].w;
        bing[xx]=yy;
    }
}
void solve() {
    for(int i=1; i<=m; i++)
        if(!ok[pfy[i].id]) {
            int LCA=lca(pfy[i].x,pfy[i].y),now1=0,now2=0,x=pfy[i].x,y=pfy[i].y;
            for(int j=20; j>=0; j--) {
                if(depth[fa[x][j]]>=depth[LCA]) {
                    int aa,bb;
                    aa=max(now1,mx1[x][j]);
                    if(now1==mx1[x][j]) bb=max(now2,mx2[x][j]);
                    else bb=max(max(now2,mx2[x][j]),min(now1,mx1[x][j]));
                    now1=aa,now2=bb;
                }
                if(depth[fa[y][j]]>=depth[LCA]) {
                    int aa,bb;
                    aa=max(now1,mx1[y][j]);
                    if(now1==mx1[y][j]) bb=max(now2,mx2[y][j]);
                    else bb=max(max(now2,mx2[y][j]),min(now1,mx1[y][j]));
                    now1=aa,now2=bb;
                }
            }
            if(-now1+ans+pfy[i].w!=ans) tot=min(tot,-now1+ans+pfy[i].w);
            if(-now2+ans+pfy[i].w!=ans) tot=min(tot,-now2+ans+pfy[i].w);
        }
}
void go(int at,int f) {
    depth[at]=depth[f]+1;
    for(int i=1; (1<<i)<=depth[at]; i++) {
        fa[at][i]=fa[fa[at][i-1]][i-1];
        mx1[at][i]=max(mx1[at][i-1],mx1[fa[at][i-1]][i-1]);
        if(mx1[at][i-1]==mx1[fa[at][i-1]][i-1])
            mx2[at][i]=max(mx2[at][i-1],mx2[fa[at][i-1]][i-1]);
        else mx2[at][i]=max(max(mx2[at][i-1],mx2[fa[at][i-1]][i-1]),min(mx1[at][i-1],mx1[fa[at][i-1]][i-1]));
    }
    for(int i=head[at]; i; i=sxd[i].next) {
        if(sxd[i].to==f || !ok[sxd[i].id]) continue;
        fa[sxd[i].to][0]=at;
        mx1[sxd[i].to][0]=sxd[i].w;
        go(sxd[i].to, at);
    }
}
signed main() {
    cin>>n>>m;
    for(int i=1; i<=m; i++) {
        cin>>x>>y>>z;
        add(x,y,z,i);
        add(y,x,z,i);
        add_bian(x,y,z,i);
    }
    zuixiao();
    go(1,0);
    solve();
    cout<<tot;
    return 0;
}
