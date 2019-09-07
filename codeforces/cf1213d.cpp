#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=200005;
int tot[N][20],n,k,mx,mx_use,a[N],use,ans=0x3f3f3f3f;//tot[i][j]:做j步，现在的值是i
signed main() {
    n=read(),k=read();
    For(i,1,n) {
        a[i]=read(); 
        mx=max(a[i],mx);
        use=0;
        for(register int now=a[i];now;use++) {tot[now][use]++;now/=2;}
        tot[0][use]++;
        mx_use=max(use,mx_use);
    }
    // For(i,0,5) 
    //     For(j,0,5) {
    //         cout<<i<<" "<<j<<" "<<tot[i][j]<<'\n';
    //     }
    For(i,0,mx) {
        // cout<<"i="<<i<<'\n';
        int cost=0,at=0,zong=0;
        while(zong<k && at<=mx_use) {
            int yyh=min(tot[i][at],k-zong);
            // cout<<"yyh="<<yyh<<'\n';
            zong+=yyh;
            cost+=yyh*at;
            at++;
            // cout<<"cost="<<cost<<'\n';
        }
        if(zong>=k) ans=min(ans,cost);
    }
    write(ans);
    return 0;
}