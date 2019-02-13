#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int n,ans[120000],cnt;
inline int read() {
    register int x = 0, f = 1;
    register char ch = getchar();
    while (!(ch >= '0' && ch <= '9')) {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
struct node {
    int last,id;
    friend bool operator < (node a,node b) {
        return a.last>b.last;
    }
};
struct yyh {
    int which,start,end;
} cow[120000];
bool cmp(yyh a,yyh b) {
    return a.start<b.start;
}
void write(int x) {
    if(x>=10) write(x/10);
    char ch='0'+x%10;
    putchar(ch);
}
priority_queue <node> q;
priority_queue <node> old;
signed main() {
    cin>>n;
    For(i,1,n) {
        cow[i].start=read();
        cow[i].end=read();
        cow[i].which=i;
    }
    sort(cow+1,cow+n+1,cmp);
    For(i,1,n) {
    	if(!q.empty()) { 
        	node at=q.top();
        	if(at.last<cow[i].start) {
        		ans[cow[i].which]=at.id;
        		q.pop();
        		q.push((node) {cow[i].end,at.id});
        		continue;
        	}
        }
        ans[cow[i].which]=++cnt;
        q.push((node) {cow[i].end,cnt});
    }
    cout<<cnt<<'\n';
    For(i,1,n) {
        write(ans[i]);
        puts("");
    }
    return 0;
}