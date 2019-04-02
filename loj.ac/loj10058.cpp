#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
queue <int> q;
//先搜索AC自动机，找到每个子节点是否找到，然后倒序搜索 
int n,m,t,point[120000];
char ch[120000][120],s[1200000];
struct AC {
	int tree[1200000][27],val[1200000],fail[1200000],cnt,fa[1200000];
	void insert(char *ch,int w) {
		int len=strlen(ch),at=0;
		for(int i=0; i<len; i++) {
			if(!tree[at][ch[i]-'A']) {
				tree[at][ch[i]-'A']=++cnt;
				fa[cnt]=at;
			}
			at=tree[at][ch[i]-'A'];
		}
		val[at]++;
		point[w]=at;
	}
	void build() {
		for(int i=0; i<26; i++) if(tree[0][i]) fail[tree[0][i]]=0,q.push(tree[0][i]);
		while(!q.empty()) {
			int at=q.front();
			q.pop();
			for(int i=0; i<26; i++) {
				if(tree[at][i]) fail[tree[at][i]]=tree[fail[at]][i],q.push(tree[at][i]);
				else tree[at][i]=tree[fail[at]][i];//这句相当于简化操作，可以提高效率
			}
		}
	}
	int query(char *ch) {
		int len=strlen(ch),at=0,ans=0;
		for(int i=0; i<len; i++) {
			at=tree[at][ch[i]-'A'];
			for(int j=at; j&&(val[j]!=-1); j=fail[j]) ans+=val[j],val[j]=-1;
		}
		return ans;
	}
	void make(char *ch) {
		int len=strlen(ch),at=0;
		for(int i=0; i<len; i++) {
			at=tree[at][ch[i]-'A'];
			for(int j=at; j&&(val[j]!=-1); j=fail[j]) val[j]=-1;
		}
	}
	int find(int w) {
		int len=strlen(ch[w]),at=0;
		for(int i=point[w],ans=strlen(ch[w]); i; i=fa[i],ans--) if(val[i]==-1) return ans;
		return 0;
	}
} ac;
signed main() {
	cin>>n>>m>>s;
	for(int i=1; i<=m; i++) cin>>ch[i],ac.insert(ch[i],i);
	ac.build();
	ac.make(s);
	for(int i=1; i<=m; i++) cout<<ac.find(i)<<'\n';
	return 0;
}
