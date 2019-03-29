#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define next(a, b) b == 9 ? dfs(a + 1, 1) : dfs(a, b + 1)
using namespace std;
int score, flag, ans[12][12], x, b[12][12], r[12][12], l[12][12], g[12][12];
inline bool ok(const register int x, const register int y,
               const register int k) {
    if (r[x][k] || l[y][k] || g[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][k])
        return 0;
    b[x][y] = k;
    ans[x][y] = k;
    r[x][k] = l[y][k] = g[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][k] = 1;
    return 1;
}
inline void del(const register int x, const register int y,
                const register int k) {
    b[x][y] = 0;
    ans[x][y] = 0;
    r[x][k] = l[y][k] = g[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][k] = 0;
}
inline void dfs(const register int x, const register int y) {
    if (x == 10 && y == 1) {
        if (flag)
            return;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << b[i][j];
            }
            puts("");
        }
        flag = 1;
        return;
    }
    if(flag) return;
    if (b[x][y]) {
        next(x, y);
        return;
    }
    For(i, 1, 9) {
        register int old = score;
        if (ok(x, y, i)) {
            next(x, y);
            del(x, y, i);
            score = old;
        }
    }
    return;
}
int t, cnt;
signed main() {
    cin >> t;
    for (int now = 1; now <= t; now++) {
        flag = 0;
        memset(ans, 0, sizeof ans);
        memset(b, 0, sizeof b);
        memset(r, 0, sizeof r);
        memset(l, 0, sizeof l);
        memset(g, 0, sizeof g);
        for (int i = 1; i <= 9; i++) {
            char ch[12];
            scanf("%s", ch);
            for (int j = 0; j <= 8; j++)
                if (ch[j] != '0') {
                    ok(i, j + 1, ch[j] - '0');
                }
            // getchar();
        }
        dfs(1, 1);
    }
    return 0;
}