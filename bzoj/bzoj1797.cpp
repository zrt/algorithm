#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int H[4005],X[120005],P[120005],tot,flow[120005],from[120005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;from[tot]=x;
}
int n,m,s,t;
int d[4005];
int belong[4005];
int low[4005],tim;
bool instk[4005];
int stk[4005],top;
int cnt;
void tarjan(int x){
	int dfn=low[x]=++tim;
	stk[top++]=x;instk[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]==0) continue;
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]==dfn){
		cnt++;
		int k;
		do{
			k=stk[--top];
			belong[k]=cnt;
			instk[k]=0;
		}while(k!=x);
	}
}
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[s]=1;int x;
	q.push(s);
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[t];
}
int dfs(int x,int a){
	int f=a,tmp;
	if(x==t||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
void Dinic(){
	while(bfs()){
		while(dfs(s,inf)>0);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,0);
	}
	Dinic();
	for(int i=1;i<=n;i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=2;i<=tot;i+=2){
		if(flow[i]){
			puts("0 0");
		}else {
			printf("%d %d\n",belong[from[i]]!=belong[P[i]],belong[from[i]]==belong[s]&&belong[P[i]]==belong[t]);
		}
	}
	
	return 0;
}
