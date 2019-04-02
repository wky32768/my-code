#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, t, act, ans, use[12][12];
char ch[12], make[12][12];
struct mat {
	int w[120][120];
} sxd[120], last;
mat cheng(mat a, mat b) {
	mat ans;
	memset(ans.w, 0, sizeof ans.w);
	for (int i = 0; i <= 70; i++)
		for (int j = 0; j <= 70; j++) {
			for (int k = 0; k <= 70; k++) {
				ans.w[i][j] += a.w[i][k] * b.w[k][j];
			}
		}
	return ans;
}
int num(int x, int y) {
	return (x - 1) * m + y;
}
mat ksm(mat a, int b) {
	mat ans;
	memset(ans.w, 0, sizeof ans.w);
	for (int i = 0; i <= 70; i++)
		ans.w[i][i] = 1;
	while (b) {
		if (b & 1)
			ans = cheng(ans, a);
		b >>= 1;
		a = cheng(a, a);
	}
	return ans;
}
signed main() {
	scanf("%lld%lld%lld%lld", &n, &m, &t, &act);
	for (int i = 1; i <= n; i++) {
		scanf("%s", ch + 1);
		for (int j = 1; j <= strlen(ch + 1); j++)
			use[i][j] = ch[j] - '0';
	}
	for (int i = 0; i < act; i++) {
		scanf("%s", make[i] + 1);
	}
	for (register int i = 1; i <= 60; i++) {	
		sxd[i].w[0][0] = 1;
		for (register int j = 1; j <= n; j++)
			for (register int k = 1; k <= m; k++) {
				int which = use[j][k];
				char c=make[which][(i-1) % strlen(make[which]+1)+1];
				if (c== 'N' && j > 1)
					sxd[i].w[num(j, k)][num(j - 1, k)] = 1;
				if (c == 'S' && j < n)
					sxd[i].w[num(j, k)][num(j + 1, k)] = 1;
				if (c == 'W' && k > 1)
					sxd[i].w[num(j, k)][num(j, k - 1)] = 1;
				if (c == 'E' && k < m)
					sxd[i].w[num(j, k)][num(j, k + 1)] = 1;
				if (c >= '0' && c <= '9') {
					sxd[i].w[0][num(j, k)] = c - '0';
					sxd[i].w[num(j, k)][num(j, k)] = 1;
				}
			}
	}
	last=sxd[1];
	for (int i = 2; i <= 60; i++) {
		last = cheng(last, sxd[i]);
	}
	last = ksm(last, t / 60);
	t %= 60;
	for (int i = 1;i<=t; i++)
		last = cheng(last, sxd[i]);
	for(int i=1; i<=n*m; i++)ans=max(ans,last.w[0][i]);
	cout<<ans;
	return 0;
}
