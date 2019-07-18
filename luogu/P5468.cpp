//sxd ak noi!
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
inline int read() {
    int x=0,f=0;
    char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
const int N=100005;
int n,m,a,b,c,f[N][1005],x,y,p,q;//第x个站点，时间为0
bool vis[N][1005];
struct node {
    int y,p,q;
};
vector <node> sxd[N];
inline int rem(int which,int time) {
    if(vis[which][time]) return f[which][time];
    if(which==n) {
        f[which][time]=time;
        return time;
    }
    f[which][time]=0x3f3f3f3f;
    vis[which][time]=1;
    for(register int i=0;i<sxd[which].size();i++) {
        node now=sxd[which][i];
        if(now.p<time) continue;
        f[which][time]=min(f[which][time],rem(now.y,now.q)+a*(now.p-time)*(now.p-time)+b*(now.p-time)+c);
    }
    return f[which][time];
}
signed main() {
    n=read(),m=read(),a=read(),b=read(),c=read();
    For(i,1,m) {
        x=read(),y=read(),p=read(),q=read();
        sxd[x].push_back((node){y,p,q});
    }
    cout<<rem(1,0);
    return 0;
}

