#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
#define lowbit(x) (x & (-x))
using namespace std;
const int NN = 230000;
int N, n, m, cnt, tree[NN], ans[NN];
struct data {
    int a, b, c, s, ans;
} a[NN], p[NN];
bool cmp1(data a, data b) {
    if (a.a == b.a && a.b == b.b)
        return a.c < b.c;
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}
bool cmp2(data a, data b) {
    if (a.b == b.b)
        return a.c < b.c;
    return a.b < b.b;
}
void upd(int x, int C) {
    for (int i = x; i <= m; i += lowbit(i))
        tree[i] += C;
}
int tot(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
void cdq(int l, int r) {
    /*cdq分治:先分治，再把前面l~mid的贡献加入后面的答案中*/
    /*不能直接排序，如1,3,2与2,1,3无法比较*/
    /*所以第一个排序只能排x，第二个排血只能排y*/
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(p + l, p + mid + 1, cmp2);
    sort(p + mid + 1, p + r + 1, cmp2);
    int i = l, j = mid + 1;
    while (j <= r) {
        /*加入贡献*/
        while (i <= mid && p[i].b <= p[j].b) {
            /*因为是分开排的序，所以要重新判断大小*/
            /*因为还有c的影响，所以放入树状数组求多少个小于*/
            upd(p[i].c, p[i].s);
            i++;
        }
        p[j].ans += tot(p[j].c);
        j++;
    }
    For(j, l, i - 1) upd(p[j].c, -p[j].s);
    /*还原树状数组(在知道操作了以后肯定是这样更快啊，什么memset根本比不了啊)*/
}
signed main() {
    scanf("%lld%lld", &N, &m);
    // For(i, 1, N) scanf("%lld%lld%lld", &a[i].a, &a[i].b, &a[i].c);
    for (int i = 1; i <= N; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    sort(a + 1, a + N + 1, cmp1);
    For(i, 1, N) {
        cnt++;
        if (a[i].a != a[i + 1].a || a[i].b != a[i + 1].b ||
            a[i].c != a[i + 1].c) {
            p[++n] = a[i];
            p[n].s = cnt;
            cnt = 0;
        }
    }
    cdq(1, n);
    For(i, 1, n) ans[p[i].ans + p[i].s - 1] += p[i].s;
    /*在p[i].s这一段中的答案就是在第一个之前(小于)的答案加上有几个跟他相等的个数，再减去他自己*/
    For(i, 0, N - 1) cout << ans[i] << '\n';
    return 0;
}
