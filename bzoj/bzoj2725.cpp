#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const LL inf(0x3f3f3f3f3f3f3f3fLL);
const double eps(1e-9);

int H0[200005],X0[400005],P0[400005],tot0,E0[400005];
void add0(int x,int y,int z){
	P0[++tot0]=y;X0[tot0]=H0[x];H0[x]=tot0;E0[tot0]=z;
}
int H1[200005],X1[400005],P1[400005],tot1,flow[400005],from[400005],E1[400005];
void add1(int x,int y,int z){
	P1[++tot1]=y;X1[tot1]=H1[x];H1[x]=tot1;flow[tot1]=z;from[tot1]=x;
}
int H2[200005],X2[400005],P2[400005],tot2,E2[400005],from2[400005];
void add2(int x,int y,int z){
	P2[++tot2]=y;X2[tot2]=H2[x];H2[x]=tot2;E2[tot2]=z;from2[tot2]=x;
}
int n,m,Q,S,T;
int cut[200005];
LL ds[200005],dt[200005];
bool vis[200005];
struct N{
	int x;LL w;
	N(int a=0,LL b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
int d[200005];
queue<int> qu;
deque<int> dq;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;int x;qu.push(S);
	while(!qu.empty()){
		x=qu.front();qu.pop();
		if(x==T) continue;
		for(int i=H1[x];i;i=X1[i]){
			if(flow[i]>0&&!d[P1[i]]){
				d[P1[i]] =d[x]+1;
				qu.push(P1[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int tmp,f=a;
	for(int i=H1[x];i;i=X1[i]){
		if(flow[i]>0&&d[P1[i]]==d[x]+1){
			tmp=dfs(P1[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(a==f) d[x]=-1;
	return f-a;
}
int ff;
int low[200005],tim;
int stk[200005],top;
bool instk[200005];
int id[200005];
int cnt;
void tarjan(int x){
	stk[top++]=x;instk[x]=1;
	int dfn=low[x]=++tim;
	for(int i=H1[x];i;i=X1[i]){
		if(flow[i]==0) continue;
		if(!low[P1[i]]){
			tarjan(P1[i]);
			low[x]=min(low[x],low[P1[i]]);
		}else if(instk[P1[i]]) low[x]=min(low[x],low[P1[i]]);
	}
	if(dfn==low[x]){
		cnt++;
		int k;
		do{
			k=stk[--top];
			instk[k]=0;
			id[k]=cnt;
		}while(k!=x);
	}
}
int Ds[200005],Dt[200005];
LL ans[200005];
vector<int> v[200005];
struct A{
	int x,y;
	LL w;
	A(int a=0,int b=0,LL c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (A a,A b){
		return a.w>b.w;
	}
};
priority_queue<A> pq;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot0=tot1=1;
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add0(x,y,z);
		add0(y,x,z);
	}
	scanf("%d%d%d",&S,&T,&Q);
	memset(ds,0x3f,sizeof ds);memset(dt,0x3f,sizeof dt);
	ds[S]=dt[T]=0;int x;
	q.push(N(S,0));
	while(!q.empty()){
		x=q.top().x; q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		if(x==T) continue;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		for(int i=H0[x];i;i=X0[i]){
			if(!vis[P0[i]]&&ds[P0[i]]>ds[x]+E0[i]){
				ds[P0[i]]=ds[x]+E0[i];
				q.push(N(P0[i],ds[P0[i]]));
			}
		}
	}
	memset(vis,0,sizeof vis);
	q.push(N(T,0));
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		if(x==S) continue;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		for(int i=H0[x];i;i=X0[i]){
			if(!vis[P0[i]]&&dt[P0[i]]>dt[x]+E0[i]){
				dt[P0[i]]=dt[x]+E0[i];
				q.push(N(P0[i],dt[P0[i]]));
			}
		}
	}
	if(ds[T]==inf) {
		for(int i=0;i<Q;i++){
			puts("Infinity");
		}
		goto ed;
	}
	for(int i=1;i<=n;i++){
		for(int j=H0[i];j;j=X0[j]){
			if(ds[P0[j]]==ds[i]+E0[j]){
				add1(i,P0[j],1);
				add1(P0[j],i,0);
			}
			if(dt[P0[j]]==dt[i]+E0[j]){
				add2(i,P0[j],0);
			}
		}
	}
	ff=0;
	if(bfs()) ff+=dfs(S,1);
	if(bfs()) ff+=dfs(S,1);
	if(ff==2){
		for(int i=0;i<Q;i++) printf("%lld\n",ds[T]);
		goto ed;
	}
	for(int i=1;i<=n;i++) if(!low[i]) tarjan(i);
	for(int i=2;i<=tot1;i+=2){
		if(flow[i]==0&&id[from[i]]!=id[P1[i]]) cut[from[i]]=P1[i],E1[i]=1;
	}
	for(int i=1;i<=tot2;i++){
		if(cut[P2[i]]==from2[i]) E2[i]=1;
	}
	memset(vis,0,sizeof vis);
	memset(Ds,0x3f,sizeof Ds);
	memset(Dt,0x3f,sizeof Dt);
	Ds[S]=Dt[T]=0;
	dq.push_back(S);
	while(!dq.empty()){
		x=dq.front();dq.pop_front();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=H1[x];i;i=X1[i]){
			if(i&1) continue;
			Ds[P1[i]]=min(Ds[P1[i]],Ds[x]+E1[i]);
			if(E1[i]){
				dq.push_back(P1[i]);
			}else dq.push_front(P1[i]);
		}
	}
	memset(vis,0,sizeof vis);
	dq.push_back(T);
	while(!dq.empty()){
		x=dq.front();dq.pop_front();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=H2[x];i;i=X2[i]){
			Dt[P2[i]]=min(Dt[P2[i]],Dt[x]+E2[i]);
			if(E2[i]){
				dq.push_back(P2[i]);
			}else dq.push_front(P2[i]);
		}
	}
	for(int i=1;i<=n;i++) if(ds[i]!=inf)v[Ds[i]].push_back(i);
	for(int num=0;num<cnt;num++){
		int siz=v[num].size();
		while(!pq.empty()&&Dt[pq.top().y]>=Ds[T]-num) pq.pop();
		for(int j=0;j<siz;j++){
			x=v[num][j];
			for(int i=H0[x];i;i=X0[i]){
				if(Ds[P0[i]]>num&&cut[x]!=P0[i])
				pq.push(A(x,P0[i],ds[x]+E0[i]+dt[P0[i]]));
			}
		}
		int xx,yy;
		if(!pq.empty()) xx=pq.top().x,yy=pq.top().y,ans[num]=pq.top().w;
	}
	for(int i=0,x,y;i<Q;i++){
		scanf("%d%d",&x,&y);
		if(cut[x]==y){
			if(ans[Ds[x]]) printf("%lld\n",ans[Ds[x]]);
			else puts("Infinity");
		}else if(cut[y]==x){
			if(ans[Ds[y]]) printf("%lld\n",ans[Ds[y]]);
			else puts("Infinity");
		}else{
			printf("%lld\n",ds[T]);
		}
	}
	ed:return 0;
}
