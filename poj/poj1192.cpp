#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n;
struct Point{
	int x,y,w;
	Point(int x=0,int y=0,int w=0){
		this->x=x;this->y=y;this->w=w;
	}
}p[1005];
int dis(int x,int y){
	return abs(p[x].x-p[y].x)+abs(p[x].y-p[y].y);
}
int H[1005],X[2010],P[2010],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int root;
bool vis[1005];
int Dp[1005][2];//0..no  | 1..chose
void dp(int x){
	vis[x]=1;
	Dp[x][0]=0;Dp[x][1]=p[x].w;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]) {
			dp(P[i]);
			Dp[x][0]=max(Dp[x][0],max(Dp[P[i]][0],Dp[P[i]][1]));
			if(Dp[P[i]][1]>0) Dp[x][1]+=Dp[P[i]][1];
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].w);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dis(i,j)==1){
				add(i,j);add(j,i);
			}
		}
	}
	root=0;
	dp(root);
	printf("%d\n",max(Dp[root][0],Dp[root][1]));
	return 0 ;
}
