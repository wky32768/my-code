#include <bits/stdc++.h>
using namespace std;
int n,a[120],depth;
bool dfs(int at) {
    if(at==depth) return a[at]==n;
    for(register int i=at;i>=1;i--) for(register int j=i;j>=1;j--) 
        if(a[i]+a[j]<=n && a[i]+a[j]>a[at]) {
            a[at+1]=a[i]+a[j];
            if(dfs(at+1)) return 1;
        }
    return 0;
}
signed main() {
    a[1]=1;
    while(scanf("%d",&n) && n) {
        depth=1;
        while(!dfs(1)) depth+=1;
        for(register int i=1;i<=depth;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}