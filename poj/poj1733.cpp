//类似于食物链的处理方法，设立两个n的点数，然后奇偶相互转化
#include <bits/stdc++.h>
#define int long long
using namespace std;
int fa[120000],n,m,a[120000],cnt;
char ch[120];
struct node {
    int l,r,which;
} query[120000];
int find(int x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
signed main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        scanf("%lld%lld%s",&query[i].l,&query[i].r,ch);
        query[i].which=(ch[0]=='o'?1:0);
        a[++cnt]=query[i].l-1;
        a[++cnt]=query[i].r;
    }
    sort(a+1,a+cnt+1);
    n=unique(a+1,a+cnt+1)-a-1;
    //a数组相当于一张字典，用来找自己的树离散化以后是谁
    for(int i=1;i<=n*2;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
        int x=lower_bound(a+1,a+n+1,query[i].l-1)-a,y=lower_bound(a+1,a+n+1,query[i].r)-a;
        int x_1=x,x_2=x+n,y_1=y,y_2=y+n;
        if(!query[i].which) {
            if(find(x_1)==find(y_2)) return cout<<i-1,0;
            fa[find(x_1)]=find(y_1);
            fa[find(x_2)]=find(y_2);
        } else {
            if(find(x_1)==find(y_1)) return cout<<i-1,0;
            fa[find(x_1)]=find(y_2);
            fa[find(x_2)]=find(y_1);
        }
    }
    cout<<m;
    return 0;
}

