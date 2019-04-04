#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
const int MAXN=50005,MAXM=100005;
int fa[MAXN];
struct edge{
	int x,y,a,b;
}e[MAXM];
const int N=MAXN+MAXM;
int ls[N],rs[N],f[N],mx[N],w[N],pos[N];
bool rev[N];
inline bool notroot(int x){
	return ls[f[x]]==x||rs[f[x]]==x;
}
inline void down(int x){
	if(rev[x]){
		rev[ls[x]]^=1;
		rev[rs[x]]^=1;
		swap(ls[x],rs[x]);
		rev[x]=0;
	}
}
inline void up(int x){
	mx[x]=max(mx[ls[x]],mx[rs[x]]);
	if(mx[ls[x]]==mx[x]) pos[x]=pos[ls[x]];
	else pos[x]=pos[rs[x]];
	if(w[x]>mx[x]){
		mx[x]=w[x];
		pos[x]=x;
	}
}
void zig(int x){
	int y=f[x];
	if(rs[x]) ls[y]=rs[x],f[rs[x]]=y;else ls[y]=0;
	f[x]=f[y];
	if(ls[f[y]]==y) ls[f[y]]=x;
	else if(rs[f[y]]==y) rs[f[y]]=x;
	f[y]=x;rs[x]=y;
	up(y);
}
void zag(int x){
	int y=f[x];
	if(ls[x]) rs[y]=ls[x],f[ls[x]]=y;else rs[y]=0;
	f[x]=f[y];
	if(ls[f[y]]==y) ls[f[y]]=x;
	else if(rs[f[y]]==y) rs[f[y]]=x;
	f[y]=x;ls[x]=y;
	up(y);
}
int list[N],t;
void splay(int x){
	int y=x;
	t=0;
	while(notroot(y)) list[t++]=y,y=f[y];
	down(y);
	for(int i=t-1;i>=0;i--) down(list[i]);
	while(notroot(x)){
		int y=f[x];
		if(!notroot(y)){
			if(ls[y]==x) zig(x);else zag(x);
		}else{
			if(ls[f[y]]==y){
				if(ls[y]==x) zig(y),zig(x);
				else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);
				else zag(y),zag(x);
			}
		}
	}
	up(x);
}
bool cmp(const edge&a,const edge&b){
	return a.a<b.a;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int ans;
inline void access(int x){
	for(int y=0;x;x=f[x]){
		splay(x);
		rs[x]=y;
		up(x);
		y=x;
	}
}
inline void mkrt(int x){
	access(x);
	splay(x);
	rev[x]^=1;
	down(x);
}
inline void cut(int x,int y){
	mkrt(x);
	access(y);
	splay(y);
	down(y);
	ls[y]=f[x]=0;
	up(y);
}
inline void link(int x,int y){
	mkrt(x);
	f[x]=y;
	access(x);
}
//int tot=MAXN;
void add_edge(int i){
	//printf("# %d %d\n",e[i].x,e[i].y);
	if(get(e[i].x)!=get(e[i].y)){
		//puts("HAHA");
		fa[get(e[i].x)]=get(e[i].y);
		int tot=n+i+1;
		mx[tot]=w[tot]=e[i].b;
		pos[tot]=tot;
		link(e[i].x,tot);
		link(e[i].y,tot);
		splay(tot);
	}else{
	//	puts("HAHA");
		mkrt(e[i].x);
		access(e[i].y);
		splay(e[i].y);
		if(mx[ls[e[i].y]]<=e[i].b){
		//	puts("no");
		}else{
			int p=pos[ls[e[i].y]];
		//	printf("%d\n",p);
			p-=n+1;
			cut(e[p].x,p+n+1);
			cut(e[p].y,p+n+1);
			int tot=n+i+1;
			mx[tot]=w[tot]=e[i].b;
			pos[tot]=tot;
			link(e[i].x,tot);
			link(e[i].y,tot);
			splay(tot);
		}
	}
	
}
int ask(){
	int x=1,y=n;
	if(get(x)!=get(y)) return 0;
	mkrt(1);
	access(y);
	splay(y);
	//puts("HAHA");
	return mx[ls[y]];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].a,&e[i].b);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e,e+m,cmp);
	ans=0x7fffffff;
	for(int i=0;i<m;i++){
	//	printf("%d\n",i);
	//	puts("Debug");
	//	for(int i=1;i<=n+m;i++){
	//		printf("## %d %d %d %d %d %d\n",i,ls[i],rs[i],f[i],mx[i],pos[i]);
	//	}
		add_edge(i);
		if(get(1)==get(n)){
		//	printf("%d %d\n",e[i].a,ask());
			ans=min(ans,e[i].a+ask());
		}
	}
	if(ans!=0x7fffffff) printf("%d\n",ans);
	else puts("-1");
	return 0;
}
