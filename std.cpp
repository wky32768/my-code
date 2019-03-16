#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAXN 100010
using namespace std;
int n, m, d = 1, e = 1, g = 1;
int c[MAXN], w[MAXN], root[MAXN];
int head[MAXN], id[MAXN], top[MAXN], deep[MAXN], fa[MAXN], son[MAXN], num[MAXN];
struct node1 { //�ṹ��ǰ����
    int next, to;
} a[MAXN << 1];
struct node2 { //��̬�߶���
    int l, r, data1, data2;
} b[MAXN * 20];
inline int read() { //�����Ķ���
    int date = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-')
            w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        date = date * 10 + c - '0';
        c = getchar();
    }
    return date * w;
}
inline int max(const int &x, const int &y) { //��д max ,�о��е��ֲС�����
    if (x > y)
        return x;
    return y;
}
void pushup(int rt) { //�ϴ�
    b[rt].data1 = b[b[rt].l].data1 + b[b[rt].r].data1;
    b[rt].data2 = max(b[b[rt].l].data2, b[b[rt].r].data2);
}
void pushdown(int rt) { //���
    b[rt].data1 = b[rt].data2 = b[rt].l = b[rt].r = 0;
}
void insert(int k, int v, int l, int r, int &rt) { //����
    int mid;
    if (!rt)
        rt = e++; //���� ��3��
    if (l == v && v == r) {
        b[rt].data1 = b[rt].data2 = k;
        return;
    }
    mid = l + r >> 1;
    if (v <= mid)
        insert(k, v, l, mid, b[rt].l);
    else
        insert(k, v, mid + 1, r, b[rt].r);
    pushup(rt);
}
void remove(int k, int l, int r, int &rt) { //ɾ��
    int mid;
    if (l == r) {
        pushdown(rt);
        rt = 0;
        return;
    }
    mid = l + r >> 1;
    if (k <= mid)
        remove(k, l, mid, b[rt].l);
    else
        remove(k, mid + 1, r, b[rt].r);
    pushup(rt);
    if (!b[rt].l && !b[rt].r) { //ע����������� �� ������ ����ʱ���ڵ�Ϊ��
        pushdown(rt);
        rt = 0;
    }
}
int query1(int s, int t, int l, int r, int rt) { //�������
    if (!rt)
        return 0; //�ڵ�Ϊ�գ�����
    int mid;
    if (l == s && r == t)
        return b[rt].data1;
    mid = l + r >> 1;
    if (t <= mid)
        return query1(s, t, l, mid, b[rt].l);
    else if (s > mid)
        return query1(s, t, mid + 1, r, b[rt].r);
    else
        return query1(s, mid, l, mid, b[rt].l) +
               query1(mid + 1, t, mid + 1, r, b[rt].r);
}
int query2(int s, int t, int l, int r, int rt) { //��������ֵ
    if (!rt)
        return 0;
    int mid;
    if (l == s && r == t)
        return b[rt].data2;
    mid = l + r >> 1;
    if (t <= mid)
        return query2(s, t, l, mid, b[rt].l);
    else if (s > mid)
        return query2(s, t, mid + 1, r, b[rt].r);
    else
        return max(query2(s, mid, l, mid, b[rt].l),
                   query2(mid + 1, t, mid + 1, r, b[rt].r));
}
void add(int x, int y) { //�ӱ�
    a[d].to = y;
    a[d].next = head[x];
    head[x] = d++;
    a[d].to = x;
    a[d].next = head[y];
    head[y] = d++;
}
void buildtree(int rt) { //����+����׼��1
    int will;
    num[rt] = 1;
    for (int i = head[rt]; i; i = a[i].next) {
        will = a[i].to;
        if (!deep[will]) {
            deep[will] = deep[rt] + 1;
            fa[will] = rt;
            buildtree(will);
            num[rt] += num[will];
            if (num[will] > num[son[rt]])
                son[rt] = will;
        }
    }
}
void dfs(int rt, int fa) { //����׼��2
    if (son[rt]) {
        top[son[rt]] = top[rt];
        id[son[rt]] = ++g;
        dfs(son[rt], rt);
    }
    int v;
    for (int i = head[rt]; i; i = a[i].next) {
        v = a[i].to;
        if (v == fa || v == son[rt])
            continue;
        top[v] = v;
        id[v] = ++g;
        dfs(v, rt);
    }
}
void change1(int x, int y) { //�޸��ڽ̣�ԭ�ڽ���ɾ�������ڽ��в���
    remove(id[x], 1, n, root[c[x]]);
    c[x] = y;
    insert(w[x], id[x], 1, n, root[c[x]]);
}
void change2(int x, int y) { //�޸����ۣ�ֱ�Ӳ���
    w[x] = y;
    insert(w[x], id[x], 1, n, root[c[x]]);
}
void work1(int x, int y) { //�����ۺ�
    int cs = c[x], s = 0;
    while (top[x] != top[y]) { //���ʸ���
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        s += query1(id[top[x]], id[x], 1, n, root[cs]);
        x = fa[top[x]];
    }
    if (deep[x] > deep[y])
        swap(x, y);
    s += query1(id[x], id[y], 1, n, root[cs]); //��Ҫ�����������
    printf("%d\n", s);
}
void work2(int x, int y) { //��������ֵ
    int cs = c[x], s = 0;
    while (top[x] != top[y]) { //ͬ��
        if (deep[top[x]] < deep[top[y]])
            swap(x, y);
        s = max(s, query2(id[top[x]], id[x], 1, n, root[cs]));
        x = fa[top[x]];
    }
    if (deep[x] > deep[y])
        swap(x, y);
    s = max(s, query2(id[x], id[y], 1, n, root[cs]));
    printf("%d\n", s);
    exit(0);
}
int main() {
	freopen("2195.in","r",stdin);
	freopen("2195_2.out","w",stdout);
    int x, y;
    char ch[3];
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        w[i] = read();
        c[i] = read();
    }
    for (int i = 1; i < n; i++) {
        x = read();
        y = read();
        add(x, y);
    }
    deep[1] = id[1] = top[1] = 1; //��ֵ
    buildtree(1);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        insert(w[i], id[i], 1, n, root[c[i]]); //����ʼ�߶���
    while (m--) { //������
        scanf("%s", ch);
        x = read();
        y = read();
        if (ch[0] == 'C') {
            if (ch[1] == 'C')
                change1(x, y);
            if (ch[1] == 'W')
                change2(x, y);
        }
        if (ch[0] == 'Q') {
            if (ch[1] == 'S')
                work1(x, y);
            if (ch[1] == 'M')
                work2(x, y);
        }
    }
    return 0;
}
