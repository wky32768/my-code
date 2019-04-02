#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[120000],now;
signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        now=now^a[i];
    }
    if(now) puts("win");
    else puts("lose");
    return 0;
}