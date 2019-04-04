#include<iostream>
#include<cstdio>
#include<vector>
//by zrt
//problem:
using namespace std;
//POJ 1985 树的直径 
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
vector<N> v[100005];
bool vis[100005];
N dfs(int x){
	vis[x]=1;
	int siz=v[x].size();
	N t;
	int maxn=0,maxx=x;
	for(int i=0;i<siz;i++){
		if(!vis[v[x][i].x]){
			t=dfs(v[x][i].x);
			if(t.w+v[x][i].w>=maxn){
				maxn=t.w+v[x][i].w;maxx=t.x;
			}
		}
	}
	vis[x]=0;
	return N(maxx,maxn);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m,x,y,z,root;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%*s",&x,&y,&z);
		v[x].push_back(N(y,z));
		v[y].push_back(N(x,z));
	}
	for(int i=n;i>0;i--){
		if(!vis[i]){
			root=i;break;
		}
	}
	int p=dfs(1).x;
	printf("%d",dfs(p).w);
	return 0;
}
