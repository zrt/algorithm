#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long double ld;
int n,m,s,t;
int H[10005],X[1000005],P[1000005],tot;
int du[10005];
vector<int> v[10005],vv[10005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool vis1[10005],vis2[10005];
queue<int> q;
ld a[105][105];
bool del[10005];
ld ans[10005];
int low[10005],dfn[10005],tim;
bool instk[10005];
int stk[10005],top;
int belong[10005];
vector<int> p[10005];
int cnt;
int list[10005],to[10005],cc;
void tarjan(int x){
	low[x]=dfn[x]=++tim;
	stk[top++]=x;instk[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(del[P[i]]) continue;
		if(!dfn[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],dfn[P[i]]);
	}
	if(low[x]==dfn[x]){
		cnt++;
		int k;
		do{
			k=stk[--top];
			instk[k]=0;
			p[cnt].push_back(k);
			belong[k]=cnt;
		}while(k!=x);
	}
}
int in[10005];
void Gauss(int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(fabs(a[j][i])>fabs(a[i][i])){
				for(int k=i;k<=n;k++) swap(a[i][k],a[j][k]);
			}
		}
		for(int j=n;j>=i;j--) a[i][j]/=a[i][i];
		for(int j=0;j<n;j++){
			if(i!=j){
				double f=a[j][i];
				for(int k=i;k<=n;k++) a[j][k]-=f*a[i][k];
			}
		}
	}
}
void topsort(){//反图
	for(int i=1;i<=n;i++){
		if(del[i]) continue;
		for(int j=0;j<v[i].size();j++){
			if(!del[v[i][j]]&&belong[i]!=belong[v[i][j]]){
				vv[belong[i]].push_back(belong[v[i][j]]);
				in[belong[v[i][j]]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		//solve x
		cc=p[x].size();
		for(int i=0;i<cc;i++) to[p[x][i]]=i;
		for(int i=0;i<=cc;i++) for(int j=0;j<=cc;j++) a[i][j]=0;
		for(int i=0;i<cc;i++){
			if(p[x][i]==t){
				a[i][i]=1;a[i][cc]=0;
			}else{
				a[i][i]=1;a[i][cc]=1;
				for(int j=H[p[x][i]];j;j=X[j]){
					if(!del[P[j]]){
						if(belong[P[j]]==x){
							a[i][to[P[j]]]-=1.0/du[p[x][i]];
						}else{
							a[i][cc]+=ans[P[j]]/(double)du[p[x][i]];
						}
					}
				}
			}
		}
		Gauss(cc);
		for(int i=0;i<cc;i++) ans[p[x][i]]=a[i][cc];
		//
		for(int i=0;i<vv[x].size();i++){
			in[vv[x][i]]--;
			if(!in[vv[x][i]]){
				q.push(vv[x][i]);
			}
		}
	}
}
int dfs(int x){
	vis1[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(del[P[i]]){
			del[x]=1;
			return 1;
		}
		if(vis1[P[i]]){
			;
		}else if(dfs(P[i])){
			del[x]=1;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);add(x,y);v[y].push_back(x);
	}
	q.push(s);
	vis1[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!vis1[P[i]]) vis1[P[i]]=1,q.push(P[i]);
		}
	}
	q.push(t);
	vis2[t]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<v[x].size();i++){
			if(!vis2[v[x][i]]){
				vis2[v[x][i]]=1;q.push(v[x][i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis1[i]) del[i]=1;
		if(vis1[i]&&!vis2[i]) del[i]=1;
	}
	memset(vis1,0,sizeof vis1);
	for(int i=1;i<=n;i++){
		if(!vis1[i]&&!del[i]){
			dfs(i);
		}
	}
	if(del[s]){
		puts("INF");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(del[i]) continue;
		for(int j=H[i];j;j=X[j]){
			if(!del[P[j]]) du[i]++;
		}
	}
	tarjan(s);
	//printf("###%d\n",cnt);
	//for(int i=1;i<=n;i++) printf("%d %d\n",du[i],belong[i]);
	topsort();
	printf("%.3f\n",(double)ans[s]);
	return 0;
}
