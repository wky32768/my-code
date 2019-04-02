#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,mod;
struct matrix {
    int w[120][120];
} c,ans;
matrix cheng(matrix a,matrix b) {
    matrix ans;
    memset(ans.w,0,sizeof ans.w);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++) 
            for(int k=1;k<=2;k++)
                ans.w[i][j]=(ans.w[i][j]+a.w[i][k]*b.w[k][j]%mod)%mod;
    return ans;
}
matrix ksm(matrix a,int b) {
    matrix ans;
    ans.w[1][1]=ans.w[2][2]=1;
    while(b) {
        if(b&1) ans=cheng(ans,a);
        a=cheng(a,a);
        b>>=1;
    }
    return ans;
}
signed main() {
    cin>>n>>mod;
    for(int i=1;i<=2;i++) for(int j=1;j<=2;j++) ans.w[i][j]=1;
    c.w[1][2]=c.w[2][1]=c.w[1][1]=1;
    ans=ksm(c,n);
    cout<<(ans.w[1][1]+ans.w[1][2]-1)%mod;
    return 0;
}