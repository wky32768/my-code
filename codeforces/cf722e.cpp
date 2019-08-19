#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=200005;
const int mod=1e9+7;
int fac[N],n,m,k,s,f[2005][25],t,ans,ny[N];//从(1,1)除法到达第i个特殊点，至少经过j个特殊点的方案数，用前缀和存储
inline int read() {
    int x=0,f=0; char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
inline int ksm(int a,int b) {
    int ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
inline int C(int n,int m) {if(n==0 || m==0) return 1;return fac[n]*ny[m]%mod*ny[n-m]%mod;}
inline int dis(int a,int b,int c,int d) {return C(abs(a-c)+abs(b-d),abs(a-c));}//没有特殊点时的距离
struct point {int x,y;} sxd[N];
inline bool cmp(point a,point b) {return a.x==b.x?a.y<b.y:a.x<b.x;}
signed main() {
    n=read(),m=read(),k=read(),s=read();
    fac[0]=1;
    For(i,1,n+m) fac[i]=fac[i-1]*i%mod;
    For(i,0,n+m) ny[i]=ksm(fac[i],mod-2);
    For(i,1,k) sxd[i].x=read(),sxd[i].y=read();
    sort(sxd+1,sxd+k+1,cmp);
    bool ok1=0,ok2=0;
    if(sxd[1].x!=1 || sxd[1].y!=1) {ok1=1;sxd[++k]=(point){1,1};}
    if(sxd[k].x!=n || sxd[k].y!=m) {ok2=1;sxd[++k]=(point){n,m};}
    if(ok1==1 && ok2==1) s*=1;
    else if(ok1==0 && ok2==1) s-=(s>>1);
    else if(ok1==1 && ok2==0) s-=(s>>1);
    else if(ok1==0 && ok2==0) s-=(s>>1),s-=(s>>1);
    sort(sxd+1,sxd+k+1,cmp);
    f[1][0]=1;
    t=log2(s)+2;
    For(i,2,k) {
        f[i][1]=dis(1,1,sxd[i].x,sxd[i].y);
        For(j,2,t) For(ztn,1,i-1) if(sxd[ztn].x<=sxd[i].x && sxd[ztn].y<=sxd[i].y){
            f[i][j]=(f[i][j]+(f[ztn][j-1]-f[ztn][j]+mod)%mod*dis(sxd[ztn].x,sxd[ztn].y,sxd[i].x,sxd[i].y)%mod)%mod;
            /*即走了j-1个特殊点到达j点（这样就有j个特殊点了*/
        }
    }
    For(i,1,t+1) {
         ans=(ans+(f[k][i]-f[k][i+1]+mod)%mod*s%mod)%mod;
        s=s-(s>>1);
    }
    ans=ans*ksm(dis(1,1,n,m),mod-2)%mod;
    cout<<ans;
    return 0;
}