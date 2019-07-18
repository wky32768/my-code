#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define get(x) (x < 0 ? 0 : fib[x])
using namespace std;
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
const int N = 200005;
const int mod = 1000000000;
struct node {
    int x, y, len;
} t[N << 2];
int n, m, fib[N], sum[N], add[N << 2], a[N], opt, x, y, z;
void pre() {
    fib[0] = fib[1] = sum[0] = 1;
    For(i, 2, n) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    For(i, 1, n) sum[i] = (sum[i - 1] + fib[i]) % mod;
}
void up(int rt) {
    //矩阵乘方以后
    //[fib(n-2),fib(n-1)]
    //[fib(n-1),fib(n)]
    t[rt].len = (t[rt << 1].len + t[rt << 1 | 1].len) % mod;
    //把后一个乘上再加上前面的
    t[rt].x = (t[rt << 1].x + t[rt << 1 | 1].x * get(t[rt << 1].len - 2) + t[rt << 1 | 1].y * get(t[rt << 1].len - 1)) % mod;
    t[rt].y = (t[rt << 1].y + t[rt << 1 | 1].x * get(t[rt << 1].len - 1) + t[rt << 1 | 1].y * get(t[rt << 1].len)) % mod;
}
void down(int rt, int l, int r) {
    if (add[rt]) {
        add[rt << 1] = (add[rt << 1] + add[rt]) % mod;
        add[rt << 1 | 1] = (add[rt << 1 | 1] + add[rt]) % mod;
        t[rt << 1].x = (t[rt << 1].x + add[rt] * sum[t[rt << 1].len - 1]) % mod;
        //左移以为即可(把f[0]的1当做第一项)
        //所以计算要sum[..]-1(第一组：1,1,2,3,第二组:1,2,3,5),sum[0]=1,sum[1]=2,sum[2]=4,sum[3]=7
        t[rt << 1 | 1].x = (t[rt << 1 | 1].x + add[rt] * sum[t[rt << 1 | 1].len - 1]) % mod;
        t[rt << 1].y = (t[rt << 1].y + add[rt] * (sum[t[rt << 1].len] - 1)) % mod;
        //对照上面的找规律可得,因为下面的sum多了一个f[0]带来的1
        t[rt << 1 | 1].y = (t[rt << 1 | 1].y + add[rt] * (sum[t[rt << 1 | 1].len] - 1)) % mod;
        add[rt] = 0;
    }
}
void build(int rt, int l, int r) {
    if (l == r) {
        t[rt].x = t[rt].y = a[l]%mod;
        t[rt].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
    up(rt);
}
void change(int L, int R, int l, int r, int rt) {
    if (l == r) {
        t[rt].x = t[rt].y = R % mod;
        t[rt].len = 1;
        add[rt] = 0;
        return; //全部重来
    }
    down(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid)
        change(L, R, l, mid, rt << 1);
    else
        change(L, R, mid + 1, r, rt << 1 | 1);
    up(rt);
}
int ask(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        int len = l - x; //补足跟询问上界的差距
        if (len == 0)
            return t[rt].x; //不用补足
        else
            return t[rt].x * get(len - 2) + t[rt].y * get(len - 1); //详见up函数里的解释
    }
    down(rt, l, r);
    int mid = (l + r) >> 1, now = 0;
    if (L <= mid)
        now = (now + ask(L, R, l, mid, rt << 1)) % mod;
    if (R > mid)
        now = (now + ask(L, R, mid + 1, r, rt << 1 | 1)) % mod;
    return now;
}
void upd(int L, int R, int C, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] = (add[rt] + C) % mod;
        //下面与down里的更新相同
        t[rt].x = (t[rt].x + sum[r - l + 1 - 1] * C) % mod;
        t[rt].y = (t[rt].y + (sum[r - l + 1] - 1) * C) % mod;
        return;
    }
    down(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid)
        upd(L, R, C, l, mid, rt << 1);
    if (R > mid)
        upd(L, R, C, mid + 1, r, rt << 1 | 1);
    up(rt);
}
signed main() {
    n = read(), m = read();
    pre();
    For(i, 1, n) a[i] = read();
    build(1, 1, n);
    while (m--) {
        opt = read();
        if (opt == 1) {
            x = read(), y = read();
            change(x, y, 1, n, 1);
        } else if (opt == 2) {
            x = read(), y = read();
            cout << ask(x, y, 1, n, 1) << '\n';
        } else if (opt == 3) {
            x = read(), y = read(), z = read();
            upd(x, y, z, 1, n, 1);
        }
    }
}