#include <bits/stdc++.h>
#define int long long
using namespace std;
int tt,n;
int ansat,ans=0;
double t,dt=0.994;
map <int,int> mp;
inline int calc(int x) {
	if(x==0) return 0;
    if(mp[x] && x!=0) return mp[x];
    while(!(x&1)) x>>=1;
    return mp[x]=calc(x>>1|1)+calc(x>>1);
}
inline int solve(int n) {
    int now=ansat,x=ansat,ans=0;
    t=20000000000000;
    while(t>1e6) {
        L1:;
        now=(int)(x+((rand()<<1)-RAND_MAX)*t/3)%n+1;
        if(now>n || now<0) goto L1;
        int haha=calc(now);
        int delta=haha-ans;
        if(delta>0) {
            ansat=now;
            x=now;
            ans=haha;
        } else if(exp(-delta/t)*RAND_MAX>rand()) x=now;
        t*=dt;
    }
    return ans;
}
signed main() {
    srand(998244353);
    srand(rand());
    mp[1]=1;
    cin>>tt;
    while(tt--) {
        cin>>n;
        int out=0;
        for(register int i=1;i<=50;i++) out=max(out,solve(n));
        cout<<out;
        puts("");
    }
    return 0;
}
