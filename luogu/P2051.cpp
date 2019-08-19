#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int mod=9999973;
const int N=120;
int f[N][N][N],n,m,ans;//f[][][]:现在在第i行，前面有j个选了一个的列，k个选了两个的列
signed main() {
    cin>>n>>m;
    f[0][0][0]=1;
    For(i,0,n-1) For(j,0,m) for(int k=0;j+k<=m;k++) {
        f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
        if(m-j-k>=1) f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k]*(m-j-k))%mod;//0->1
        if(j>=1) f[i+1][j-1][k+1]=(f[i+1][j-1][k+1]+f[i][j][k]*j)%mod;//1->2
        if(m-j-k>=2) f[i+1][j+2][k]=(f[i+1][j+2][k]+f[i][j][k]*(m-j-k)*(m-j-k-1)/2)%mod;//0->1 && 0->1
        if(j>=2) f[i+1][j-2][k+2]=(f[i+1][j-2][k+2]+f[i][j][k]*j*(j-1)/2)%mod;//1->2 && 1->2
        if(m-j-k>=1 && j>=1) f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k]*j*(m-j-k))%mod;//0-1 && 1-2
    }
    For(i,0,m) for(int j=0;i+j<=m;j++) ans=(ans+f[n][i][j])%mod;
    cout<<ans;
    return 0;
}