/*
ans=(a*(a-1)/2+b*(b-1)/2...)/((r-l+1)*(r-l)/2)
=(a^2+b^2+c^2...+x^2-(r-l+1))/((r-l+1)*(r-l))
顺便复习一下莫队吧，对于离线的算法可以先按照左端点排序，然后一步一步看似暴力的跳，可是复杂度非常的优秀.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,pos[120000],co[120000],s[120000],ans,block;//ans是平方和,s当前颜色的计数
struct node {
    int l,r,id,a,b;
} a[120000];
bool cmp(node a,node b) {
    if(pos[a.l]==pos[b.l]) return a.r<b.r;
    return a.l<b.l;
}
bool cmp_with_id(node a,node b) {
    return a.id<b.id;
}
void upd(int which,int add) {
    ans-=s[co[which]]*s[co[which]];
    s[co[which]]+=add;
    ans+=s[co[which]]*s[co[which]];
}
void solve() {
    for(int i=1,l=1,r=0;i<=m;i++) {
        for(;r<a[i].r;r++) upd(r+1,1);
        for(;l>a[i].l;l--) upd(l-1,1);
        for(;r>a[i].r;r--) upd(r,-1);
        for(;l<a[i].l;l++) upd(l,-1);
        if(a[i].l==a[i].r) {
            a[i].a=0,a[i].b=1;//只有一只袜子，就得钦定
            continue;
        }
        a[i].a=ans-(a[i].r-a[i].l+1);
        a[i].b=(a[i].r-a[i].l+1)*(a[i].r-a[i].l);
        int gg=__gcd(a[i].a,a[i].b);
        a[i].a/=gg,a[i].b/=gg;
    }

}
signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>co[i];
    block=sqrt(n);
    for(int i=1;i<=n;i++) pos[i]=(i-1)/block+1;
    for(int i=1;i<=m;i++) {
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    solve();
    sort(a+1,a+m+1,cmp_with_id);
    for(int i=1;i<=m;i++) cout<<a[i].a<<"/"<<a[i].b<<'\n';
    return 0;
}