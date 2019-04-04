#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
vector<N> v[150];
priority_queue<N> q;
int x;
bool vis[150];
int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x);
			if(i==j) continue;
			v[i].push_back(N(j,x));
			}
		}
		long long ans=0;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.x]) continue;
			vis[t.x]=1;
			ans+=t.w;
			for(int i=0;i<v[t.x].size();i++){
				q.push(v[t.x][i]);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}