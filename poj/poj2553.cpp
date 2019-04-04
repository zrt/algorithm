#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[5005];
int n,m,x,y,tim,cnt;
int dfn[10005],low[10005],instack[10005],stk[10005],top,in[10005],point[10005];
void tj(int u){
	dfn[u]=low[u]= ++tim;
	instack[u]=1;
	stk[top++]=u;
	for(int i=0;i<v[u].size();i++){
		if(!dfn[v[u][i]]){
			tj(v[u][i]);
			low[u]=min(low[u],low[v[u][i]]);
		}else if(instack[v[u][i]]){
			low[u]=min(low[u],dfn[v[u][i]]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		int j;
		do{
			j=stk[top-1];--top;
			instack[j]=0;
			point[j]=cnt;
		}while(j!=u);
	}
}
int main(){
	while(scanf("%d",&n)==1&&n){
		scanf("%d",&m);
		top=0;cnt=0;
		for(int i=1;i<=n;i++) v[i].clear();
		memset(dfn,0,sizeof dfn);
		memset(instack,0,sizeof instack);
		memset(low,0,sizeof low);
		memset(in,0,sizeof in);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				tj(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				if(point[i]!=point[v[i][j]]){
					in[point[i]]++;
				}
			}
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			if(!in[point[i]]){
				if(f) f=0; else putchar(' ');
				printf("%d",i);
			}
		}
		putchar('\n');
	}
}