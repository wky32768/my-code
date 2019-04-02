#include <bits/stdc++.h>
#define int long  long
using namespace std;
int trie[1200000][30],val[1200000];
int n,m,cnt;
char ch[1200000];
void insert(char *ch) {
	int n=strlen(ch),at=0;
	for(int i=0;i<n;i++) {
		int now=ch[i]-'a';
		if(!trie[at][now]) trie[at][now]=++cnt;
		at=trie[at][now];
	}
	val[at]++;
}
int search(char *ch) {
	int n=strlen(ch),at=0,ans=0;
	for(int i=0;i<n;i++) {
		int now=ch[i]-'a';
		ans+=val[at];
		at=trie[at][now];
		if(!at) return ans;
	}
	ans+=val[at];
	return ans;
}
signed main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>ch;
		insert(ch);
	}
	for(int i=1;i<=m;i++) {
		cin>>ch;
		cout<<search(ch)<<'\n';
	}
	return 0;
}