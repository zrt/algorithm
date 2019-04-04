/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<vector>
#define lowbit(x) (x&-x)
//by zrt
//problem:
using namespace std;
int n,m,x,y;
int H[100005],X[200005],P[200005],tot;
int w[100005],p[100005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int f[100005];
void Add(int pos,int k){
	while(pos<=n){
		f[pos]+=k;
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=f[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
int ans[100005];
void dfs(int x,int fa){
	ans[p[x]]=ask(p[x]);
	Add(p[x],1);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x);
		}
	}
	Add(p[x],-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) p[w[i]]=i;
	dfs(1,-1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
