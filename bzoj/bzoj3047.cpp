#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
const int M=10100;
const int INF=0x3f3f3f3f;
int n,m,q,cnt;
map<int,int> f[M];
vector<int> belong[M];
int dis[M];

vector<int> rings[M];
int size[M];
map<int,int> dist[M];

void Add(int x,int y,int z){
	if(f[x].find(y)==f[x].end()){
		f[x][y]=INF;
	}
	f[x][y]=min(f[x][y],z);
}
namespace Cactus_Graph{
	int fa[M<<1][16],dpt[M<<1];
	pair<int,int> second_lca;
	int Get_Depth(int x){
		if(!fa[x][0]) dpt[x]=1;
		if(dpt[x]) return dpt[x];
		return dpt[x]=Get_Depth(fa[x][0])+1;
	}
	void Pre(){
		int i,j;
		for(j=1;j<=15;j++){
			for(i=1;i<=cnt;i++){
				fa[i][j]=fa[fa[i][j-1]][j-1];
			}
			for(i=n+1;i<=n<<1;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		for(i=1;i<=cnt;i++) Get_Depth(i);
		for(i=n+1;i<=n<<1;i++) Get_Depth(i);
	}
	int LCA(int x,int y){
		int j;
		if(dpt[x]<dpt[y]) swap(x,y);
		for(j=15;j>=0;j--){
			if(dpt[fa[x][j]]>=dpt[y]) x=fa[x][j];
		}
		if(x==y) return x;
		for(j=15;j>=0;j--){
			if(fa[x][j]!=fa[y][j]){
				x=fa[x][j];y=fa[y][j];
			}
		}
		second_lca=make_pair(x,y);
		return fa[x][0];
	}
}
void Tarjan(int x){
	static int dpt[M],low[M],T;
	static int stack[M],top;
	map<int,int>::iterator it;
	dpt[x]=low[x]=++T;
	stack[++top]=x;
	for(it=f[x].begin();it!=f[x].end();it++){
		if(dpt[it->first]){
			low[x]=min(low[x],dpt[it->first]);
		}else{
			Tarjan(it->first);
			if(low[it->first]==dpt[x]){
				int t;
				rings[++cnt].push_back(x);
				belong[x].push_back(cnt);
				Cactus_Graph::fa[cnt][0]=n+x;
				do{
					t=stack[top--];
					rings[cnt].push_back(t);
					Cactus_Graph::fa[n+t][0]=cnt;
				}while(t!=it->first);//!
			}
			low[x]=min(low[x],low[it->first]);
		}
	}
}
void DFS(int x){
	vector<int>::iterator it,_it;
	static int stack[M];int i,j,top=0;
	for(it=rings[x].begin();it!=rings[x].end();it++){
		stack[++top]=*it;
	}
	stack[++top]=*rings[x].begin();
	for(i=1;i<top;i++){
		int p1=stack[i],p2=stack[i+1];
		size[x]+=f[p1][p2];
		if(i!=top-1){
			dist[x][p2]=dist[x][p1]+f[p1][p2];
		}
	}
	i=2;j=top-1;
	while(i<=j){
		if(dis[stack[i-1]]+f[stack[i-1]][stack[i]]<dis[stack[j+1]]+f[stack[j+1]][stack[j]]){
			dis[stack[i]]=dis[stack[i-1]]+f[stack[i-1]][stack[i]];i++;
		}else{
			dis[stack[j]]=dis[stack[j+1]]+f[stack[j+1]][stack[j]];j--;
		}
	}
	for(_it=rings[x].begin(),_it++;_it!=rings[x].end();_it++){
		for(it=belong[*_it].begin();it!=belong[*_it].end();++it){
			DFS(*it);
		}
	}
}
int main(){
	using namespace Cactus_Graph;
	int i,x,y,z;
	cin>>n>>m>>q;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);Add(y,x,z);
	}
	Tarjan(1);
	Pre();
	vector<int>::iterator it;
	for(it=belong[1].begin();it!=belong[1].end();it++){
		DFS(*it);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(n+x,n+y);
		if(lca>n) printf("%d\n",dis[x]+dis[y]-2*dis[lca-n]);
		else{
			int ans=dis[x]+dis[y]-dis[second_lca.first-n]-dis[second_lca.second-n];
			int temp=abs(dist[lca][second_lca.first-n]-dist[lca][second_lca.second-n]);
			ans+=min(temp,size[lca]-temp);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
