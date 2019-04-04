#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int f[1005];
struct N{
	int x,y,z;
	friend bool operator < (N a,N b){
		return a.z>b.z;
	}
}a[20005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a,a+m);
	int tot=0;
	int c=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=0;i<m;i++){
		if(get(a[i].x)!=get(a[i].y)){
			c+=a[i].z;
			tot++;
			f[get(a[i].x)]=get(a[i].y);
		}
	}
	if(tot==n-1){
		printf("%d\n",c);
	}else{
		puts("-1");
	}
	return 0;
}
