#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
//by zrt
//problem:
using namespace std;
int f,p,c,m;
int H[505],X[2050],P[2050],E[2050];
int tot;
int d[505];
bool vis[505];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
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
vector<int> Ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int i=0,x,y,z;i<p;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	int ans=0;
	for(int i=0,x;i<c;i++){
		scanf("%d",&x);
		if(d[x]<=m){
			Ans.push_back(i+1);
			ans++;
		}
	}
	sort(Ans.begin(),Ans.end());
	printf("%d\n",ans);
	for(int i=0;i<Ans.size();i++){
		printf("%d\n",Ans[i]);
	}
	return 0;
}
