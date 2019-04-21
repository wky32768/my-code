#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d[50][50], e[50][50];
bool flag;
char ch[12];
int floyd() {
    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= 26; j++)
            e[i][j] = d[i][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                e[i][j] |= e[i][k] & e[k][j];
                if (e[i][j] == e[j][i] && e[i][j] != 0 && i != j)
                    return -1; //产生矛盾勒
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (e[i][j] == e[j][i] && e[i][j] == 0 && i != j)
                return 0; //还有的无法判断
    return 1;             //可以全部判断
}
signed main() {
    while (cin >> n >> m && n) {
        memset(d, 0, sizeof d);
        flag = 1;
        for (int i = 1; i <= m; i++) {
            cin >> ch;
            d[ch[0] - 'A' + 1][ch[2] - 'A' + 1] = 1;
            if (flag) {
                int now = floyd();
                if (now == -1) {
                    printf("Inconsistency found after %d relations.\n", i);
                    flag = 0;
                } else if (now == 1) {
                    printf("Sorted sequence determined after %d relations: ", i);
                    pair<int, char> ans[50];
                    for (int j = 1; j <= n; j++) {
                        ans[j].first = 0;
                        ans[j].second = j + 'A' - 1;
                    }
                    //非常巧妙的做法，记录下比每一个字母大的个数，然后倒序输出
                    for (int j = 1; j <= n; j++)
                        for (int k = 1; k <= n; k++)
                            if (e[j][k])
                                ans[j].first++;
                    sort(ans + 1, ans + n + 1);
                    for (int j = n; j >= 1; j--)
                        cout << ans[j].second;
                    puts(".");
                    flag = 0;
                }
            }
        }
        if (flag)
            puts("Sorted sequence cannot be determined.");//直到最后都没有判断出来
    }
    return 0;
}