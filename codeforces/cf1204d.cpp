#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read() {int x=0,f=0;char ch=getchar();while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();return f?-x:x;}
inline void write(int x) {if(x<0) x=-x,putchar('-');if(x>=10) write(x/10);putchar(x%10+'0');}
/*
有三种情况：
（1）：0000000...0000000000000000000000
（2）：1111111...1111111111111111111111
（3）：0000000...000001111111111...1111
如果0的个数比1要多，就不可能是2的情况
这样如果第一个是1，那么不能变成0，因为变成0会计入答案
所以只能维持1不变。
如果不是这样，那他就不是一定要维持1
那就可以变成0了
*/
char ch[1000005];
int tot;
signed main() {
    scanf("%s", ch+1);
    for(int i=strlen(ch+1);i>=1;i--) {
        if(ch[i]=='0') tot++;//0，不会变
        else if(tot) tot--;//1，第一种情况
        else ch[i]='0';//2,第二种情况
    }
    printf("%s",ch+1);
    return 0;
}