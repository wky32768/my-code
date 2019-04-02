#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=120000;
int n,m,a[N];
struct node {
    int mx,mn;
} tree[N<<2];
void build(int rt,int l,int r) {
    if(l==r) {
        tree[rt].mx=tree[rt].mn=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
    tree[rt].mn=min(tree[rt<<1].mn,tree[rt<<1|1].mn);
}
int search_mx(int L,int R,int l,int r,int rt) {
    if(L<=l && r<=R) return tree[rt].mx;
    int mid=(l+r)>>1,mx=-1e18;
    if(L<=mid) mx=max(mx,search_mx(L,R,l,mid,rt<<1)); 
    if(R>mid) mx=max(mx,search_mx(L,R,mid+1,r,rt<<1|1));
    return mx;
}
int search_mn(int L,int R,int l,int r,int rt) {
    if(L<=l && r<=R) return tree[rt].mn;
    int mid=(l+r)>>1,mn=1e18;
    if(L<=mid) mn=min(mn,search_mn(L,R,l,mid,rt<<1)); 
    if(R>mid) mn=min(mn,search_mn(L,R,mid+1,r,rt<<1|1));
    return mn;
}
signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=n-m+1;i++) {
        cout<<search_mx(i,i+m-1,1,n,1)<<" "<<search_mn(i,i+m-1,1,n,1)<<'\n';
    }
    return 0;
}