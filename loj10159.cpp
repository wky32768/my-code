#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt, x, y, tot, head[1200000], mx[1200000], sec[1200000], depth[1200000], len[1200000], rt, d;
struct node {
    int next, to;
} sxd[2400000];
set<int> a;
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
void find(int at, int f) {
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == f)
            continue;
        find(sxd[i].to, at);
        if (mx[sxd[i].to] + 1 > mx[at]) {
            sec[at] = mx[at];
            mx[at] = mx[sxd[i].to] + 1;
        } else if (mx[sxd[i].to] + 1 > sec[at]) {
            sec[at] = mx[sxd[i].to] + 1;
        }
    }
    d = max(d, mx[at] + sec[at]);
}
void ok(int at, int f, int len) {  //剩下的长度用来搜索
    a.insert(at);
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == f)
            continue;
        if (mx[sxd[i].to] == len - 1)
            ok(sxd[i].to, at, len - 1);  //继续的点一定+1以后是当前所剩的长度
    }
}
void dfs(int at, int f) {
    if (mx[at] + sec[at] == d) {
        ok(at, f, mx[at]);
        ok(at, f, sec[at]);  //处于某个最长链的根节点，进入输出程序
    }
    for (int i = head[at]; i; i = sxd[i].next) {
        if (sxd[i].to == f)
            continue;
        dfs(sxd[i].to, at);
    }
}
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld", &x, &y);
        x++, y++;
        add(x, y);
        add(y, x);
    }
    find(1, 0);
    dfs(1, 0);
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) cout << (*it - 1) << '\n';
    return 0;
}