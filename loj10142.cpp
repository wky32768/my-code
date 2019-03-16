//树链剖分万岁！每一个宗教维护线段树(动态开点线段树)
//动态开点后，用每个节点的l,r进行维护，其他的跟普通的树链剖分其实差不多
#include <bits/stdc++.h>
using namespace std;
const int N = 120000;
int n, m, e = 1, g = 1, cnt, x, y;
int root[N], head[N], mp[N], top[N], depth[N], fa[N], son[N], sz[N], c[N],
w[N]; char ch[12]; struct node {
    int next, to;
} sxd[N << 1];
struct segment {
    int l, r, sum, mx;
} tree[N << 4];
int read() {
    int x = 0;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x;
}
void write(int x) {
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
void pushup(int x) {
    tree[x].sum = tree[tree[x].l].sum + tree[tree[x].r].sum;
    tree[x].mx = max(tree[tree[x].l].mx, tree[tree[x].r].mx);
}
void clean(int x) { tree[x].l = tree[x].r = tree[x].sum = tree[x].mx = 0; }
void insert(int which, int C, int l, int r, int &rt) {
    if (!rt)
        rt = e++; //动态开点
    if (l == r && l == which) {
        tree[rt].sum = tree[rt].mx = C;
        return;
    }
    int mid = (l + r) >> 1;
    if (which <= mid)
        insert(which, C, l, mid, tree[rt].l);
    else
        insert(which, C, mid + 1, r, tree[rt].r);
    pushup(rt);
}
void remove(int which, int l, int r, int &rt) {
    if (l == r) {
        clean(rt);
        rt = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (which <= mid)
        remove(which, l, mid, tree[rt].l);
    else
        remove(which, mid + 1, r, tree[rt].r);
    pushup(rt);
    if (!tree[rt].l && !tree[rt].r) { //左右两边都空了
        clean(rt);
        rt = 0;
    }
}
int ask_sum(int L, int R, int l, int r, int rt) {
    if (!rt)
        return 0;
    if (L <= l && r <= R)
        return tree[rt].sum;
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid)
        ans += ask_sum(L, R, l, mid, tree[rt].l);
    if (R > mid)
        ans += ask_sum(L, R, mid + 1, r, tree[rt].r);
    return ans;
}
int ask_mx(int L, int R, int l, int r, int rt) {
    if (!rt)
        return 0;
    if (L <= l && r <= R)
        return tree[rt].mx;
    int mid = (l + r) >> 1, mx = 0;
    if (L <= mid)
        mx = max(mx, ask_mx(L, R, l, mid, tree[rt].l));
    if (R > mid)
        mx = max(mx, ask_mx(L, R, mid + 1, r, tree[rt].r));
    return mx;
}
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
void dfs1(int at) {
    sz[at] = 1;
    for (int i = head[at]; i; i = sxd[i].next) {
        if (!depth[sxd[i].to]) {
            depth[sxd[i].to] = depth[at] + 1;
            fa[sxd[i].to] = at;
            dfs1(sxd[i].to);
            sz[at] += sz[sxd[i].to];
            if (sz[sxd[i].to] > sz[son[at]])
                son[at] = sxd[i].to;
        }
    }
}
void dfs2(int at, int f) {
    if (son[at]) {
        top[son[at]] = top[at];
        mp[son[at]] = ++g;
        dfs2(son[at], at);
    }
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == f || sxd[i].to == son[at])
            continue;
        top[sxd[i].to] = sxd[i].to;
        mp[sxd[i].to] = ++g;
        dfs2(sxd[i].to, at);
    }
}
void change1(int x, int y) {
    remove(mp[x], 1, n, root[c[x]]);
    c[x] = y;
    insert(mp[x], w[x], 1, n, root[c[x]]);
}
void change2(int x, int y) {
    w[x] = y;
    insert(mp[x], w[x], 1, n, root[c[x]]);
}
void find_sum(int x, int y) {
    int zj = c[x], s = 0;
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        s += ask_sum(mp[top[x]], mp[x], 1, n, root[zj]);
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
        swap(x, y);
    s += ask_sum(mp[x], mp[y], 1, n, root[zj]);
    write(s);
    puts("");
}
void find_mx(int x, int y) {
    int zj = c[x], s = 0;
    while (top[x] != top[y]) {
        if (depth[top[x]] < depth[top[y]])
            swap(x, y);
        s = max(s, ask_mx(mp[top[x]], mp[x], 1, n, root[zj]));
        x = fa[top[x]];
    }
    if (depth[x] > depth[y])
        swap(x, y);
    s = max(s, ask_mx(mp[x], mp[y], 1, n, root[zj]));
    write(s);
    puts("");
}
signed main() {
    n = read(), m = read();
    for (register int i = 1; i <= n; i++)
        w[i] = read(), c[i] = read();
    for (register int i = 1; i < n; i++) {
        x = read(), y = read();
        add(x, y);
        add(y, x);
    }
    depth[1] = mp[1] = top[1] = 1;
    dfs1(1);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        insert(mp[i], w[i], 1, n, root[c[i]]);
    }
    while (m--) {
        scanf("%s", ch);
        x = read(), y = read();
        if (ch[0] == 'C') {
            if (ch[1] == 'C')
                change1(x, y);
            if (ch[1] == 'W')
                change2(x, y);
        }
        if (ch[0] == 'Q') {
            if (ch[1] == 'S')
                find_sum(x, y);
            if (ch[1] == 'M')
                find_mx(x, y);
        }
    }
    return 0;
}
