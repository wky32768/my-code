#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N =55;
int n,m,a[N][N],cnt,vis[N][N];
pair <int,int> ans[3000];
signed main() {
    n=read(),m=read();
    For(i,1,n) For(j,1,m) a[i][j]=read();
    For(i,1,n-1) For(j,1,m-1) if(a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1) {
        vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
        ans[++cnt]=make_pair(i,j);
    }
    bool flag=true;
    For(i,1,n) For(j,1,m) if(a[i][j]==1 && vis[i][j]==0) flag=false;
    if(flag==false) return puts("-1"),0;
    cout<<cnt<<'\n';
    For(i,1,cnt) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    return 0;
}