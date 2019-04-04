#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[2000005];
int n,m;
int son[2000005];
int c[2000005];
int w[2000005];
int num;
bool cmp(int x,int y){
	return w[x]<w[y];
}
void dfs(int x){
	for(int j=0;j<son[x];j++) dfs(v[x][j]);
	sort(v[x].begin(),v[x].end(),cmp);
	w[x]=c[x]+son[x];
	for(int i=0;i<son[x];i++){
		if(w[x]+w[v[x][i]]-1<=m){
			num++;
			w[x]+=w[v[x][i]]-1;
		}
	}
}
int main(){
//	freopen("sakura.in","r",stdin);
//	freopen("sakura.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&son[i]);
		v[i].reserve(son[i]);
		for(int j=0,x;j<son[i];j++){
			scanf("%d",&x);
			v[i].push_back(x+1);
		}
	}
	dfs(1);
	printf("%d\n",num);
	fclose(stdin);fclose(stdout);
	return 0;
}
