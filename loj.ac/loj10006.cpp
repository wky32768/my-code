#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[120000], at, ans;
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        at += a[i];
        if (at > m) {
            at = a[i];
            ans++;
        }
    }
    if (at)
        ans++;
    cout << ans;
}
