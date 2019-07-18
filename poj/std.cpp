#include <bits/stdc++.h>
#include <stdio.h>

#define maxN 25//��󶥵�����������s[i]
#define inf 0x7fffffff
#define cout std::cout

struct Edge {
	int v, w, next;
} edge[maxN * 30]; //��

//using namespace std;

int edgeNum;//������
int dis[maxN];//�·���е�dis[i]����Զ�㵽i�������
int r[maxN];//r[i]��ʾiʱ��������Ҫ������
int num[maxN];//num[i]��ʾiʱ�̿�ʼ��������
bool vis[maxN];//��ʾi�Ƿ�������
int preEdge[maxN];//ͬһ��������һ����
int cnt[maxN];//����еĴ���
int queue[maxN * 30];//ģ�����
int n;//�����n

void addEdge(int u, int v, int w) { //����±�
//	cout<<"add "<<u<<" "<<v<<" "<<w<<'\n';
	edge[edgeNum].v = v;
	edge[edgeNum].w = w;
	edge[edgeNum].next = preEdge[u];//��uΪ������һ����
	preEdge[u] = edgeNum ++;
}

int spfa(int ans) { //spfa�㷨ʵ��
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

void buildGraph(int ans) { //��ͼ��Ҳ�Ǳ���Ŀ�Ĺؼ�����ģ��������
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

int main() { //������
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
