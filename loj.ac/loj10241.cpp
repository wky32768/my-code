#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
signed main() {
    scanf("%lld%lld",&n,&k);
    if(n%(k+1)==0) puts("2");
    else puts("1");
    return 0;
}