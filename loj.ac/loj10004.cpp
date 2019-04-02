#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int m, n, at = 1, tot = 0;
bool vis[120000];
struct node {
    int date, money;
} a[120000];
bool cmp(node x, node y) { return x.money > y.money; }
signed main() {
    cin >> m >> n;
    For(i, 1, n) cin >> a[i].date;
    For(i, 1, n) cin >> a[i].money;
    sort(a + 1, a + n + 1, cmp);
    For(i, 1, n) {
        int flag = 0;
        for (register int j = a[i].date; j >= 1; j--)
            if (!vis[j]) {
                flag = 1;
                vis[j] = 1;
                break;
            }
        if (!flag)
            tot += a[i].money;
    }
    cout << m - tot;
    return 0;
}
/*
10000
7
4 2 4 3 1 4 6
70 60 50 40 30 20 10
*/
