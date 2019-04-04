#include <cstdio>
#include <cstring>
#include <algorithm>
//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
int n,k;
int f[50005],d[50005];//fa | dist to fa
// 0..1..2 //
int get(int x){
	if(x==f[x]) return x;
	int tmp=get(f[x]);
	d[x]+=d[f[x]];
	d[x]%=3;
	return f[x]=tmp;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){f[i]=i;}
	int tot=0;
	for(int i=0,D,x,y;i<k;i++){
		scanf("%d%d%d",&D,&x,&y);
		if(x>n||y>n||(D==2&&x==y)){
			tot++;continue;
		}
		if(D==1) {
			if(get(x)==get(y)){
				if(d[x]!=d[y]) tot++;
			}else{
				int tmp=get(x);
				f[get(x)]=y;
				d[tmp]=(-d[x]+3)%3;
			}
		}else {
			if(get(x)==get(y)){//x-->y
				if((d[x]-d[y]+3)%3!=1) tot++;
			}else{
				int tmp=get(x);
				f[get(x)]=y;
				d[tmp]=(1-d[x]+3)%3;
			}
		}
	}
	printf("%d\n",tot);
	return 0;
}
