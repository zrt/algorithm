#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,v;
int f[100005];
int g[100005];
int main(){
	scanf("%d%d",&n,&v);
	while(n--){
		int w,m;
		scanf("%d%d",&w,&m);
		for(int i=0;i<=v;i++){
			g[i]=f[i];
		}
		int a,b;
		while(m--){
			scanf("%d%d",&a,&b);
			for(int i=v;i>=a;i--){
				g[i]=max(g[i-a]+b,g[i]);
			}
		}
		for(int i=w;i<=v;i++) f[i]=max(f[i],g[i-w]);
	}
	printf("%d\n",f[v]);
	return 0;
}
