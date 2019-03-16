#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, now;
char ch[1200000];
stack<char> q;
signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    q.push(ch[1]);
    for (int i = 1; i <= n; i++) {
        if (!q.empty() && (ch[i] == q.top() + 1 || ch[i] == q.top() + 2)) {
            now += 2;
            q.pop();
            ans = max(ans, now);
            continue;
        }
        if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{')
            q.push(ch[i]);
        else {
            now = 0;
            while (!q.empty())
                q.pop();
        }
    }
    cout << ans;
    return 0;
}