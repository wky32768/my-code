#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, m, a[120000], s[120000], l, r, tot, ans;
bool ok(int x) {
    int tot = 0, at = 1;
    For(i, 1, n) if (s[i] - s[at - 1] >= x) {
        at = i;
        tot++;
    }
    return tot >= m;
}
signed main() {
    cin >> n >> m;
    For(i, 1, n) {
        cin >> a[i];
        tot += a[i];
        r=max(r,a[i]);
        s[i] = s[i - 1] + a[i];
    }
    l = tot;
    while (l >= r) {
        int mid = (l + r) >> 1;
        if (ok(mid)) {
            ans = mid;
            r = mid + 1;
        } else
            l = mid - 1;
    }
    cout<<(ans==0?r:ans);
    return 0;
}