#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int H[105],X[105],P[105];
int n,m,tot;
int w[105],vv[105];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tim,low[105];
int stk[105],top;
int belong[105];
int W[105],V[105],cnt;
bool instk[105];
void tj(int x){
	int dfn=low[x]=++tim;
	stk[top++]=x;instk[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tj(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(dfn==low[x]){
		cnt++;
		int k;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
			W[cnt]+=w[k];
			V[cnt]+=vv[k];
		}while(k!=x);
	}
}
int in[105];
vector<int> v[105];
int ans[505];
int dp[105][505];

void Dp(int x){
	if(W[x]>m) return;
	for(int i=0;i<W[x];i++){
		dp[x][i]=-(1<<25);
	}
	for(int i=W[x];i<=m;i++) dp[x][i]=V[x];
	for(int i=0;i<v[x].size();i++){
		Dp(v[x][i]);
		for(int s=m;s>=W[x];s--){
			for(int j=s;j>=0;j--){
				dp[x][s]=max(dp[x][s],dp[v[x][i]][j]+dp[x][s-j]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d",&vv[i]);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x) add(x,i);
	}
	for(int i=1;i<=n;i++){
		if(!low[i]) tj(i);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(belong[i]!=belong[P[j]]){
				v[belong[i]].push_back(belong[P[j]]);
				in[belong[P[j]]]++;
			}
		}
	}
	
	for(int i=1;i<=cnt;i++){
		if(W[i]>m) continue;
		if(!in[i]){
			Dp(i);
			for(int s=m;s>=0;s--){
				for(int j=s;j>=0;j--){
					dp[0][s]=max(dp[0][s],dp[i][j]+dp[0][s-j]);
				}
			}
		}
	}
	
	printf("%d\n",dp[0][m]);
	return 0;
}
