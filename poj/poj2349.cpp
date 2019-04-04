#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
double d[505][505];
int x[505],y[505],T,s,p;
int tot;double ans[505];
struct N{
	int x;double w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,double b=0){
		x=a,w=b;
	}
}t;
priority_queue<N> q;
int vis[505];
inline bool cmp(double a,double b){
	return a>b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		tot=0;
		memset(vis,0,sizeof vis);
		scanf("%d%d",&s,&p);
		for(int i=1;i<=p;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=1;i<=p;i++){
			for(int j=i+1;j<=p;j++){
				d[i][j]=d[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			}
		}
//		vis[1]=1;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.x]) continue;
			vis[t.x]=1;
			ans[tot++]=t.w;
			for(int i=1;i<=p;i++){
				if(vis[i]) continue;
				q.push(N(i,d[t.x][i]));
			}
		}
		sort(ans,ans+tot,cmp);
		printf("%.2f\n",ans[s-1]);
	}
	return 0;
}