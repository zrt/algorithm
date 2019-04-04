#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n;
int H[10005],X[20005],P[20005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dp[10005][3];//0 not 1 yes
/*
dp[i][0] = sum(min(dp[s][2],dp[s][1]))自己没被选，父节点被选中 
dp[i][1] = sum(min(dp[s][1],dp[s][2]))自己没被选，某儿子结点被选中 
dp[i][2] = sum(min(dp[s][0],dp[s][1],dp[s][2]))自己被选中 
求dp[i][1] 时需注意当所有的dp[s][1] < dp[s][2]时是不满足条件的。 
*/
void dfs(int x,int fa){
	dp[x][0]=0;
	dp[x][2]=1;
	dp[x][1]=0;
	int stot=0;
	bool flag=0;
	int minn=inf;
	for(int i=H[x];i;i=X[i]){
		if(fa!=P[i]){
			stot++;
			dfs(P[i],x);
			dp[x][2]+=min(dp[P[i]][0],min(dp[P[i]][1],dp[P[i]][2]));
			dp[x][0]+=min(dp[P[i]][2],dp[P[i]][1]);
			if(dp[P[i]][1]<dp[P[i]][2]){
				dp[x][1]+=dp[P[i]][1];
				if(minn>dp[P[i]][2]-dp[P[i]][1]){
					minn=dp[P[i]][2]-dp[P[i]][1];
				}
			}else {
				flag=1;
				dp[x][1]+=dp[P[i]][2];
			}
		}
	}
	if(stot==0){
		dp[x][1]=inf;
		return;
	}
	if(!flag){
		dp[x][1]+=minn;
	}
	
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,-1);
	printf("%d\n",min(dp[1][2],dp[1][1]));
	
	return 0;
}
