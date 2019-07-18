#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;
const int N = 100005;
int read() {
	int x = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
struct node {
	int l, r, w, rnd, same, sz;
} a[N];
int n, rt, tot, opt, x;
int xin(int val) {
	a[++tot].w = val;
	a[tot].rnd = rand();
	a[tot].same = a[tot].sz = 1;
	return tot;
}
void upd(int x) {
	a[x].sz = a[a[x].l].sz + a[a[x].r].sz + a[x].same;
}
void build() {
	xin(-0x3f3f3f3f);
	xin(0x3f3f3f3f);
	rt = 1;
	a[1].r = 2;
	upd(1);
}
int rnk(int x, int val) {
	if (!x) return 0;
	if (a[x].w == val) return a[a[x].l].sz + 1;
	else if (a[x].w > val) return rnk(a[x].l, val);
	return a[a[x].l].sz + a[x].same + rnk(a[x].r, val);
}
int val(int x, int rnk) {
	if (!x) return 0x3f3f3f3f;
	if (a[a[x].l].sz >= rnk) return val(a[x].l, rnk);
	if (a[a[x].l].sz + a[x].same >= rnk) return a[x].w;
	return val(a[x].r, rnk - a[a[x].l].sz - a[x].same);
}
void zig(int &p) {
	int q = a[p].l;
	a[p].l = a[q].r;
	a[q].r = p;
	p = q;
	upd(a[p].r);
	upd(p);
}
void zag(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l;
	a[q].l = p;
	p = q;
	upd(a[p].l);
	upd(p);
}
void insert(int &x, int val) {
	if (!x) {x = xin(val);return;}
	if (a[x].w == val) {
		a[x].same++;
		upd(x);
		return;
	}
	if (a[x].w > val) {
		insert(a[x].l, val);
		if (a[a[x].l].rnd > a[x].rnd) zig(x);
	} else {
		insert(a[x].r, val);
		if (a[a[x].r].rnd > a[x].rnd) zag(x);
	}
	upd(x);
}
int pre(int val) {
	int ans = 1, now = rt;
	while (now) {
		if (a[now].w == val) {
			if (a[now].l>0) {
				now = a[now].l;
				while (a[now].r>0)
					now = a[now].r;
				ans = now;
			}
			break;
		}
		if (a[now].w < val && a[now].w > a[ans].w) ans = now;
		if (a[now].w > val) now = a[now].l;
		else now = a[now].r;
	}
	return a[ans].w;
}
int nxt(int val) {
	int ans = 2, now = rt;
	while (now) {
		if (a[now].w == val) {
			if (a[now].r>0) {
				now = a[now].r;
				while (a[now].l>0)
					now = a[now].l;
				ans = now;
			}
			break;
		}
		if (a[now].w > val && a[now].w < a[ans].w) ans = now;
		if (a[now].w > val) now = a[now].l;
		else now = a[now].r;
	}
	return a[ans].w;
}
void del(int &x, int val) {
	if (!x) return;
	if (a[x].w == val) {
		if (a[x].same>1) {
			a[x].same--;
			upd(x);
			return;
		}
		if (a[x].l || a[x].r) {
			if (a[x].r == 0 || a[a[x].r].rnd < a[a[x].l].rnd) {
				zig(x);
				del(a[x].r, val);
			} else {
				zag(x);
				del(a[x].l, val);
			}
			upd(x);
		} else x = 0;
		return;
	}
	if (a[x].w > val) del(a[x].l, val);
	else del(a[x].r, val);
	upd(x);
}
signed main() {
	srand((int)time(0));
	n = read();
	build();
	while (n--) {
		opt = read();
		x=read();
		if (opt == 1) {insert(rt, x);} 
		else if (opt == 2) {del(rt, x);} 
		else if (opt == 3) {write(rnk(rt, x) - 1);puts("");} 
		else if (opt == 4) {write(val(rt, x+1));puts("");} 
		else if (opt == 5) {write(pre(x));puts("");} 
		else if (opt == 6) {write(nxt(x));puts("");}
	}
	return 0;
}
