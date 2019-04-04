//0 red 1 yellow
#include<cstdio>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10005;
int n,m;
int f[MAXN][5];
// 0,1,r,y
// 2. none need red
// 3. none need yellow
// 4. none need none
int H[MAXN],X[MAXN<<1],P[MAXN<<1],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int c[MAXN];
const int inf=0x3f3f3f3f;
int ans=inf;
void dfs(int x,int fa){
	if(x<=m){
		f[x][c[x]]=1,f[x][2+c[x]]=0;
		f[x][c[x]^1]=f[x][2+(c[x]^1)]=f[x][4]=inf;
		return;
	}else{
		for(int i=H[x];i;i=X[i]){
			if(P[i]!=fa){
				dfs(P[i],x);
				for(int j=0;j<2;j++){
					f[x][j]+=min(min(f[P[i]][2+j],f[P[i]][4]),min(f[P[i]][0],f[P[i]][1]));
					if(f[x][j]>=2*inf) f[x][j]=inf;
					f[x][j+2]+=min(min(f[P[i]][2+j],f[P[i]][4]),min(f[P[i]][0],f[P[i]][1]));
					if(f[x][j+2]>=2*inf) f[x][j+2]=inf;
				}
				f[x][4]+=min(f[P[i]][4],min(f[P[i]][0],f[P[i]][1]));
				if(f[x][4]>=2*inf) f[x][4]=inf;
			}
		}
		f[x][0]++;f[x][1]++;
	}
}
void dp(int x){
	dfs(x,0);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&c[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dp(m+1);
	int i=m+1;
	printf("%d\n",min(f[i][0],min(f[i][1],f[i][4])));
	return 0;
}
