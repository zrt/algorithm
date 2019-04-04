#include<iostream>
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,x,y,z;
struct N{
	int u,v,w;
	friend bool operator < (N  a,N b){
		return a.w<b.w;
	}
};
N a[5005];
int f[105];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n){
		int ans=0x7fffffff;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		}
		sort(a,a+m);
		int tot,last;
		for(int i=0;i<m;i++){
			for(int j=1;j<=n;j++) f[j]=j;
			tot=0;
			for(int j=i;j<m;j++){
				if(get(a[j].u)!=get(a[j].v)){
					tot++;
					f[get(a[j].u)]=f[get(a[j].v)];
					last=j;
				}
			}
			if(tot!=n-1) break;
			ans=min(ans,a[last].w-a[i].w);
		}
		if(ans==0x7fffffff) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
