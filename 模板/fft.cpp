//先背个板子吧（
#include <bits/stdc++.h>
#include <complex>
#define cp complex<double>
#define pi acos(-1)
using namespace std;
int n, m, c[5200000], len = 1;
cp x[5200000], y[5200000];
#define gc getchar
inline int read(){
    char ch=gc();int sum=0,f=0;
    while(!(ch>='0'&&ch<='9')) {f|=(ch=='-');ch=gc();}
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=gc();
    return f?-sum:sum;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
inline void fft(cp *a, int n, int inv) {
    if (n == 1)
        return;
    int mid = n >> 1;
    static cp b[5200000];
    for (register int i = 0; i <= mid - 1; i++)
        b[i] = a[i * 2], b[i + mid] = a[i * 2 + 1]; //拆成两组
    for (register int i = 0; i <= n - 1; i++)
        a[i] = b[i];
    fft(a, mid, inv);
    fft(a + mid, mid, inv);
    for (register int i = 0; i <= mid - 1; i++) {
        cp x(cos(2 * pi * i / n), inv * sin(2 * pi * i / n));
        b[i] = a[i] + x * a[i + mid];
        b[i + mid] = a[i] - x * a[i + mid];
    }
    for (register int i = 0; i <= n - 1; i++)
        a[i] = b[i];
}
signed main() {
    n=read(),m=read();
    for (register int i = 0; i <= n; i++)
        x[i]=read();
    for (register int i = 0; i <= m; i++)
        y[i]=read();
    while (len <= n + m)
        len <<= 1;
    fft(x, len, 1);
    fft(y, len, 1);
    for (register int i = 0; i <= len; i++)
        x[i] *= y[i];
    fft(x, len, -1);
    for (register int i = 0; i <= n + m; i++)
        c[i] = (int)(x[i].real() / len + 0.5);
    for (register int i = 0; i <= n + m; i++) {
       write(c[i]);
       putchar(' ');
    }
    return 0;
}