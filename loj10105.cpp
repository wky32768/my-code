#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 360000;
struct node {
	int next, to, w;
} sxd[N << 1];
int n, m, opt, x, y, tot, head[N], cnt = 1, ru[N], chu[N], ans[N];
/*关于cnt:如代码中所示，vis是用【i>>1】来统计计算的 ，所以一对应该是像“2,3”这样的对*/
int read() {
	int f = 0;
	char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) ch = getchar();
	while (ch >= '0' && ch <= '9') {
		f = f * 10 + ch - '0';
		ch = getchar();
	}
	return f;
}
void write(int x) {
	if (x < 0) {
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
bool vis[N];
void add(int u, int v) {
	sxd[++cnt].next = head[u];
	sxd[cnt].to = v;
	head[u] = cnt;
}
void dfs(int x) {
	for (int &i = head[x]; i; i = sxd[i].next) {
		//这个&号，如果使用就只能跑一次 
		int j=i;
		if(vis[j>>1]) continue;
		vis[j >> 1] = 1;
		dfs(sxd[i].to);
		ans[++tot] = j;
	}
}
/*套圈法：在大环里找到的小环先放入答案，然后再把大环继续补完*/
signed main() {
	scanf("%lld%lld%lld", &opt, &n, &m);
	for (int i = 1; i <= m; i++) {
		x = read(), y = read();
		add(x, y);
		if (opt==1) {
			add(y, x);
			ru[x]++, ru[y]++;
		} else {
			cnt++;
			chu[x]++, ru[y]++;
		}
	}
	if (opt==1) {
		for (register int i = 1; i <= n; i++)
			if ((ru[i] + chu[i])&1)
				return puts("NO"), 0;
	} else {
		for (register int i = 1; i <= n; i++)
			if (ru[i] != chu[i])
				return puts("NO"), 0;
	} /*欧拉回路判断的基本条件*/
	dfs(x);
	if (tot != m)
		return puts("NO"), 0;
	puts("YES");
	for (register int i = tot; i >= 1; i--) {
		write(ans[i] & 1 ? (-(ans[i] >> 1)) : (ans[i] >> 1)); /*根据cnt的值倒推出读进来的时候是哪条边 */
		putchar(' ');
	}
	/*倒序输出？请手推一下dfs的过程*/
	return 0;
}