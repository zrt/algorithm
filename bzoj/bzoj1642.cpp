#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m,r;
int f[1005];
struct N{
	int s,e,p;
	friend bool operator < (N a,N b){
		return a.e<b.e;
	}
}a[1005];
int inf=1<<30;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].p);
	}
	a[0].e=-inf;
	sort(a,a+1+m);
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++){
			if(a[j].e+r<=a[i].s){
				f[i]=max(f[i],f[j]+a[i].p);
			}
		}
		ans=max(ans,f[i]);
	}
	
	printf("%d\n",ans);
	return 0;
}
