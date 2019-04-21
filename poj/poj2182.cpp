//用从后往前的顺序判断前面的第a[i]+1个数
#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
using namespace std;
int tree[520000], n, a[520000], ans[520000];
void add(int x, int C) {
    for (int i = x; i <= n; i += lowbit(i))
        tree[i] += C;
}
int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        add(i, 1);
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--) {
        int l = 1, r = n, now = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ask(mid) >= a[i] + 1) {
                now = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans[i] = now;
        add(ans[i], -1);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}