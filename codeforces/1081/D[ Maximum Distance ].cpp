#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
struct N{
	int x,y,w;
}edges[100005];
int sp[100005];
int fa[100005];
bool cmp(N a,N b){
	return a.w<b.w;
}
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	cin>>n>>m>>k;
	for(int i=1,x;i<=k;i++){
		scanf("%d",&x);
		sp[x] = 1;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w);
	}
	sort(edges+1,edges+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans = -1;
	for(int i=1;i<=m;i++){
		int x = get(edges[i].x);
		int y = get(edges[i].y);
		if(x!=y){
			if(sp[x] && sp[y]){
				ans = edges[i].w;
			}
			sp[x] =sp[x]||sp[y];
			fa[y] = x;
		}
	}
	for(int i=1;i<=k;i++) printf("%d ",ans);

	

	return 0;
}