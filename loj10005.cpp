#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node1 {
    int x;
    friend bool operator<(node1 a, node1 b) { return a.x > b.x; }
};
struct node2 {
    int x;
    friend bool operator<(node2 a, node2 b) { return a.x < b.x; }
};
priority_queue<node1> a;
priority_queue<node2> b;
int n, zero;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push((node1){ x });
        b.push((node2){ x });
    }
    cin >> zero;
    for (int i = 1; i < n; i++) {
        node1 x = a.top();
        a.pop();
        node1 y = a.top();
        a.pop();
        x.x = x.x * y.x + 1;
        a.push(x);
        node2 xx = b.top();
        b.pop();
        node2 yy = b.top();
        b.pop();
        xx.x = xx.x * yy.x + 1;
        b.push(xx);
    }
    cout << a.top().x - b.top().x;
    return 0;
}
