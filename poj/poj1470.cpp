#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
//by zrt
//problem:
using namespace std;
int n;
vector<int> v[905];
int anc[905][11];
int dep[905];
bool vis[905];
void dfs(int x){
	int siz=v[x].size();
	for(int i=0;i<siz;i++){
		int p=v[x][i];
		anc[p][0]=x;
		dep[p]=dep[x]+1;
		dfs(p);
	}
}
int cnt[905];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) v[i].clear();
		int x,num,y;
		memset(vis,0,sizeof vis);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			scanf("%d:(%d)",&x,&num);
			for(int i=0;i<num;i++){
				scanf("%d",&y);
				v[x].push_back(y);vis[y]=1;
			} 
		}
		int root;
		for(int i=1;i<=n;i++){
			if(!vis[i]) {
				root=i;break;
			}
		}
		anc[root][0]=-1;
		dep[root]=1;
		dfs(root);
		int log;
		for(log=0;1<<log<=n;log++);log--;
		for(int i=0;i<log;i++){
			for(int j=1;j<=n;j++){
				if(~anc[j][i]){
					anc[j][i+1]=anc[anc[j][i]][i];
				}else anc[j][i+1]=-1;
			}
		}
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			while(getchar()!='(');
			scanf("%d%d",&x,&y);
			while(getchar()!=')');
			if(dep[x]<dep[y]) x^=y^=x^=y;
			for(int i=0;i<=log;i++){
				if((dep[x]-dep[y])>>i&1) x=anc[x][i]; 
			}
			if(x==y) goto ed;
			for(int i=log;i>=0;i--){
				if(anc[x][i]!=anc[y][i]){
					x=anc[x][i];
					y=anc[y][i];
				}
			}
			x=anc[x][0];
			ed:;
			cnt[x]++;
		}
		for(int i=1;i<=n;i++){
			if(cnt[i]){
				printf("%d:%d\n",i,cnt[i]);
			}
		}
	}
	
	return 0;
}
