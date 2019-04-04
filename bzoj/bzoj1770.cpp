#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,m;
int H[40],X[1200],P[1200],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int a[40][40];
int ans=50;
int val[40];
void dfs(int pos,int cnt){
	if(cnt>=ans) return;
	if(pos==0){
		ans=cnt;
		return;
	}
	if(a[pos][pos]){
		int k=0;
		for(int i=pos+1;i<=n;i++){
			if(a[pos][i]) k^=val[i];
		}
		k^=a[pos][n+1];
		val[pos]=k;
		dfs(pos-1,cnt+val[pos]);
	}else{
		int k=0;
		for(int i=pos+1;i<=n;i++){
			if(a[pos][i]) k^=val[i];
		}
		k^=a[pos][n+1];
		if(k) return;
		val[pos]=1;
		dfs(pos-1,cnt+val[pos]);
		val[pos]=0;
		dfs(pos-1,cnt+val[pos]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++){
		a[i][i]=a[i][n+1]=1;
	}
	for(int i=1;i<=n;i++){//lie
		bool ok=0;
		for(int j=i;j<=n;j++){
			if(a[j][i]){
				ok=1;
				for(int k=i;k<=n+1;k++) swap(a[j][k],a[i][k]);
				break;
			}
		}
		if(!ok) continue;
		for(int j=i+1;j<=n;j++){
			if(a[j][i]){
				for(int k=i;k<=n+1;k++){
					a[j][k]^=a[i][k];
				}
			}
		}
	}
	dfs(n,0);
	printf("%d\n",ans);
	return 0;
}

