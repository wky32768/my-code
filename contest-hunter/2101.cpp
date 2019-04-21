//求出拓扑序后从后往前递推
#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int n, m, cnt, head[32000], x, y, ru[32000], pu[32000], tot;
bitset<32000> c[32000];
struct node {
    int next, to;
} sxd[240000];
void add(int u, int v) {
    sxd[++cnt].next = head[u];
    sxd[cnt].to = v;
    head[u] = cnt;
}
queue<int> q;
void tuopu() {
    for (int i = 1; i <= n; i++)
        if (ru[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        pu[++tot] = now;
        cout << "now=" << now << '\n';
        for (int i = head[now]; i; i = sxd[i].next) {
            ru[sxd[i].to]--;
            if (ru[sxd[i].to] == 0)
                q.push(sxd[i].to);
        }
    }
}
void solve() {
    for (int i = tot; i >= 1; i--) {
        int x = pu[i];
        // cout<<"x="<<x<<'\n';
        c[x][x] = 1;
        for (int j = head[x]; j; j = sxd[j].next) {
            c[x] |= c[sxd[j].to];
        }
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        ru[y]++;
    }
    tuopu();
    solve();
    for (int i = 1; i <= n; i++)
        cout << c[i].count() << '\n';
    return 0;
}