#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,b[205],c[205],K;
int bag[40005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	bag[0]=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	scanf("%d",&K);
	int maxx=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=c[i];j<<=1){
			c[i]-=j;
			int w=j*b[i];
			for(int k=min(maxx,K-w);k>=0;k--){
				if(bag[k]){
					maxx=max(maxx,k+w);
					if(!bag[k+w]) bag[k+w]=bag[k]+j;
					else bag[k+w]=min(bag[k+w],bag[k]+j);
				}
			}
		}
		if(c[i]){
			int w=c[i]*b[i];
			for(int k=min(maxx,K-w);k>=0;k--){
				if(bag[k]){
					maxx=max(maxx,k+w);
					if(!bag[k+w]) bag[k+w]=bag[k]+c[i];
					else bag[k+w]=min(bag[k+w],bag[k]+c[i]);
				}
			}
		}
	}
	printf("%d\n",bag[K]-1);
	return 0;
}
