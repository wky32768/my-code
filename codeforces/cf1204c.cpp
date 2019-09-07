#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=120;
char ch[N][N];
int dis[N][N],n,m,now[2000005],ans[2000005],tot;
signed main() {
    memset(dis,0x3f,sizeof dis);
    n=read();
    For(i,1,n) scanf("%s",ch[i]+1);
    For(i,1,n) For(j,1,n) if(ch[i][j]=='1') dis[i][j]=1;
    For(i,1,n) dis[i][i]=0;//别忘了他
    For(k,1,n) For(i,1,n) For(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    m=read();
    For(i,1,m) now[i]=read();
    ans[++ans[0]]=now[1];
    For(i,2,m) {
        tot+=dis[now[i-1]][now[i]];
        if(tot>dis[ans[ans[0]]][now[i]]) {//i-1不可替代
            ans[++ans[0]]=now[i-1];
            tot=dis[ans[ans[0]]][now[i]];
        }
    }
    ans[++ans[0]]=now[m];
    cout<<ans[0]<<'\n';
    For(i,1,ans[0]) cout<<ans[i]<<' ';
    return 0;
}