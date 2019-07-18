#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, a[5500], ans, rev[5500], all, tot, mn = 0x3f3f3f3f, mnat;
char ch;
bool ok(int x) {
    memset(rev, 0, sizeof rev);
    all = 0, tot = 0;
    For(i, 1, n - x + 1) {
        if ((a[i] + all) % 2 == 1) {
            rev[i] = 1;
            tot++;
        }
        all += rev[i];
        if (i - x + 1 >= 1)
            all -= rev[i - x + 1];
    }
    if (tot > mn)
        return 0;
    For(i, n - x + 2, n) {
        if ((a[i] + all) % 2 == 1)
            return 0;
        if (i - x + 1 >= 1)
            all -= rev[i - x + 1];
    }
    return 1;
}
signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> ch;
        a[i] = (ch == 'F' ? 0 : 1);
    }
    For(i, 1, n) {
        if (ok(i) && tot < mn) {
            mn = tot;
            mnat = i;
        }
    }
    cout << mnat << " " << mn << '\n';
    return 0;
}