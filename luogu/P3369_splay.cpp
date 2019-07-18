#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 1200000;
struct node {
    int fa, ch[2], sz, same, w;
} t[N];
int root = 1, n, m, l, r, tot;
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
    // sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + same[x]; //sz别忘了加上自己
    t[x].sz = t[t[x].ch[0]].sz + t[t[x].ch[1]].sz + t[x].w;
}
void rotate(int x, int &k) { //k目标位置
    //自己画图还是非常好理解的
    int y = t[x].fa, z = t[y].fa, which_son = (t[y].ch[0] == x ? 0 : 1);
    if (y == k)
        k = x; //旋转以后目标换人了
    else {
        // if (ch[z][0] == y)
        // ch[z][0] = x;
        // else
        // ch[z][1] = x; //上一任交接
        if (t[z].ch[0] == y)
            t[z].ch[0] = z;
        else
            t[z].zh[1] = x;
    }
    // ch[y][which_son] = ch[x][which_son ^ 1];
    // fa[ch[y][which_son]] = y;
    // ch[x][which_son ^ 1] = y;
    // fa[y] = x, fa[x] = z;
    t[y].ch[which_son] = t[x].ch[which_son ^ 1];
    t[t[y].ch[which_son]].fa = y;
    t[x].ch[which_son ^ 1] = y;
    t[y].fa = x, t[x].fa = z;
    upd(x), upd(y);
}
void splay(int x, int &k) { //k的意思同上
    while (x != k) {
        // int y = fa[x], z = fa[y];
        int y = t[x].fa, z = t[y].fa;
        if (y != k) { //如果只有一格，就不需要分类讨论了
            // if ((ch[y][0] == x) ^ (ch[z][0] == y))
            if ((t[y].ch[0] == x) ^ (t[z].ch[0] == y))
                rotate(x, k);
            else //在同一条直线上,从父节点开始旋转
                rotate(y, k);
        }
        rotate(x, k); //其实跟前面有重复，不过懒了。。其实可以直接全部分类讨论，这样有些就不用做两遍了
    }
}
void insert(int x) {
    int now = root, sxd = root;
    while (now && t[now].w != x) {
        sxd = now;
        now = t[now].ch[t[now].w > x ? 1 : 0];
    }
    if (now)
        t[now].same++;
    else {
        now = ++tot;
        if (sxd)
            t[sxd].ch[t[sxd].w > x ? 1 : 0] = now;
        t[now].fa = sxd;
        t[now].w = x;
        t[now].same = t[now].sz = 1;
    }
    splay(sxd, root) //转转保平安（
}
void find(int x) {
    int now = root;
    while (t[now].w != x && t[now].ch[t[now].w < x ? 0 : 1])
        now = t[now].ch[t[now].w < x ? 0 : 1];
    splay(now, root);
}
int nxt(int x, int sxd) { //sxd:1前0后
    find(x);              //查找x的位置(Splay操作到根节点)
    int now = root;
    if ((t[now].w > x && sxd) || (t[now].w < x && !sxd))
        return now;
    now = t[now].ch[sxd];
    while (t[now].ch[sxd ^ 1])
        now = t[now].ch[sxd ^ 1];
    return now;
}
void del(int x) {
    int lst = nxt(x, 0), nex = nxt(x, 1);
    splay(lst, root);
    splay(nex, lst);
}
signed main() {

    return 0;
}
