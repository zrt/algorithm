#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int x[1505],y[1505];
int a[505];
struct N{
	int x,y,z;
	friend bool operator < (const N&a,const N&b){
		return a.z<b.z;
	}
}e[550000];
int f[1505];
int tot;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int mx;
int main(){
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[tot].x=i;e[tot].y=j;
			e[tot].z=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			tot++;
		}
	}
	sort(e,e+tot);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0;i<tot;i++){
		if(get(e[i].x)!=get(e[i].y)){
			mx=max(mx,e[i].z);
			f[get(e[i].x)]=get(e[i].y);
		}
	}
	tot=0;
	for(int i=0;i<m;i++) if(a[i]*a[i]>=mx) tot++;
	printf("%d\n",tot);
	return 0;
}
