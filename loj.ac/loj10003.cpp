#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, ans[120000], l, r, tot1, tot2, xx[120000], yy[120000];
struct node {
    int x, y, mn, id;
} a[120000];
bool cmp(node a, node b) { return a.mn < b.mn; }
signed main() {
    cin >> n;
    For(i, 1, n) {
        a[i].id = i;
        cin >> a[i].x;
        xx[i] = a[i].x;
    }
    For(i, 1, n) {
        cin >> a[i].y;
        yy[i] = a[i].y;
        a[i].mn = min(a[i].x, a[i].y);
    }
    sort(a + 1, a + n + 1, cmp);
    l = 1, r = n;
    For(i, 1, n) {
        if (a[i].mn == a[i].x) {
            ans[l] = a[i].id;
            l++;
        } else if (a[i].mn == a[i].y) {
            ans[r] = a[i].id;
            r--;
        }
    }
    For(i, 1, n) {
        tot1 += xx[ans[i]];
        tot2 = max(tot2, tot1);
        tot2 += yy[ans[i]];
    }
    cout << tot2 << '\n';
    For(i, 1, n - 1) cout << ans[i] << " ";
    cout << ans[n];
    return 0;
}
