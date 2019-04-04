#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
int T,n;int map[10][10],f;
struct N{
	int x,w;
	bool c;
	friend bool operator < (N a,N b) {
		return a.w>b.w;
	}
}a[10];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		if(f) putchar('\n'); else f=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].w);
			a[i].x=i;a[i].c=0;
		}
		memset(map,0,sizeof map);
		sort(a,a+n);
		int ok=1;
		for(int t=0;t<n;t++){
			for(int i=0;i<n;i++){
				if(a[i].c) continue;
				a[i].c=1;
				if(i+a[i].w>=n) {
					ok=0;break;
				}
				for(int j=i+1;j<=i+a[i].w&&ok;j++){
					a[j].w--;
					map[a[i].x][a[j].x]=map[a[j].x][a[i].x]=1;
					if(a[j].w<0){
						ok=0;break;
					}
				}
				sort(a,a+n);break;
			}
			if(!ok) break;
		}
		if(!ok){
			puts("NO");
		}else{
			puts("YES");
		}
		if(ok){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d ",map[i][j]);
				}
				putchar('\n'); 
			}
		}
		
	}
	return 0;
}
