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
const int N = 1200000;
int n, ans,a[N],yue[N],gg[N];//gg存下所有可能为Gcd答案的数
unsigned long long rnd() {
	static unsigned long long i = (19260817) ^ ((int)(time(0))), j;
	i = i * i;
	i = i / 100000;
	i = i % 10000000000;
	j = i / 10000;
	return j;
}
void solve() {
    int haha=rnd();
    int which=a[haha%n+1],cnt=0;
    for(int i=1;i*i<=which;i++) if(which%i==0) {
        yue[++cnt]=i;
        if(i*i!=which) yue[++cnt]=which/i;
    }
    sort(yue+1,yue+cnt+1);
    // For(i,1,cnt) cout<<yue[i]<<" ";
    // puts("");
    memset(gg,0,sizeof gg);//不要忘了清零！
    For(i,1,n) {
        int now=__gcd(a[i],which);
        gg[lower_bound(yue+1,yue+cnt+1,now)-yue]++;
    }
    For(i,1,cnt) For(j,i+1,cnt) if(yue[j]%yue[i]==0) gg[i]+=gg[j];
    /*这句话可以这么理解：如果被6整除，一定能被2和3整除,所以被2整除的数要加上所有偶数的答案*/
    For(i,1,cnt) if(gg[i]*2>=n) ans=max(ans,yue[i]);
}
signed main() {
    srand((int)time(0));
    n = read();
    For(i, 1, n) a[i] = read();
    For(i, 1, 10) solve();//随机大法好（如果是真的比赛，这种算法还是不要卡的太死，万一是老年机呢？
    cout << ans;
    return 0;
}