#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,k,m;
struct N{
	int x,y,z;
	bool f;
}e[40010];
int f[10010],tot;
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
bool judge(int p){
	for(int i=1;i<=n;i++) f[i]=i;
	int sum(0);
	for(int i=0;i<tot&&sum<k;i++){
		if(e[i].f&&e[i].z<=p&&(get(e[i].x)!=get(e[i].y))){
			sum++;
			f[get(e[i].x)]=get(e[i].y);
		}
	}
	if(sum<k) return 0;
	for(int i=0;i<tot&&sum<n-1;i++){
		if(e[i].z<=p&&get(e[i].x)!=get(e[i].y)){
			f[get(e[i].x)]=get(e[i].y);
			sum++;
		}
	}
	if(sum==n-1) return 1;
	return 0;
}
bool cmp(N a,N b){
	return a.z<b.z;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,a,b,c1,c2;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c1,&c2);
		e[tot].x=a,e[tot].y=b,e[tot].z=c1,e[tot].f=1;tot++;
		e[tot].x=a,e[tot].y=b,e[tot].z=c2,e[tot].f=0;tot++;
	}
	sort(e,e+tot,cmp);
	int L(-1),R(30000);
	int M;
	while(L!=R-1){
		M=(L+R)>>1;
		if(judge(M)){
			R=M;
		}else L=M;
	}
	printf("%d\n",R);
	return 0;
}
