#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
struct node {
    int l, r, sz, cnt, dat, w;
} a[N << 2];
int tot;
int make(int val) {
    a[++tot].w = val;
    a[tot].dat = rand();
    a[tot].sz = a[tot].cnt = 1;
    return tot;
}
void upd(int rt) { a[rt].sz = a[a[rt].l].sz + a[a[rt].r].sz; }
void build() {
    make(-0x3f3f3f3f);
    make(0x3f3f3f3f);
    a[1].r = 2;
    upd(1);
}
int get_rank_by_val(int rt, int val) {
    if (!rt)
        return 0;
    if (val == a[rt].w)
        return a[a[rt].l].sz + 1;
    if (a[a[rt].l].w > val)
        return get_rank_by_val(a[rt].l, val);
    else
        return get_rank_by_val(a[rt].r, val) + a[a[rt].l].sz + a[rt].cnt;
}
int get_val_by_rank(int rt, int rank) {
    if (!rt)
        return 0x3f3f3f3f;
    if (a[a[rt].l].sz >= rank)
        return get_val_by_rank(a[rt].l, rank);
    if (a[a[rt].l].sz + a[rt].cnt >= rank)
        return a[rt].w;
    return get_val_by_rank(a[rt].r, rank - a[a[rt].l].sz - a[rt].cnt);
}
void zig(int &p) {
    int q = a[p].l;
    a[p].l = a[q].r;
    a[q].r = p;
    p = q;
}
void zag(int &p) {
    int q = a[p].r;
    a[p].r = a[q].l;
    a[q].l = p;
    p = q;
}
void insert(int &rt, int val) {
    if (!rt) {
        rt = make(val);
        return;
    }
    if (a[rt].w == val) {
        a[rt].cnt++;
        upd(rt);
        return;
    }
    if (val < a[rt].w) {
        insert(a[rt].l, val);
        if (a[a[rt].l].dat > a[rt].dat)
            zig(rt);
    } else {
        insert(a[rt].r, val);
        if (a[a[rt].r].dat > a[rt].dat)
            zag(rt);
    }
    upd(rt);
}
int pre(int val) {
    int ans = 1, at = 1;
    while (at) {
        if (a[at].w == val) {
            if (a[at].l) {
                at = a[at].l;
                while (a[at].r)
                    at = a[at].r;
                ans = at;
            }
            break;
        }
        if(a[at].w>a[ans].w && a[at].w<val) ans=at;
        at=a[at].w>val?a[at].l:a[at].r;
    }
}
signed main() {}