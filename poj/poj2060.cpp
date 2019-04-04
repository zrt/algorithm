#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int tt;
int H[505],X[250005],P[250005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tim[505],fx[505],fy[505],tx[505],ty[505];
bool cover[505];int link[505];
bool find(int k){
	for(int i=H[k];i;i=X[i]){
		if(!cover[P[i]]){
			cover[P[i]]=1;
			int q=link[P[i]];
			link[P[i]]=k;
			if(q==-1||find(q)) return 1;
			link[P[i]]=q;
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		memset(H,0,sizeof H);
		tot=0;
		int n;
		scanf("%d",&n);
		for(int i=1,x,y;i<=n;i++){
			scanf("%d:%d%d%d%d%d",&x,&y,&fx[i],&fy[i],&tx[i],&ty[i]);
			tim[i]=x*60+y;
		}
		for(int i=1;i<=n;i++){
			int timx=tim[i]+abs(fx[i]-tx[i])+abs(fy[i]-ty[i]);
			for(int j=i+1;j<=n;j++){
				if(timx+abs(fx[j]-tx[i])+abs(fy[j]-ty[i])<tim[j]){
					add(i,j);
				}
			}
		}
		int ans(0);
		memset(link,-1,sizeof link);
		for(int i=1;i<=n;i++){
			memset(cover,0,sizeof cover);
			if(find(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
