#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    int x,y;
} sxd[120000];
int n,r,pos,ans,cnt,x,y;
bool cmp(sxd a,sxd b) {return a.x>b.x;}
void solve() {
    sort(sxd+1,sxd+n+1,cmp);
    pos=ans=0;
    for(int i=1;i<=n;i++) {
        if(sxd[i].x>pos) {
            ans++;
            pos=sxd[i].y;
        } else {
            
        }


    }

}
signed main() {
    while(scanf("%lld%lld",&n,&r)!=EOF && n) {
        cnt++;
        for(int i=1;i<=n;i++) {
            cin>>x>>y;
            sxd[i].x=x-r;
            sxd[i].y=x+r;
        }
        solve();
    }
    return 0;
}