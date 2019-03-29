//把a[i]-b[i]佐为背包的价值，然后01背包
//没调出来，不知道为什么
#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, suma, sumb, cnt, tot, f[25][801], d[230][25][801], a[1200], b[1200];
vector <int> ans;
void out(int i, int j, int k) {
    if (!j)
        return;
    int last = d[i][j][k];
    out(last - 1, j - 1, k - (a[last] - b[last]));
    ans.push_back(last);
    suma += a[last], sumb += b[last];
}
void solve() {
    f[0][400] = 0; //避免负数
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= 800; k++)
                d[i][j][k] = d[i - 1][j][k];
        for (int j = m;j; j--)
            for (int k = 0; k <= 800; k++) {
                if (k - (a[i] - b[i]) < 0 || k - (a[i] - b[i]) > 800)
                    continue; //肯定不行，防RE
                if (f[j][k] < f[j - 1][k - (a[i] - b[i])] + a[i] + b[i]) { //注意F中维护的是和的最大值
                    f[j][k] = f[j - 1][k - (a[i] - b[i])] + a[i] + b[i];
                    d[i][j][k] = i;
                }
            }
    }
    tot=0;
    for(int k=0;k<=400;k++) {
        if(f[m][k+400]>=0 && f[m][k+400]>=f[m][400-k]) {//绝对值，要判断向上还是向下，答案的方案是相同的。看顺序可知，找到第一个直接退出即可。
            tot=k+400;
            break;
        }
        if(f[m][400-k]>=0) {
            tot=400-k;
            break;
        }
    }
    ans.clear();
    suma = sumb = 0;
    out(n, m, tot);
    printf("Jury #%d\n", ++cnt);
    printf("Best jury has value %d for prosecution and value %d for defence:\n",suma, sumb);
    for(int i=0;i<(int)ans.size();i++) cout<<" "<<ans[i];
    puts("\n");
}
signed main() {
    // freopen("in.in","r",stdin);
    // freopen("out.out","w",stdout);
    while (scanf("%lld%lld", &n, &m) && n) {
		memset(f, -0xcf, sizeof(f));
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &a[i], &b[i]);
        }
        solve();
    }
}