#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
struct matrix {
    int w[120][120];
} a,b,c;
int n,m,p;
signed main() {
    cin>>n>>m;
    For(i,1,n) For(j,1,m) cin>>a.w[i][j];
    cin>>p;
    For(i,1,m) For(j,1,p) cin>>b.w[i][j];
    For(i,1,n) For(k,1,p) {
        For(j,1,m) c.w[i][k]+=a.w[i][j]*b.w[j][k];
    }
    For(i,1,n) {
        For(k,1,p) cout<<c.w[i][k]<<" ";
        puts("");
    }
    return 0;
}