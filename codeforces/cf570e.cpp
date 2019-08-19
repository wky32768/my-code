#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=520;
int n,m,f[2][N][N],now=0,ans;//f[][][]:第i步，上面的x坐标，下面的y坐标
char ch[N][N];
signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
    if(ch[1][1]!=ch[n][m]) return puts("0"),0;
    f[0][1][n]=1;//轮到左边的走
    for(int i=1;i<=(n+m)/2;i++) {//1,2是第一步
        now^=1;
        memset(f[now],0,sizeof f[now]);//必须把now放在最前面
        for(int j=1;j<=i+1;j++) {
            for(int a=n;a>=n-i;a--) {
                int k=i+2-j,b=n+m-i-a;
                if(j>a || k>b) continue;
                if(j<1 || j>n || k<1 || k>m) continue;
                //cout<<j<<" "<<k<<" "<<a<<" "<<b<<'\n';
                if(ch[j][k]==ch[a][b]) {
                    f[now][j][a]=(f[now][j][a]+f[now^1][j][a])%mod;
                    f[now][j][a]=(f[now][j][a]+f[now^1][j-1][a])%mod;
                    f[now][j][a]=(f[now][j][a]+f[now^1][j][a+1])%mod;
                    f[now][j][a]=(f[now][j][a]+f[now^1][j-1][a+1])%mod;
                    //cout<<"debug "<<now<<" "<<j<<" "<<a<<" "<<f[now][j][a]<<'\n';
                }
            }
        }
    }
    now^=1;//已经更过一层，所以要回退
    // cout<<"now="<<now<<'\n';
    if((n+m+1)%2==1) {
        for(int i=1;i<=n;i++) ans=(ans+f[now][i][i])%mod;
    } else {
        for(int i=1;i<=n;i++) {
            ans=(ans+f[now][i][i]+f[now][i][i+1])%mod;
        }
    }
    cout<<ans;
    return 0;
}