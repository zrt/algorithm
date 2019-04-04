#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	int w1,w2,h1,h2;
}a[100005],b[100005];
int tot;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tot=0;
		int maxw=-1;
		int maxpos;
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&a[i].w1,&a[i].w2,&a[i].h1,&a[i].h2);
			if(a[i].w2-a[i].w1>maxw){
				maxw=a[i].w2-a[i].w1;
				maxpos=i;
			}
		}
		bool ok=1;
		for(int i=0;i<n;i++){
			if(a[i].w1>=a[maxpos].w1&&a[i].w2<=a[maxpos].w2){
				;
			}else{
				ok=0;break;
			}
		}
		if(!ok){
			puts("NIE");continue;
		}
		for(int i=0;i<n;i++){
			if(a[i].w1==a[maxpos].w1&&a[i].w2==a[maxpos].w2) b[tot++]=a[i];
		}
		maxw=-1;
		for(int i=0;i<tot;i++){
			if(b[i].h2-b[i].h1>maxw){
				maxw=b[i].h2-b[i].h1;
				maxpos=i;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i].h1>=b[maxpos].h1&&a[i].h2<=b[maxpos].h2){
				;
			}else{
				ok=0;break;
			}
		}
		if(!ok){
			puts("NIE");continue;
		}
		puts("TAK");
	}
	
	return 0;
}
