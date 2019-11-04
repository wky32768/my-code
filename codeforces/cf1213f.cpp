#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
const int N=800005;
int head1[N],head2[N],cnt1,cnt2;
struct node {int next,to;} sxd1[N],sxd2[N];
inline void add1(int u,int v) {sxd1[++cnt1]=(node) {head1[u],v}; head1[u]=cnt1;}
inline void add2(int u,int v) {sxd2[++cnt2]=(node) {head2[u],v}; head2[u]=cnt2;}
int n,k,temp,x;
int dfn[N],low[N],tot,vis[N],kuai,belong[N];
stack <int> st;
inline void tarjan(int x) {
    dfn[x]=low[x]=++tot;
    vis[x]=1;
    st.push(x);
    for(register int i=head1[x];i;i=sxd1[i].next) {
        if(!dfn[sxd1[i].to]) {
            tarjan(sxd1[i].to);
            low[x]=min(low[x],low[sxd1[i].to]);
        } else if(vis[sxd1[i].to]) low[x]=min(low[x],dfn[sxd1[i].to]);
    }
    if(dfn[x]==low[x]) {
        kuai++;
        int at=0;
        while(at!=x && !st.empty()) {
            at=st.top(); st.pop();
            vis[at]=0;
            belong[at]=kuai;
        }
    }
}
int ru[N],ans[N];
queue <int> q;
inline void tp() {
    For(i,1,kuai) if(!ru[i]) q.push(i);
    int at=0;
    while(!q.empty()) {
        int now=q.front(); q.pop();
        ans[now]=at;
        if(at!=25) at++;
        for(register int i=head2[now];i;i=sxd2[i].next) {
            ru[sxd2[i].to]--;
            if(!ru[sxd2[i].to]) q.push(sxd2[i].to);
        }
    }
}
signed main() {
    n=read(),k=read();
    For(i,1,2) {
        temp=read();
        For(j,1,n-1) {
            x=read();
            add1(temp,x);
            temp=x;
        }
    }
    For(i,1,n) if(!dfn[i]) tarjan(i);
    if(kuai<k) return puts("NO"),0;
    For(j,1,n) for(register int i=head1[j];i;i=sxd1[i].next)
        if(belong[j]!=belong[sxd1[i].to]) 
			add2(belong[j],belong[sxd1[i].to]),ru[belong[sxd1[i].to]]++;
    tp();
    puts("YES");
    For(i,1,n) cout<<char(ans[belong[i]]+'a');
    return 0;
}
