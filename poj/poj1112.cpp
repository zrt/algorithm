#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int map[105][105];
int n;
int H[105],X[10005],P[10005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dp[105][105];
int what[105][105];
int cnt[105][2];
vector<int> v[105][2];
int vis[105];
int now;
bool ok=1;
void dfs(int x){
	int to=3-vis[x];
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			vis[P[i]]=to;
			cnt[now][to-1]++;
			v[now][to-1].push_back(P[i]);
			dfs(P[i]);
			if(!ok) return;
		}else if(vis[P[i]]!=to){
			ok=0;return;
		}
	}
}
bool out[105];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		while(scanf("%d",&x),x){
			map[i][x]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((!map[i][j])||(!map[j][i])){
				add(i,j);add(j,i);
			}
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			now++;
			vis[i]=1;cnt[now][0]=1;
			v[now][0].push_back(i);
			dfs(i);
			if(!ok){
				puts("No solution");
				goto ed;
			}
			for(int i=cnt[now][0];i<=n/2;i++){
				if(dp[now-1][i-cnt[now][0]]){
					dp[now][i]=1;
					what[now][i]=0;
				}
			}
			for(int i=cnt[now][1];i<=n/2;i++){
				if(dp[now-1][i-cnt[now][1]]){
					dp[now][i]=1;
					what[now][i]=1;
				}
			}
		}
	}
	for(int i=n/2;i>0;i--){
		if(dp[now][i]){
			int a=now,b=i;
			printf("%d ",i);
			while(a>0){
				int k=what[a][b];
				for(int i=0;i<v[a][k].size();i++){
					out[v[a][k][i]]=1;
					printf("%d ",v[a][k][i]);
				}
				b-=cnt[a][k];
				a--;
			}
			puts("");
			printf("%d ",n-i);
			for(int i=1;i<=n;i++){
				if(!out[i]) printf("%d ",i);
			}
			puts("");
			break;
		}
	}
	ed:return 0;
}
