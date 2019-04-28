void mo() {
    for(int i=1;i<=N;i++) miu[i]=1;
    for(int i=2;i<=N;i++) {
        if(vis[i]) continue;
        miu[i]=-1;//质数
        for(int j=i*2;j<=N;j+=i) {
            vis[j]=1;
            if((j/i)%i==0) miu[j]=0;
            else miu[j]*=-1;
        }
    }
    for(int i=1;i<=N;i++) sum[i]=sum[i-1]+miu[i];
}//构造莫比乌斯函数