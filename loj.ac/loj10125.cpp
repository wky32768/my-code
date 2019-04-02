#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
using namespace std;
int c[1200000], n, m, opt, x, y;
void change(int at, int x) {
    for (int i = at; i <= n; i += lowbit(i)) c[i] += x;
}
int tot(int at) {
    int ans = 0;
    for (int i = at; i; i -= lowbit(i)) ans += c[i];
    return ans;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        change(i, x);
    }
    while (m--) {
        cin >> opt >> x >> y;
        if (opt == 1) {
            change(x, y);
        } else
            cout << tot(y) - tot(x - 1) << '\n';
    }
    return 0;
}