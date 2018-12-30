#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,t,head[110000],cnt,now;
struct node {int next,to,w;} sxd[110000];
inline int read() {
    register int x=0,f=1;
    register char ch=getchar();
    while(!(ch>='0' && ch<='9')) {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(int x) {
    if(x>=10) write(x/10);
    register char ch=x%10+'0';
    putchar(ch);
}
void add(int u,int v,int w) {
    sxd[++cnt].next=head[u];
    sxd[cnt].to=v;
    sxd[cnt].w=w;
    head[u]=cnt;
}
multiset <long long> q[110000];
inline int dfs(int at,int fa,int x) {
    q[at].clear();
    int val=0;
    for(int i=head[at];i;i=sxd[i].next) {
        if(sxd[i].to==fa) continue;
        val=dfs(sxd[i].to,at,x)+sxd[i].w;
        if(val>=x) now++;
        else q[at].insert(val);
    }
    long long mx=0;
    while(!q[at].empty()) {
        long long res=*q[at].begin();
        if(q[at].size()==1) return max(mx,res);	
        multiset <int> :: iterator it=q[at].lower_bound(x*(1ll)-res);
        if(it==q[at].begin() && q[at].count(*it)==1) it++;
        if(it==q[at].end()) {
            mx=max(mx,res);	
            q[at].erase(q[at].find(res));
        } else {
            now++;
            q[at].erase(q[at].find(res));	
            q[at].erase(q[at].find(*it));
        }
    }
    return mx;
}
bool ok(int x,int t) {
    memset(q,0,sizeof q);
    now=0;
    dfs(1,0,x);
    return now>=t;
}
signed main() {
    n=read();
    t=read();
    int sum=0;
    For(i,1,n-1) {
        int u=read(),v=read(),w=read();
        add(u,v,w);	
        add(v,u,w);
        sum+=w;
    }
    int l=1,r=sum/t+1,mid,ans=0;
    while(l<=r) {
        mid=(l+r) >> 1;
        if(ok(mid,t)) {
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    write(ans);
    return 0;
}
