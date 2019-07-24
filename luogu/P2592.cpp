#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define mod (12345678)
using namespace std;
int n,m,k,ans,f[210][210][23][23];
signed main() {
    cin>>n>>m>>k;
    f[0][0][0][0]=1;
    For(i,0,n) For(j,0,m) For(a,0,k) For(b,0,k){
        f[i+1][j][a+1][max(0,b-1)]=(f[i+1][j][a+1][max(0,b-1)]+f[i][j][a][b])%mod;
        f[i][j+1][max(0,a-1)][b+1]=(f[i][j+1][max(0,a-1)][b+1]+f[i][j][a][b])%mod;
    }
    For(i,0,k) For(j,0,k) ans=(ans+f[n][m][i][j])%mod;
    cout<<ans;
    return 0;
}