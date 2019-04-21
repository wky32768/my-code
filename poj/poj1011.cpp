/*简单搜索，注意剪枝的优化*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[120], v[120], len, cnt, sum, val;
bool cmp(int a, int b) { return a > b; }
bool dfs(int which, int now, int last) { //第几根，现在长度，上一根
    if (which > cnt)
        return 1;
    if (now == len)
        return dfs(which + 1, 0, 1);
    int fail = 0;
    for (int i = last; i <= n; i++) {
        if (!v[i] && now + a[i] <= len && a[i] != fail) {
            v[i] = 1;
            if (dfs(which, now + a[i], i + 1))
                return 1;
            fail = a[i];
            v[i] = 0;
            if (now == 0 || now == len)
                return 0;
        }
    }
    return 0;
}
signed main() {
    while (scanf("%lld", &n) != EOF && n != 0) {
        sum = val = 0;
        for (register int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i], val = max(val, a[i]);
        }
        sort(a + 1, a + n + 1, cmp);
        for (len = val; len <= sum; len++) {
            if (sum % len != 0)
                continue;
            cnt = sum / len;
            memset(v, 0, sizeof v);
            if (dfs(1, 0, 1))
                break;
        }
        cout << len << '\n';
    }
    return 0;
}