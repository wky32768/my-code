//折半搜索，先搜左半边，找到解后排序离散化，然后找另一半的解，upper_bound与之对应
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[80],w,ans;
vector <int> a;
bool cmp(int a,int b) {return a>b;}
void dfs1(int rest,int now) {
    if(!rest) {return a.push_back(now);}
    dfs1(rest-1,now);
    if(now+s[rest]<=w) dfs1(rest-1,now+s[rest]);
}
void dfs2(int which,int now) {
    if(which==n+1) {
        int close=*--upper_bound(a.begin(),a.end(),w-now);//必须大于等于0
        ans=max(ans,now+close);
        return;
    }
    dfs2(which+1,now);
    if(now+s[which]<=w) dfs2(which+1,now+s[which]);
    return;
}
signed main() {
    scanf("%lld%lld",&w,&n);
    for(register int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1,cmp);
    int mid=(n/2+3);
    dfs1(mid-1,0);
    sort(a.begin(),a.end());
    m=unique(a.begin(),a.end())-a.begin();
    dfs2(mid,0);
    cout<<ans;
    return 0;
}