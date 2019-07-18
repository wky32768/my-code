#include <bits/stdc++.h>
#include <stdio.h>

#define maxN 25//最大顶点数，这里是s[i]
#define inf 0x7fffffff
#define cout std::cout

struct Edge {
	int v, w, next;
} edge[maxN * 30]; //边

//using namespace std;

int edgeNum;//边总数
int dis[maxN];//最长路径中的dis[i]代表远点到i的最长距离
int r[maxN];//r[i]标示i时刻至少需要多少人
int num[maxN];//num[i]标示i时刻开始工作的人
bool vis[maxN];//标示i是否进入队列
int preEdge[maxN];//同一个起点的上一条边
int cnt[maxN];//入队列的次数
int queue[maxN * 30];//模拟队列
int n;//输入的n

void addEdge(int u, int v, int w) { //添加新边
//	cout<<"add "<<u<<" "<<v<<" "<<w<<'\n';
	edge[edgeNum].v = v;
	edge[edgeNum].w = w;
	edge[edgeNum].next = preEdge[u];//以u为起点的上一条边
	preEdge[u] = edgeNum ++;
}

int spfa(int ans) { //spfa算法实现
	int head = 0, tail = 1;

	for (int i = 0; i <= 24; ++ i) {
		dis[i] = -inf;
		vis[i] = false;
		cnt[i] = 0;
	}
	queue[0] = 0;
	dis[0] = 0;
	while (head < tail) {
		int u = queue[head];
		int p = preEdge[u];
		vis[u] = true;
//		cout<<"now:"<<u<<'\n';
		while (p != -1) {
			int v = edge[p].v, w = edge[p].w;
			if (dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					vis[v] = true;
					queue[tail] = v;
					tail ++;

				}
				if(++cnt[v] > 24) {
					return 0;
				}

			}
			p = edge[p].next;
		}
		head ++;
		vis[u] = false;
//		for(int i=0;i<=n;i++) cout<<dis[i]<<" ";
//		puts("");
	}
	if (dis[24] == ans) {
		return 1;
	}
	return 0;
}

void buildGraph(int ans) { //建图这也是本题目的关键，建模。。。。
	edgeNum = 0;
	for (int i = 0; i <= 24; ++ i) {
		preEdge[i] = -1;
	}
	addEdge(0,24,ans);
	for(int i = 1; i <= 24; ++i) {
		addEdge(i - 1,i,0);
		addEdge(i,i - 1,-num[i]);
	}
	for(int i = 1; i <= 8; ++i)
		addEdge(i + 16,i,r[i] - ans);
	for(int i = 9; i <= 24; ++i)
		addEdge(i - 8,i,r[i]);
}

int main() { //主函数
//	freopen("std.out","w",stdout);
	int	cases;
	scanf("%d", &cases);
	while (cases --) {
		bool flag = false;;
		for (int i = 1; i <= 24; ++ i) {
			scanf("%d", &r[i]);
			num[i] = 0;
		}
		scanf("%d", &n);
		int t;
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &t);
			num[t + 1] ++;
		}
		for (int i = 0; i <= 24; ++ i) {
			buildGraph(i);
			if (spfa(i) == 1) {
				flag = true;
				printf("%d\n", i);
				break;
			}
		}
		if (!flag) {
			printf("No Solution\n");
		}
	}
	return 0;
}
