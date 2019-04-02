/*
树状数组维护几个比他小，几个比他大
使用这种方法要先考虑数据的范围
*/
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1200000;
int n,a[N],tree[N],l[N],r[N],ans1,ans2;
int ask(int at) {
    int ans=0;
    for(int i=at;i;i-=lowbit(i)) ans+=tree[i];
    return ans;
}
void add(int at,int C) {
    for(int i=at;i<=n;i+=lowbit(i)) tree[i]+=C;
}
signed main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--) {
        r[i]=ask(a[i]-1);
        add(a[i],1);
    }
    memset(tree,0,sizeof tree);
    for(int i=1;i<=n;i++) {
        l[i]=ask(a[i]-1);
        add(a[i],1);
    }
    //预处理
    for(int i=1;i<=n;i++) {
        ans1+=(n-i-r[i])*(i-1-l[i]);
        ans2+=l[i]*r[i];
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}