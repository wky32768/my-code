/*
����ͼ��̬�滮�� 
��f [u][i], g[u][i]�ֱ��ʾ�Ƿ���ڴ�1��n�ĳ���Ϊi��·��һ ��·������ 
����һ����u �� v��f [v][i] | = f [u][i ? cost(u, v)]�� 
ʱ�临�Ӷ�O(e * edge value)��
*/
#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=250;
const int M=11000;
vector <int> q[N];
int n,m,a,b,c,d,f[N][M],g[N][M],w1[N][N],w2[N][N],ru[N];
queue <int> xd;
void solve() {
	For(i,1,n) if(ru[i]==0) xd.push(i);
	f[1][0]=g[1][0]=1;
	while(!xd.empty()) {
		int now=xd.front();
		xd.pop();
		For(i,0,(int)q[now].size()-1) {
			int ano=q[now][i];
			for(int j=0;j+w1[now][ano]<=10005;j++) f[ano][j+w1[now][ano]]|=f[now][j];
			for(int j=0;j+w2[now][ano]<=10005;j++) g[ano][j+w2[now][ano]]|=g[now][j];
			ru[ano]--;
			if(ru[ano]==0) xd.push(ano);
		}
	}	
}
signed main() {
	cin>>n>>m;
	while(m--) {
		cin>>a>>b>>c>>d;
		q[a].push_back(b);
		w1[a][b]=c;
		w2[a][b]=d;
		ru[b]++;
	}
	solve();
	For(i,1,10001) if(f[n][i] && g[n][i]) return cout<<i,0;
	puts("IMPOSSIBLE");
}
