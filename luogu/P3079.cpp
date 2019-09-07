#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define lowbit(x) (x&(-x))
using namespace std;
const int N=120000;
int n,nn,tree[1200000],ans,last=1;//注意last的初始值,每一个正在运行的值都应该是合法的
struct node {
    int x1,y1,x2,y2;
} a[N],b[N];
inline bool cmp1(node a,node b) {return a.x1<b.x1;}
inline bool cmp2(node a,node b) {return a.x2<b.x2;}
inline void add(int x,int C) {for(;x<=nn;x+=lowbit(x)) tree[x]+=C;}
inline int tot(int x) {
    int ans=0;
    for(;x;x-=lowbit(x)) ans+=tree[x];
    return ans;
}
signed main() {
    cin>>n;
    For(i,1,n) {
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
        a[i].x1++,a[i].y1++,a[i].x2++,a[i].y2++;
        b[i]=a[i];
        nn=max(nn,a[i].y2);
    }
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+n+1,cmp2);
    For(i,1,n) {
        for(;last<=n && b[last].x2<=a[i].x1;last++) add(b[last].y1,-1),add(b[last].y2+1,1);
        //对于最右侧已经跳出的三角形，不在对这条边产生影响。
        if(!tot(a[i].y1)) ans++;
        //在左右已经失去影响的效果下，只要不是上下都被锁定，就必须要画上这一条边。
        add(a[i].y1,1),add(a[i].y2+1,-1); 
    }
    cout<<ans;
    return 0;
}