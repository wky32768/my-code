#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt, prime[1200000], v[1200000];
void shai() {
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            prime[++cnt]=i;
            v[i]=i;
        }
        for(int j=1;j<=cnt;j++) {
            if(prime[j]>v[i] || prime[j]>n/i) break;
            v[i*prime[j]]=prime[j];
        }
    }
}
signed main() {
    cin >> n;
    shai();
    for(int i=1;i<=cnt;i++) {
        int now=1,ans=0;
        for(;pow(prime[i],now)<=n;now++) {
            ans+=n/(pow(prime[i],now));
        }
        cout<<prime[i]<<" "<<ans;
        puts("");
    }
    return 0;
}