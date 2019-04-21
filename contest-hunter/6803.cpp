/*大概思路：把每一座塔的每一发子弹当做一个点，然后对限定时间能达到的怪物连边，跑二分图匹配的时候必须把每一个怪都达到（即都能匹配）*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt, t2, t,girl[120000];
bool vis[120000];
double ans, t1,v;
pair<int, int> a[120000], b[120000];
pair<int, double> c[120000];
vector<int> sxd[1200];
double dis(pair<int, int> a, pair<int, int> b) {
    int xx=a.first-b.first,yy=a.second-b.second;
    return sqrt(xx*xx+yy*yy);
}
bool find(int x) {
    for (int i = 0; i < (int)sxd[x].size(); i++) {
        int now = sxd[x][i];
        if (vis[now])
            continue;
        vis[now] = 1;
        if (!girl[now] || find(girl[now])) {
            girl[now] = x;
            return 1;
        }
    }
    return 0;
}
bool ok(double x) {
    memset(girl, 0, sizeof girl);
    for (int i = 1; i <= m; i++) {
        sxd[i].clear();
        for (int j = 1; j <= t; j++)
            if (c[j].second + dis(a[i], b[c[j].first]) / v <= x) {
                sxd[i].push_back(j);
            }
    }
    for (int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof vis);
        if (!find(i))
            return 0;
    }
    return 1;
}
signed main() {
    cin >> n >> m >> t1 >> t2 >> v;
    t = n * m;
    t1 /= 60;
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++)
        cin >> b[i].first >> b[i].second;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int which = (i - 1) * n + j; //第几发子弹,在第几个炮塔
            c[which].first = j;
            c[which].second = (i - 1) * (t1 + t2) + t1;
        }
    double l = t1, r = 100000;
    while (l + 1e-8 < r) {
        double mid = (l + r) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.6lf", l);
    return 0;
}
