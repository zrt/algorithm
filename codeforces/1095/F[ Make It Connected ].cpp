#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n,m;
struct N{
	LL x,y,z;
}edges[200005+200005];
LL a[200005];
int fa[200005];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
bool cmp(N a, N b){
	return a.z<b.z;
}
int main(){
	scanf("%d%d",&n,&m);
	LL mn = 1LL<<60;
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]), mn=min(mn,a[i]);
	for(int i=1;i<=m;i++) scanf("%I64d%I64d%I64d",&edges[i].x, &edges[i].y, &edges[i].z);
	for(int i=1;i<=n;i++) fa[i]=i;
	int pos ;
	for(int i=1;i<=n;i++){
		if(a[i]==mn) pos = i;
	}
	for(int i=1;i<=n;i++){
		edges[i+m].x = i;
		edges[i+m].y = pos;
		edges[i+m].z = a[i]+a[pos];
	}

	m+=n;
	sort(edges+1,edges+m+1,cmp);
	LL ans = 0;
	for(int i=1;i<=m;i++){
		if(get(edges[i].x)!=get(edges[i].y)){
			fa[get(edges[i].x)] = get(edges[i].y);
			ans+=edges[i].z;
		}
	}
	cout<<ans<<endl;



	

	

	

	return 0;
}