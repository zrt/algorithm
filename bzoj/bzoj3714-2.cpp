#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int n;
int val[2005][2005];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool vis[2005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			scanf("%d",&x);
			val[j+1][i]=val[i][j+1]=x;
		}
	}
	long long cost(0);
	q.push(N(1,0));
	int c;
	n=n+1;
	while(!q.empty()){
		x=q.top().x;c=q.top().w;q.pop();
		if(vis[x]) continue;
		vis[x]=1;cost+=c;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				q.push(N(i,val[x][i]));
			}
		}
	}
	printf("%lld\n",cost);
	return 0;
}
