/*
可持久化trie树，详见笔记本
a[p] xor a[p + 1] xor ... xor a[N] xor x = s[p - 1] xor s[N] xor x
当l <= p <= r时,求p,使s[p - 1] xor s[N] xor x最大 
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int trie[14400000][2],latest[14400000],root[1200000],s[1200000],n,m,tot,x,l,r;
char ch[12];
#define gc getchar
inline int read() {
    int x=0;
    char ch=gc();
    while(!(ch>='0' && ch<='9')) ch=gc();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=gc();
    return x;
}
inline void write(int x) {
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
inline void insert(int which,int at,int used,int now) {
    if(at<0) {//现在的最后一位，要进行这一位的标记
        latest[now]=which;
        return;
    }
    int c=(s[which]>>at)&1;
    if(used) trie[now][c^1]=trie[used][c^1];//如果以前的有别的分叉，就对现在的点也连过去
    //如果!used说明先前的不用继续走了，也就不需要再同步了
    trie[now][c]=++tot;//建立新点
    insert(which,at-1,trie[used][c],trie[now][c]);
    latest[now]=max(latest[trie[now][0]],latest[trie[now][1]]);
}
inline int ask(int now,int val,int k,int mn) {//mn可走
    if(k<0) return s[latest[now]]^val;//跑完了，记录答案
    int c=(val>>k)&1;
    if(latest[trie[now][c^1]]>=mn) return ask(trie[now][c^1],val,k-1,mn);
    else return ask(trie[now][c],val,k-1,mn);
}
signed main() {
    scanf("%lld%lld",&n,&m);
    latest[0]=-1;//必须是-1,不然L=1时会炸(l-1=0)
    root[0]=++tot;
    insert(0,25,0,root[0]);
    for(register int i=1;i<=n;i++) {
        x=read();
        s[i]=s[i-1]^x;
        root[i]=++tot;
        insert(i,25,root[i-1],root[i]);
    }
    for(register int i=1;i<=m;i++) {
        scanf("%s",ch);
        if(ch[0]=='A') {
            x=read();
            root[++n]=++tot;
            s[n]=s[n-1]^x;
            insert(n,25,root[n-1],root[n]);
        } else {
            scanf("%lld%lld%lld",&l,&r,&x);
            write(ask(root[r-1],x^s[n],25,l-1));
            puts("");
        }
    }
    return 0;
}