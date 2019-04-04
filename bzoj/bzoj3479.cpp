#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
#define int LL
int n,c;
int x[2005],y[2005];
struct N{
	int x,y,z;
	friend bool operator < (N a,N b){
		return a.z<b.z;
	}
}a[2020025];
int tot;
bool check(int i,int j){
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])>=c;
}
int f[2005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
#undef int
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#define int LL
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(check(i,j)){
				tot++;
				a[tot].x=i;
				a[tot].y=j;
				a[tot].z=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+tot+1);
	int ans=0;
	int p=0;
	for(int i=1;i<=tot;i++){
		if(get(a[i].x)!=get(a[i].y)){
			f[get(a[i].x)]=get(a[i].y);
			ans+=a[i].z;
			p++;
		}
	}
	if(p==n-1)
	printf("%lld\n",ans);
	else puts("-1");
	return 0;
}
