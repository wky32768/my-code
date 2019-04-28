/*
用sg函数做，还套了个记忆化
切成两半以后，返回的sg值就是两个数的异或。如果有两个必胜，用掉一个，别人再用一个，你就是两个必败了
注意点：为什么要从2开始枚举？
因为如果是1了，先手必胜(非（1,1），可是我的初始化没有设置这种情况，就会出现-1
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int sg[230][230], x, y, tong[1200];
bool vis[230][230];
int find(int x, int y) {
    if(sg[x][y]!=-1) return sg[x][y];
    memset(tong, 0, sizeof tong);
    for (int i = 2; i <= x-i; i++)
        tong[(find(i, y)) ^ (find(x - i, y))]=1;
    for (int i = 2; i <= y-i; i++)
        tong[(find(x, i)) ^ (find(x, y - i))]=1;
    for (int i = 0; i < 1200; i++)
        if (!tong[i]) {
            sg[x][y] = i;
            return i;
        }
}
signed main() {
    memset(sg,-1,sizeof sg);
    sg[2][2] = sg[2][3] = sg[3][2] = 0;
    while (scanf("%lld%lld", &x, &y) != EOF) {
        if (!find(x, y))
            puts("LOSE");
        else
            puts("WIN");
    }
    return 0;
}
/*200 200*/
