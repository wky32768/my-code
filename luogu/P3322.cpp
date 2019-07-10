#include <bits/stdc++.h>
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int n, w[120][120], shu[120], a, b, tot, now;
vector<int> ans;
bool ok(int x) {
    for (int i = 0; i < (int)ans.size(); i++) {
        if (w[x][ans[i]] == 0)
            return 0;
    }
    return 1;
}
signed main() {
    srand((int)time(0));
    cin >> n;
    while (cin >> a >> b) {
        w[a][b] = w[b][a] = 1;
    }
    For(i, 1, n) shu[i] = i;
    For(i, 1, 100000) {
        random_shuffle(shu + 1, shu + n + 1);
        ans.clear();
        now = 0;
        For(i, 1, n) if (ok(shu[i])) {
            ans.push_back(shu[i]);
            now++;
        }
        tot = max(tot, now);
    }
    cout << tot;
}