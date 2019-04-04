/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	int u,v,w;
	N(int a=0,int b=0,int c=0){
		u=a,v=b,w=c;
	}
	friend bool operator < (N a,N b){
		return a.w<b.w;
	}
};
N e[3000050];
int n,m;
int H[1000050],P[2000050],X[2000050],E[2000050],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int f[1000050];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int fa[1000050][25];
int w[1000050][25];
int ws[1000050][25];
int log;
int q[1000050],h,t;
int dep[1000050];
bool use[1000050];
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	int maxx=0;
	for(int i=log;i>=0;i--){
		if(dep[x]-dep[y]>=1<<i){
			maxx=max(maxx,w[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y) return maxx;
	for(int i=log;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			maxx=max(maxx,max(w[x][i],w[y][i]));
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	maxx=max(maxx,max(w[x][0],w[y][0]));
	return maxx;
}
int lcaa(int x,int y,int zx){
	if(dep[x]<dep[y]) swap(x,y);
	int maxx=0;
	for(int i=log;i>=0;i--){
		if(dep[x]-dep[y]>=1<<i){
			maxx=max(maxx,ws[x][i]);
			if(w[x][i]<zx) maxx=max(maxx,w[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y) return maxx;
	for(int i=log;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			maxx=max(maxx,max(ws[x][i],ws[y][i]));
			if(w[x][i]<zx) maxx=max(w[x][i],maxx);
			if(w[y][i]<zx) maxx=max(w[y][i],maxx);
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	maxx=max(maxx,max(ws[x][0],ws[y][0]));
	if(w[x][0]<zx) maxx=max(maxx,w[x][0]);
	if(w[y][0]<zx) maxx=max(maxx,w[y][0]);
	return maxx;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e,e+m);
	for(int i=1;i<=n;i++) f[i]=i;
	int cnt=1;
	for(log=0;1<<log<=n;log++);log--;
	long long sum=0;
	for(int i=0;i<m;i++){
		x=get(e[i].u),y=get(e[i].v);
		if(x==y) continue;
		cnt++;
		add(e[i].u,e[i].v,e[i].w);
		add(e[i].v,e[i].u,e[i].w);
		f[x]=y;
		use[i]=1;
		sum+=e[i].w;
		if(cnt==n) break;
	}
	//root = 1
	q[t++]=1;dep[1]=1;
	while(h!=t){
		x=q[h++];
		for(int i=H[x];i;i=X[i]){
			if(dep[P[i]]) continue;
			fa[P[i]][0]=x;
			q[t++]=P[i];
			w[P[i]][0]=E[i];
//			ws[P[i]][0]=E[i];
			dep[P[i]]=dep[x]+1;
		}
	}
	for(int i=1;i<=log;i++){
		for(int j=1;j<=n;j++){
			if(1<<i<=dep[j]){
				fa[j][i]=fa[fa[j][i-1]][i-1];
				w[j][i]=max(w[j][i-1],w[fa[j][i-1]][i-1]);
				ws[j][i]=min(w[j][i-1],w[fa[j][i-1]][i-1]);
				if(ws[j][i]==w[j][i]){
					ws[j][i]=max(ws[j][i-1],ws[fa[j][i-1]][i-1]);
				}
				if(ws[j][i]==w[j][i]){
					ws[j][i]=min(ws[j][i-1],ws[fa[j][i-1]][i-1]);
				}
			}
		}
	}
	int minn=~0U>>1;
	for(int i=0;i<m;i++){
		if(use[i]) continue; 
		int p=lca(e[i].u,e[i].v);
		if(e[i].w>p){
			minn=min(minn,e[i].w-p);
		}else{
			p=lcaa(e[i].u,e[i].v,p);
			if(p==0||p==e[i].w) continue;
			minn=min(minn,e[i].w-p);
		}
	}
	printf("%lld\n",sum+minn);
	return 0;
}
