#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int f[1000005],n,m,k;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int H[1000005],X[4000005],P[4000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=k+1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(P[j]>k){
				f[get(i)]=get(P[j]);
			}
		}
	}
	int top(0);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if((i<=k||P[j]<=k)){
				if(get(i)==get(P[j])){
					top++;
				}else{
					f[get(i)]=get(P[j]);
				}
			}
		}
	}
	printf("%d\n",top);
	return 0 ;
}
