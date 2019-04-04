#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int H[25005],X[200005],P[200005],E[200005],kind[200005];
int tot;
int belong[25005],in[25005];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;kind[tot]=k;
}
int n,m1,m2,s;
int x,y,z;
bool vis[25005];
vector<int> v[25005];
int d[25005];
queue<int> q;
int cnt;
void bfs(){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		//	printf("%d\n",cnt);
			cnt++;
			vis[i]=1;
			q.push(i);
			while(!q.empty()){
				x=q.front();q.pop();
		//		printf("%d\n",x);
			//	vis[x]=1;
				v[cnt].push_back(x);
				belong[x]=cnt;
				for(int i=H[x];i;i=X[i]){
					if(!vis[P[i]]){
						vis[P[i]]=1;
						q.push(P[i]);
					}
				}
			}
		}
	}
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
priority_queue<N> pq;
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m1,&m2,&s);
	for(int i=0;i<m1;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,1);add(y,x,z,1);
	}
	bfs();
	memset(vis,0,sizeof vis);
	memset(d,0x3f,sizeof d);
	d[s]=0;
	for(int i=0;i<m2;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z,0);
		in[belong[y]]++;
	}
	for(int i=1;i<=cnt;i++) if(!in[i]) q.push(i);
	while(!q.empty()){
		z=q.front();q.pop();int siz=v[z].size();
		for(int i=0;i<siz;i++) pq.push(N(v[z][i],d[v[z][i]]));
		while(!pq.empty()){
			x=pq.top().x;pq.pop();
			if(vis[x]) continue;
			else vis[x]=1;
		//	
			for(int i=H[x];i;i=X[i]){
				if(kind[i]){
					if(d[P[i]]>d[x]+E[i]){
						d[P[i]]=d[x]+E[i];
						pq.push(N(P[i],d[P[i]]));
					}
				}else{
					in[belong[P[i]]]--;
					if(!in[belong[P[i]]]){
						q.push(belong[P[i]]);
					}
					if(d[x]==0x3f3f3f3f) continue;
					d[P[i]]=min(d[P[i]],d[x]+E[i]);
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(d[i]==0x3f3f3f3f){
			puts("NO PATH");
		}else{
			printf("%d\n",d[i]);
		}
	}
	
//	for(int i=1;i<=n;i++) printf("%d ",belong[i]);
	return 0;
}
