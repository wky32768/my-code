//这里使用了lowbit来优化当前的方案，存入二进制数后可以用Lowbit搜索每一位。所以这说不定就是除了某d开头算法外数独较快的解法了吧。
#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
char ch[12][12];
int hang[12], lie[12], gong[12], cnt[1200], num[1200], tot;
int get(int x, int y) { return (x / 3) * 3 + y / 3; }
void flip(int x, int y, int z) {
    hang[x] ^= (1 << z);
    lie[y] ^= (1 << z);
    gong[get(x, y)] ^= (1 << z);
    return;
}
bool dfs(int now) {
    if (!now)
        return 1;
    int mn = 10, x, y;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (ch[i][j] != '.')
                continue;
            int val = hang[i] & lie[j] & gong[get(i, j)];
            if (!val)
                return 0; //矛盾，回退
            if (cnt[val] < mn) {
                mn = cnt[val];
                x = i, y = j;
            }
        }
    int val = hang[x] & lie[y] & gong[get(x, y)];
    for (int i = val; i; i -= lowbit(i)) {
        int which = num[lowbit(i)];
        ch[x][y] = '1' + which;
        flip(x, y, which);
        if (dfs(now - 1))
            return 1;
        flip(x, y, which);
        ch[x][y] = '.';
    }
    return 0;
}
char yyh[12000];
signed main() {
    for (int i = 0; i < (1 << 9); i++)
        for (int j = i; j; j -= lowbit(j))
            cnt[i]++; //有几个1
    for (int i = 0; i < 9; i++)
        num[1 << i] = i;
    while (scanf("%s", yyh) && yyh[0] != 'e') {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                ch[i][j] = yyh[i * 9 + j];
        for(int i=0;i<9;i++) hang[i]=lie[i]=gong[i]=(1<<9)-1;
        tot=0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (ch[i][j]!='.') flip(i,j,ch[i][j]-'1');
                else tot++;
        dfs(tot);
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) cout<<ch[i][j];
        puts("");
    }
    return 0;
}