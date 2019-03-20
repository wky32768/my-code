#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1200000;
int n, m, tot, l, r, k, cnt, a[N], root[N], mp[N];
struct segment {
    int ls, rs, w;
} tree[N << 2];
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f ? -x : x;
}
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
int build (int l, int r) {
    /*
    返回动态的参数
    跟普通的树不一样，这次需要一个一个读入，一开始的处理相当于空树
    */
    int now = ++tot, mid = (l + r) >> 1;
    if (l == r)
        return now;
    tree[now].ls = build(l, mid);
    tree[now].rs = build(mid + 1, r);
    return now;
}
int insert(int old, int l, int r, int x, int val) {
    int now = ++tot, mid = (l + r) >> 1;
    tree[now] = tree[old]; //只要同步了，一定是连向老的边
    if (l == r) {
        tree[now].w += val;
        return now;
    }
    if (x <= mid)
        tree[now].ls = insert(tree[old].ls, l, mid, x, val);
    else
        tree[now].rs = insert(tree[old].rs, mid + 1, r, x, val);
    tree[now].w = tree[tree[now].ls].w + tree[tree[now].rs].w;
    return now;
}
int ask(int p,int q,int l,int r,int k) {
    if(l==r) return l;//找到答案位置
    int mid=(l+r)>>1,tot_left=tree[tree[p].ls].w-tree[tree[q].ls].w;
    if(tot_left>=k) return ask(tree[p].ls,tree[q].ls,l,mid,k);
    else return ask(tree[p].rs,tree[q].rs,mid+1,r,k-tot_left);
}
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        mp[++cnt] = a[i];
    }
    sort(mp + 1, mp + cnt + 1);
    cnt = unique(mp + 1, mp + cnt + 1) - (mp + 1); // Unique返回第一个重复的数
    root[0] = build(1, cnt);
    for (int i = 1; i <= n; i++) {
        int x = lower_bound(mp + 1, mp + cnt + 1, a[i]) - mp;
        root[i] = insert(root[i - 1], 1, cnt, x, 1);
    }
    while (m--) {
        l=read(),r=read(),k=read();
        write(mp[ask(root[r],root[l-1],1,cnt,k)]);
        puts("");
    }
}