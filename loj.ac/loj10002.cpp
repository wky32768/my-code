#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    double l,r;
    friend bool operator < (node a,node b) {
        return a.l<b.l;
    }
} a[120000];
int n,l,w,t,x,y,cnt,ans;
signed main() {
	cin>>t;
    while(t--) {
        cin>>n>>l>>w;
        cnt=0;
        for(int i=1;i<=n;i++) {
            cin>>x>>y;
            if(y<w/2) continue;
            a[++cnt].l=x-sqrt(y*y-w*w/4.0);
            a[cnt].r=x+sqrt(y*y-w*w/4.0);
        }
        ans=0;
        sort(a+1,a+cnt+1);
        double at=0,go=0;
        while(at<l) {
            ans++;
            go=at;
            for(int i=1;a[i].l<=at && i<=cnt;i++) go=max(go,a[i].r);
            if(go==at && at<l) {
                puts("-1");
                goto L1;
            }
            at=go;
        }
        cout << ans << '\n';
        L1:;
    }
    return 0;
}
