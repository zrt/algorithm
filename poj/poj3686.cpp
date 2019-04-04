#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m;
int tt;
int H[55],X[250000],P[250000],cost[250000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;cost[tot]=z;
}
int map[55][55];
int Lx[55],Ly[2505];
int link[2505];
bool S[55],T[2505];
bool find(int x){
	S[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!T[P[i]]&&cost[i]==Lx[x]+Ly[P[i]]){
			T[P[i]]=1;
			if(!link[P[i]]||find(link[P[i]])){
				link[P[i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
void update(){
	int a=inf;
	for(int i=1;i<=n;i++) if(S[i]){
		for(int j=H[i];j;j=X[j]){
			if(!T[P[j]]) a=min(Lx[i]+Ly[P[j]]-cost[j],a);
		}
	}
	for(int i=1;i<=n;i++) if(S[i]) Lx[i]-=a;
	for(int i=1;i<=m*n;i++) if(T[i]) Ly[i]+=a;
}
void KM(){
	for(int i=1;i<=m*n;i++) link[i]=Ly[i]=0;
	for(int i=1;i<=n;i++){Lx[i]=0;}
	for(int i=1;i<=n;i++){
		for(;;){
			for(int j=1;j<=n;j++) S[j]=0;
			for(int j=1;j<=m*n;j++) T[j]=0;
			if(find(i)) break;else update();
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&n,&m);
		tot=0;memset(H,0,sizeof H);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&map[i][j]);
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					add(i,(k-1)*m+j,-map[i][j]*k);
				}
			}
		}
		memset(link,0,sizeof link);
		KM();int sum=0;
		for(int i=1;i<=m*n;i++) if(link[i]) sum+=Lx[link[i]]+Ly[i];
		printf("%.6f\n",-sum/(double)n);
	}
	return 0 ;
}
