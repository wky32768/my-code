#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5][5], ans[20], mn=0x3f3f3f3f, xin[5][5];
char ch[5][5];
void dfs(int at) {
//	cout<<"dfs "<<at<<'\n';
	if (at == 17) {
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				xin[i][j] = a[i][j];
//        for(int i=1;i<=16;i++) cout<<ans[i]<<' ';
//        puts("");
		for (int i = 1; i <= 16; i++)
			if (ans[i] == 1) {
				int x = (i%4==0?i/4:i/4+1);
				int y = (i % 4 == 0 ? 4: i%4);
//                cout<<x<<" "<<y<<'\n';
				if (x - 1 >= 1)
					xin[x - 1][y] = 3 - xin[x - 1][y];
				if (y - 1 >= 1)
					xin[x][y - 1] = 3 - xin[x][y - 1];
				xin[x][y] = 3 - xin[x][y];
				if (x + 1 <= 4)
					xin[x + 1][y] = 3 - xin[x + 1][y];
				if (y + 1 <= 4)
					xin[x][y + 1] = 3 - xin[x][y + 1];
			}
		int he = 0;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				he += xin[i][j];
		if (he == 16 || he == 32) {
			int zong = 0;
			for (int i = 1; i <= 4; i++)
				for (int j = 1; j <= 4; j++)
					if(ans[(i-1)*4+j]==1) zong++;
			mn = min(mn, zong);
		}
		return;
	}
	ans[at] = 1;
	dfs(at + 1);
	ans[at] = 0;
	dfs(at + 1);
}
signed main() {
	for (int i = 1; i <= 4; i++) {
		scanf("%s", ch[i] + 1);
		for (int j = 1; j <= 4; j++)
			a[i][j] = (ch[i][j] == 'b' ? 1 : 2);
	}
	dfs(1);
	if(mn>=16) cout<<"Impossible";
	else cout << mn;
	return 0;
}
