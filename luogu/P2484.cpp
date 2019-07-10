/* 
n=4,m=3
1 2 2 1
1 2 2 1
1 2 2 1
*/

#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, m, a[120][120], test[120][120], ans1, ans2, tot, ans = 0x3f3f3f3f;
bool ok(int r, int c) {
    For(i, 1, n) For(j, 1, m) test[i][j] = a[i][j];
    For(i, 1, n) For(j, 1, m) if (test[i][j]) {
        if (i + r - 1 <= n && j + c - 1 <= m) {
            int jian = test[i][j];
            For(k, 0, r - 1) For(l, 0, c - 1) {
                test[i + k][j + l] -= jian;
                if (test[i + k][j + l] < 0)
                    return 0;
            }
        } else
            return 0;
    }
    return 1;
}
signed main() {
    cin >> n >> m;
    For(i, 1, n) For(j, 1, m) {
        cin >> a[i][j];
        tot += a[i][j];
    }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--) {
            if (tot % (i * j) == 0 && tot / (i * j) < ans)
                if (ok(i, j))
                    ans = min(ans, tot / (i * j));
        }
    cout << ans;
    return 0;
}
