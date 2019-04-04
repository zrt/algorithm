#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
struct N{
	int x,y,w;
}map[2005*2005];
int tot;
bool cmp(N a,N b){
	return a.w<b.w;
}
int f[2005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			scanf("%d",&map[tot].w);
			map[tot].x=i;
			map[tot].y=j+1;
			tot++;
		}
	}
	sort(map,map+tot,cmp);
	long long cost(0);
	for(int i=1;i<=n+1;i++) f[i]=i;
	for(int i=0;i<tot;i++){
		if(get(map[i].x)!=get(map[i].y)){
			f[get(map[i].x)]=get(map[i].y);
			cost+=map[i].w;
		}
	}
	printf("%lld\n",cost);
	
	return 0;
}
