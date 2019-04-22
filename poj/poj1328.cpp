#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    int x, y;
    double l, r;
} sxd[120000];
int n, r, ans, cnt, x, y;
double pos;
bool cmp(node a, node b) { return a.l < b.l; }
void solve() {
    pos = -0x3f3f3f3f;
    ans = 0;
    bool flag=1;
    for (int i = 1; i <= n; i++)
        if (abs(sxd[i].y) > r) {
            flag=0;
            break;
        }
    if(!flag) {
        printf("Case %lld: %lld\n", cnt, -1ll);
        return;
    }
    for (int i = 1; i <= n; i++) {
        double length = sqrt((double)r * r - (double)sxd[i].y * sxd[i].y);
        sxd[i].l = sxd[i].x - length;
        sxd[i].r = sxd[i].x + length;
    }
    sort(sxd + 1, sxd + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (pos + 1e-8 < sxd[i].l) {
            ans++;
            pos = sxd[i].r;
        } else {
            pos = min(sxd[i].r, pos); //为了监控i必须做出牺牲
        }
    }
    printf("Case %lld: %lld\n", cnt, ans);
    return;
}
signed main() {
    while (scanf("%lld%lld", &n, &r) != EOF && n) {
        cnt++;
        for (int i = 1; i <= n; i++)
            cin >> sxd[i].x >> sxd[i].y;
        solve();
    }
    return 0;
}