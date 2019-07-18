#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 120000;
int n, m, k, a[N], kuai, ans[N], cnt[N];
struct node {
    int l, r, id, which;
    friend bool operator<(node a, node b) {
        if (a.which != b.which)
            return a.which < b.which;
        else
            return a.r < b.r;
    }
} ask[N];
signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    kuai = sqrt(n);
    for (int i = 1; i <= m; i++) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].id = i;
        ask[i].which = (ask[i].l - 1) / kuai + 1;
    }
    sort(ask + 1, ask + m + 1);
    int l = 1, r = 0, now = 0;
    for (int i = 1; i <= m; i++) {
        while (ask[i].l < l) {
            l--;
            now += 2 * (cnt[a[l]]) + 1;
            cnt[a[l]]++;
        }
        while (ask[i].r > r) {
            r++;
            now += 2 * (cnt[a[r]]) + 1;
            cnt[a[r]]++;
        }
        while (ask[i].l > l) {
            cnt[a[l]]--;
            now -= 2 * cnt[a[l]] + 1;
            l++;
        }
        while (ask[i].r < r) {
            cnt[a[r]]--;
            now -= 2 * cnt[a[r]] + 1;
            r--;
        }
        ans[ask[i].id] = now;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}