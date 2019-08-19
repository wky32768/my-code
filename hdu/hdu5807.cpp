#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {
    int x=0,f=0; char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=120;
const int mod=998244353;
int t,n,m,K,q,x,y,z;
int cnt,w[N],ok[N][N],f[N][N][N][3];//三个人在i,j,k，准备走的是l,所以当l==1，说明一轮已经走完了
void solve() {
    for(int i=n;i>=1;i--) for(int j=n;j>=1;j--) for(int k=n;k>=1;k--) {//从最终状态逆推
        f[i][j][k][0]=1;//位置可行就说明有了1个答案(不和法后面判了)
        For(ii,1,n) if(ok[i][ii]) f[i][j][k][0]=(f[ii][j][k][2]+f[i][j][k][0])%mod;
        For(jj,1,n) if(ok[j][jj]) f[i][j][k][1]=(f[i][jj][k][0]+f[i][j][k][1])%mod;
        For(kk,1,n) if(ok[k][kk]) f[i][j][k][2]=(f[i][j][kk][1]+f[i][j][k][2])%mod;
        if(abs(w[i]-w[j])>K || abs(w[j]-w[k])>K || abs(w[k]-w[i])>K) 
            f[i][j][k][0]=0;
    }
}
signed main() {
    t=read();
    while(t--) {
        n=read(),m=read(),K=read(),q=read();
        For(i,1,n) cin>>w[i];
        memset(ok,0,sizeof ok);
        For(i,1,m) x=read(),y=read(),ok[x][y]=ok[y][x]=1;
        memset(f,0,sizeof f);
        solve();
        while(q--) {
            x=read(),y=read(),z=read();
            cout<<f[x][y][z][0]<<'\n';
        }
    }
}