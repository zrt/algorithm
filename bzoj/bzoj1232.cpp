/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,p;
struct N{
	int u,v,w;
	N(int a=0,int b=0,int c=0){
		u=a,v=b,w=c;
	}
};
N a[100005];
int w[10005];
int f[10005];
int x,y,z;
bool cmp(N a,N b){
	return a.w<b.w;
}
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int minn=~0U>>1;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		if(w[i]<minn) minn=w[i];
	}
	for(int i=0;i<p;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		a[i].w+=w[a[i].u]+w[a[i].v]+a[i].w;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a,a+p,cmp);
	int tot=0;
	long long sum=minn;
	for(int i=0;i<p&&tot<n-1;i++){
		if(get(a[i].u)!=get(a[i].v)){
			sum+=a[i].w;
			tot++;
			f[get(a[i].u)]=get(a[i].v);
		}
	}
	printf("%lld\n",sum);
	return 0;
}
