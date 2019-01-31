#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    int x, y;
} a[1200000];
bool cmp(node a, node b) {
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}
inline int read() {
    register int x = 0;
    register char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
int n, at, ans;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].x = read();
        a[i].y = read();
    }
    sort(a + 1, a + n + 1, cmp);
    for (register int i = 1; i <= n; i++)
        if (a[i].x >= at) {
            at = a[i].y;
            ans++;
        }
    cout << ans;
}
