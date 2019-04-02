#include <bits/stdc++.h>
#define int long long
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
queue<pair<int, int> > q;
int n, m, d[1200][1200];
char ch[1200][1200];
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", ch[i] + 1);
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ch[i][j] == '1') {
                q.push(make_pair(i,j));
                d[i][j]=0;
            }
    while(!q.empty()) {
        pair <int,int> now=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int xx=now.first+dx[i],yy=now.second+dy[i];
            if(xx<1 || xx>n || yy<1 || yy>m) continue;
            if(d[xx][yy]>d[now.first][now.second]+1) {
                d[xx][yy]=min(d[xx][yy],d[now.first][now.second]+1);
                q.push(make_pair(xx,yy));
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) cout<<d[i][j]<<" ";
        puts("");
    }
    return 0;
}