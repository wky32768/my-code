#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
int read() {
	int x = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch))
		f |= (ch == '-'), ch = getchar();
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
void write(int x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 5200000;
struct node {
	int ls, rs, w;
} tree[N];
int root[N], n, m, a[N], b[N], nn, tot, l, r, k;
int build(int l, int r) {
	int now = ++tot;
	if (l == r) {
		return now;
	}
	int mid = (l + r) >> 1;
	tree[now].ls = build(l, mid);
	tree[now].rs = build(mid + 1, r);
	return now;
}
int insert(int rt, int l, int r, int which) {
	int now = ++tot,mid=(l+r)>>1;
	tree[now] = tree[rt];
	if (l == r) {
		tree[now].w++;
		return now;
	}
	if (which <= mid)
		tree[now].ls = insert(tree[rt].ls, l, mid, which);
	else
		tree[now].rs = insert(tree[rt].rs, mid + 1, r, which);
	tree[now].w = tree[tree[now].ls].w + tree[tree[now].rs].w; //明确：tree中是这一段有几个不同的数
	return now;
}
int solve(int a1, int a2, int l, int r, int k) {
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	int left_tot = tree[tree[a2].ls].w - tree[tree[a1].ls].w;
	if (left_tot >= k)
		return solve(tree[a1].ls, tree[a2].ls, l, mid, k);
	else
		return solve(tree[a1].rs, tree[a2].rs, mid + 1, r, k-left_tot);
}

signed main() {
	n = read(), m = read();
	For(i, 1, n) {
		a[i] = read();
		b[i] = a[i];
	}
	nn=n;
	sort(b + 1, b + nn + 1);
	nn = unique(b + 1, b + nn + 1) - (b + 1);
	root[0] = build(1, nn);
	For(i, 1, n) {
		int x = lower_bound(b + 1, b + nn + 1, a[i]) - b;
		root[i] = insert(root[i - 1], 1, nn, x);
	}
	while (m--) {
		l = read(), r = read(), k = read();
		write(b[solve(root[l-1],root[r],1, nn, k)]);
		puts("");
	}
	return 0;
}
