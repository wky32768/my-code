//破环为链，然后维护，注意负数与负数，负数与正数的特殊情况
#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, ans = -0x3f3f3f3f, mx[120][120], mn[120][120], a[120];
char ch[120];
signed main() {
    scanf("%lld", &n);
    For(i, 1, n) {
        cin>>ch[i]>>a[i];
        a[i + n] = a[i];
        ch[i + n] = ch[i];
    }
    memset(mx, 0xcf, sizeof mx);
    memset(mn, 0x3f, sizeof mn);
    For(i, 1, n << 1) mx[i][i] = mn[i][i] = a[i];
    For(len, 2, n) for (int l = 1; l + len - 1 <= n * 2; l++) {
        int r = l + len - 1;
        for (int k = l + 1; k <= r; k++)
            if (ch[k] == 't') {
                mx[l][r] = max(mx[l][r], mx[l][k - 1] + mx[k][r]);
                mn[l][r] = min(mn[l][r], mn[l][k - 1] + mn[k][r]);
            } else {
                mx[l][r] = max(mx[l][r], max(mx[l][k - 1] * mx[k][r],
                                             mn[l][k - 1] * mn[k][r]));
                mn[l][r] = min(
                    mn[l][r],
                    min(min(mx[l][k - 1] * mx[k][r], mn[l][k - 1] * mn[k][r]),
                        min(mn[l][k - 1] * mx[k][r], mx[l][k - 1] * mn[k][r])));
            }
    }
    For(i, 1, n) ans = max(ans, mx[i][i + n - 1]);
    printf("%lld\n", ans);
    For(i, 1, n) if (ans == mx[i][i + n - 1]) printf("%d ", i);
    return 0;
}