#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 1200000;
int fa[N], ch[N][2], sz[N], rev[N], root, n, m, l, r;
int read() {
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
void upd(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; //sz别忘了加上自己
}
void pushdown(int x) {
    if (rev[x]) {
        swap(ch[x][0], ch[x][1]);
        rev[ch[x][0]] ^= 1;
        rev[ch[x][1]] ^= 1;
        rev[x] = 0;
    }
}
void rotate(int x, int &k) { //k目标位置
    //自己画图还是非常好理解的
    int y = fa[x], z = fa[y], which_son = (ch[y][0] == x ? 0 : 1);
    if (y == k)
        k = x; //旋转以后目标换人了
    else {
        if (ch[z][0] == y)
            ch[z][0] = x;
        else
            ch[z][1] = x; //上一任交接
    }
    ch[y][which_son] = ch[x][which_son ^ 1];
    fa[ch[y][which_son]] = y;
    ch[x][which_son ^ 1] = y;
    fa[y] = x, fa[x] = z;
    upd(x), upd(y);
}
void splay(int x, int &k) { //k的意思同上
    while (x != k) {
        int y = fa[x], z = fa[y];
        if (y != k) { //如果只有一格，就不需要分类讨论了
            if ((ch[y][0] == x) ^ (ch[z][0] == y))
                rotate(x, k);
            else //在同一条直线上,从父节点开始旋转
                rotate(y, k);
        }
        rotate(x, k); //其实跟前面有重复，不过懒了。。其实可以直接全部分类讨论，这样有些就不用做两遍了
    }
}
void build(int rt, int l, int r) {
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    ch[rt][(mid < rt ? 0 : 1)] = mid;
    fa[mid] = rt;
    sz[mid] = 1;
    if (l == r)
        return;
    build(mid, l, mid - 1);
    build(mid, mid + 1, r); //注意这里和线段树不大一样，应为mid已经放在树上了
    upd(mid);
}
int find(int x, int k) {
    pushdown(x);
    int tot = sz[ch[x][0]];
    if (k == tot + 1)
        return x; //不要忘了根上的x
    if (k <= tot)
        return find(ch[x][0], k);
    else
        return find(ch[x][1], k - sz[ch[x][0]] - 1);
}
void rever(int l, int r) {
    int x = find(root, l), y = find(root, r + 2); //是把l-1和r+1都加了1（因为有保底的两个点）
    splay(x, root);
    splay(y, ch[x][1]); //用splay把l,r中间的塞成一颗树
    rev[ch[y][0]] ^= 1;
}
signed main() {
    n = read(), m = read();
    root = (n + 2 + 1) / 2;
    build(root, 1, n + 2);
    For(i, 1, m) {
        l = read(), r = read();
        rever(l, r);
    }
    For(i, 2, n + 1) {
        write(find(root, i) - 1);
        putchar(' ');
    }
    return 0;
}
