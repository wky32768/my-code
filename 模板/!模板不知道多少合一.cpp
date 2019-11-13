//二维前缀和
For(i,1,n) For(j,1,n) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];

//二分
int l=1,r=n,ans=0;
while(l<=r) {
	int mid=(l+r)>>1;
	if(ok(mid)) ans=mid,l=mid+1;
	else r=mid-1;
}

//三分 
double l=0,r=?,ans=0;
while(fabs(r-l)>=1e-6) {
	double mid1=l+(r-l)/3,mid2=l+(r-l)/3*2;
	if(f(mid1)<f(mid2)) l=mid1;
	else r=mid2;
}

//离散化
For(i,1,n) a[i]=b[i]=read();
sort(b+1,b+n+1);
int nn=unique(b+1,b+n+1)-(b+1);
For(i,1,n) a[i]=lower_bound(b+1,b+nn+1,a[i])-b;

//求第k大数
int search(int l,int r,int k) {
	if(l==r) return a[l];
	int now=0;
	For(i,l,r) if(a[i]<a[l]) {
		now++;
		swap(a[now+l],a[i]);	
	}
	if(now+1==k) return a[l];
	else if(now<k) return search(l+now+1,r,k-now-1);
	else return search(l+1,l+now,k);
}

//st表
int mx(int i,int j) {
	int len=log2(j-i+1);
	return max(mx[i][len],mx[j-(1<<len)+1][len];
}
For(i,1,n) a[i]=mx[i][0]=read();
For(i,1,n) For(j,1,20) if(i+(1<<j)-1<=n) mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);

//单调栈
For(i,1,n) {
	if(a[i]>=sta[cnt]) sta[++cnt]=a[i];
	else {
		int w=0;
		while(sta[cnt]>a[i]) {
			w++;
			ans=max(ans,sta[cnt]*w);
			cnt--;
		}
		sta[++cnt]=a[i];
	}
}

//单调队列
For(i,1,n) {
	while(l<=r && !ok(l)) l++;
	//更新答案 
	while(l<=r && q[r]/*比现在劣*/) r--;
	q[++r]=ans[i]; 
}

//字符串hash 
unsigned long long ...
p[0]=1;
For(i,1,n) p[i]=p[i]*131;
For(i,1,n) h[i]=h[i-1]*131+ch[i]-'0';
int has(int l,int r) {
	return h[r]-h[l]*p[r-l+1];
}

//kmp
k=0;
For(i,2,n) {
	while(a[i]!=a[k+1] && k) k=kmp[k];
	if(a[i]==a[k+1]) k++;
	kmp[i]=k;
}
k=0;
For(i,2,m) {
	while((k==n || b[i]!=a[k+1]) && k) k=kmp[k];	
	if(b[i]==a[k+1]) k++;
	if(k==n)...
}

//trie
int t[N][27],val[N],cnt;
void insert(char *ch) {
	int len=strlen(ch+1),now=1;
	For(i,1,len) {
		if(!t[now][ch-'a'+1]) t[now][ch-'a'+1]=++cnt;
		now=t[now][ch-'a'+1];
	}
	val[now]++;
}
int search(char *ch) {
	int len=strlen(ch+1),now=1;
	For(i,1,len) {
		if(!t[now][ch-'a'+1]) return 0;
		now=t[now][ch-'a'+1];	
	}
	return val[now];
}

//huffman树 
if((n-1)%(k-1)) For(i,1,k-1-(n-1)%(k-1)) q.push( (node) {1,0} );
while(q.size()!=1) {
	int tot_w=0,mx_h=0;
	For(i,1,k) {
		mx_h=max(mx_h,q.front().h);
		tot_w+=q.front().w;
		q.pop();
	}
	q.push((node) {tot_w,mx_h};
}

//树的重心 
void dfs(int x,int f) {
	sz[x]=1;
	int mx_son=0;
	for(int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=f) {
		fa[sxd[i].to]=x;
		dfs(sxd[i].to,x):
		sz[x]+=sz[sxd[i].to];
		mx_son=max(mx_son,sz[xd[i].to]);
	}
	mx_son=max(mx_son,n-sz[x]);
	if(mx_son>mx) {
		mx=mx_son,zx=x;	
	}
}
dfs(1,0);

//线性筛 
For(i,2,n) {
	if(!v[i]) {
		p[++cnt]=i;
		For(int j=1;j<=cnt;j++) {
			if(p[j]>n/i || p[j]>i) break;	
			v[p[j]*i]=p[j];
		}
	}
}

//exgcd
void exgcd(int a,int b,int &x,int &y) {
	if(!b) {x=1,y=0;return;}
	exgcd(b,a%b,y,x);	
	y-=a/b*x;
}

//逆元
//1.exgcd
int ny(int w) {
	int x=0,y=0;
	exgcd(a,mod,x,y);
	return x;
}
//2.公式
ny[1]=1;
For(i,2,mod-1) ny[i]=(mod-mod/i)*ny[mod%i]%mod;
//3.阶乘 
fac[0]=1;
For(i,1,n) fac[i]=fac[i-1]*i%mod;
fac_ny[n]=ksm(fac[n],mod-2);
Dep(i,n-1,1) fac_ny[i]=(ny[i+1]*(i+1))%mod;//阶乘的逆元
For(i,1,n) ny[i]=fac_ny[i]*fac[i-1]%mod;//单个数的逆元 

//高斯消元 
For(i,1,n) {
	For(j,i+1,n) if(fabs(c[j][i])>1e-6) {
		For(k,1,n) swap(c[j][k],c[i][k]);
		swap(b[j],b[i]);
		break;
	}
	For(j,1,n) if(i!=j) {
		int rate=c[j][i]/c[i][i];
		For(k,1,n) c[j][k]-=c[i][k]*rate;
		b[j]-=b[i]*rate;
	}
	cout<<b[i]/c[i][i]<<" ";
}

//组合数
int C(int n,int m) {return fac[n]*ny(m)%mod*ny(n-m)%mod;}

//并查集
int find(int x) {if(fa[x]==x) return x; fa[x]=find(fa[x]);}
void merge(int x,int y) {
	int xx=find(x),yy=find(y);
	if(xx==yy) continue;
	if(h[xx]>h[yy]) swap(xx,yy);
	fa[xx]=yy;
	h[yy]=max(h[yy],h[xx]+1);
}

//树状数组
#define lowbit (x&(-x))
void add(int x,int C) {
	for(int i=x;i<=n;i+=lowbit(x)) t[i]+=C;
}
int tot(int x) {
	int sum=0;
	for(int i=x;i;i-=lowbit(x)) sum+=t[i];
	return sum;	
}

//线段树 
void build(int l,int r,int rt) {
	if(l==r) {tree[rt]=a[l];return;}	
	int mid=(l+r)>>1;
	build(l,mid,rt<<1); build(mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int x,int l,int r) {
	if(!add[x]) return;
	add[x<<1]+=add[x]; add[x<<1|1]+=add[x];
	tree[x<<1]+=add[x]*l; tree[x<<1|1]+=add[x]*r;
	add[x]=0;
}
void change(int L,int R,int C,int l,int r,int rt) {
	if(L<=l && r<=R) {
		add[rt]+=C;
		tree[rt]+=C*(r-l+1);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(rt,mid-l+1,r-mid);
	if(L<=mid) change(L,R,C,l,mid,rt<<1);
	if(R>mid) change(L,R,C,mid+1,r,rt<<1|1);
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
int ask(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R) return tree[rt];	
	int mid=(l+r)>>1,tot=0;
	pushdwon(rt,mid-l+1,r-mid);
	if(L<=mid) tot+=change(L,R,C,l,mid,rt<<1);
	if(R>mid) tot+=change(L,R,C,mid+1,r,rt<<1|1);
	return tot;
}

//分块
void change1(int l,int r,int C,int x) {
	For(i,l,r) add[i]+=C;	
	sum[x]+=C*(r-l+1);
}
void change2(int l,int r,int C) {
	For(i,l,r) add_kuai[i]+=C;
}
int ask_tot(int l,int r) {
	int ll=(l-1)/sz+1,rr=(r-1)/sz+1,zong=0;
	if(ll==rr) {For(i,l,r) zong+=a[i]+add[i];return zong;}
	For(i,l,ll*sz) zong+=a[i]+add[i];
	For(i,ll+1,rr-1) zong+=sum[i]+add_kuai[i]*sz;
	For(i,(rr-1)*sz+1,rr) zong+=a[i]+add[i];
	return zong;
}
int sz=sqrt(n),tot=(n-1)/sz+1;
For(i,1,tot) For(j,1,sz) sum[i]+=a[(i-1)*sz+j];
while(m--) {
	l=read(),r=read(),C=read();
	int ll=(l-1)/sz+1,rr=(r-1)/sz+1;
	if(ll==rr) {change1(l,r,C,ll);continue;}
	change1(l,ll*sz,C,ll);
	change2(ll+1,rr-1,C);
	change1((rr-1)*sz+1,rr,C,rr);	
}
while(q--) {
	l=read(),r=rad();
	cout<<ask_tot(l,r)<<'\n';	
}

//三种背包 
//1.0/1背包
f[0]=1;
For(i,1,tot) {
	Dep(j,m,c[i]) 
		f[j]=max(f[j],f[j-c[i]]+w[i]);
}
//2.完全背包
f[0]=1;
For(i,1,tot) {
	For(j,c[i],m)
		f[j]=max(f[j],f[j-c[i]]+w[i]);
}
//3.多组背包，先二进制拆分再做0/1背包

//dij
memset(dis,0x3f,sizeof dis);
dis[1]=0;
priority_queue <node> q;
q.push((node) {0,1}};
while(!q.empty()) {
	node x=q.top(); q.pop();
	while(!q.empty() && vis[x.at]) {
		x=q.top(); q.pop();	
	}
	dis[x.at]=-x.dis;
	vis[x.at]=1;
	for(register int i=head[x.at];i;i=sxd[i].next)
		if(dis[sxd[i].to]>dis[x.at]+sxd[i].w) {
			dis[sxd[i].to]=dis[x.at]+sxd[i].w;
			if(!vis[sxd[i].to]) q.push((node) {-dis[sxd[i].to],sxd[i].to});
		}
}

//spfa
memset(dis,0x3f,sizeof dis);
dis[1]=0;
q.push(1);
while(!q.empty()) {
	int x=q.front(); q.pop();
	vis[x]=0;
	for(register int i=head[x];i;i=sxd[i].next)
		if(dis[sxd[i].to]>dis[x]+sxd[i].w) {
			dis[sxd[i].to]=dis[x.at]+sxd[i].w;
			if(!vis[sxd[i].to]) {q.push(x); vis[x]=1;}	
		}
}
 
//kruskal
sort(bian+1,bian+n+1);
int tot=0,at=1,sum=0;
while(tot!=n-1) {
	int x=bian[at].x,y=bian[at].y;
	int xx=find(x),yy=find(y);
	at++;
	if(xx==yy) continue;
	fa[xx]=yy;
	tot++;
	sum+=bian[at].w;
}

//prim
memset(dis,0x3f,sizeof dis);
q.push((node) {0,1});
dis[1]=0;
while(!q.empty()) {
	node x.q.top(); q.pop();
	while(!q.empty() && vis[x.at]) {
		x=q.top(); q.pop();
	}
	vis[x.at]=1;
	tot+=x.w;
	for(register int i=head[x.at];i;i=sxd[i].next) 
		if(!vis[sxd[i].to]) dis[sxd[i].to]=min(dis[sxd[i].to],sxd[i].w);
}

//LCA
void dfs(int x,int f) {
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	For(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(register int i=head[x];i;i=sxd[i].next) if(sxd[i].to!=f) dfs(sxd[i].to,x);	
}
int LCA(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	Dep(i,20,0) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	Dep(i,20,0) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

//tarjan
stack <int> sta;
void tarjan(int x,int f) {
	dfn[x]=low[x]=++cnt;
	sta.push(x);
	for(register int i=head[x];i;i=sxd[i].next) {
		if(!dfn[sxd[i].to]) {
			tarjan(sxd[i].to,x); low[x]=min(low[x],low[sxd[i].to]);
		} else if(vis[sxd[i].to]) {
			low[x]=min(low[x],dfn[sxd[i].to];	
		}
	}
	if(low[x]>=dfn[x]) {
		kuai++;
		int now=sta.top();
		while(!sta.empty() && now!=x) {
			now=sta.top(); sta.pop();
			vis[now]=0;
			a[kuai].push_back(now);
		}
	}
}
For(i,1,n) if(!vis[i]) tarjan(i);

//二分图匹配
int find(int x) {
	for(register int i=head[x];i;i=sxd[i].next) if(!used[sxd[i].to]) {
		used[sxd[i].to]=1;
		if((!girl[sxd[i].to]) || find(girl[sxd[i].to])) {
			girl[sxd[i].to]=x;
			return 1;
		}
	}
	return 0;
}
int ans=0;
For(i,1,n) {
	memset(used,0,sizeof used);
	ans+=find(i);
}

//dinic
bool bfs() {
	queue <int> q;
	while(!q.empty()) q.pop();
	memset(depth,0,sizeof depth);
	depth[s]=1;
	q.push(s);
	For(i,1,n) wky[i]=head[i];
	while(!q.empty()) {
		int x=q.front(); q.pop();
		for(register int i=head[x];i;i=sxd[i].next) 
			if(sxd[i].w>0 && depth[sxd[i].to]==0) {
				depth[sxd[i].to]=depth[x]+1;	
				q.push(sxd[i].to);
			}
	}
	return (depth[t]>0);
}
int dfs(int x,int val) {
	if(x==t) return val;
	int rest=val;
	for(int i=wky[x];i;i=sxd[i].next) {
		wky[x]=i;
		if(depth[sxd[i].to]==depth[x]+1 && sxd[i].w>0) {
			int carrot=dfs(sxd[i].to,min(rest,sxd[i].w);
			if(!carrot) depth[x]=0;
			sxd[i].w-=carrot;
			sxd[i^1].w+=carrot;
			rest-=carrot;
		}
	}
	return val-rest;
}
int dinic() {
	int ans=0;
	while(bfs()) ans+=dfs(s,0x3f3f3f3f);	
	return ans;
}
