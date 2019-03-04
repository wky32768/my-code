#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
queue <int> q;
struct AC {
	int tree[1200000][27],val[1200000],fail[1200000],cnt;
	void insert(char *ch) {
		int len=strlen(ch),at=0;
		for(int i=0; i<len; i++) {
			if(!tree[at][ch[i]-'a']) tree[at][ch[i]-'a']=++cnt;
			at=tree[at][ch[i]-'a'];
		}
		val[at]++;
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
			at=tree[at][ch[i]-'a'];
			for(int j=at; j&&(val[j]!=-1); j=fail[j]) ans+=val[j],val[j]=-1;
		}
		return ans;
	}
} ac;
int n,t;
char ch[1200000];
signed main() {
	cin>>t;
	while(t--) {
		memset(ac.tree,0,sizeof ac.tree);
		memset(ac.fail,0,sizeof ac.fail);
		memset(ac.val,0,sizeof ac.val);
		scanf("%lld",&n);
		For(i,1,n) cin>>ch,ac.insert(ch);
		ac.build();
		cin>>ch;
		cout<<ac.query(ch)<<'\n';
	}
	return 0;
}

