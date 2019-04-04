#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<iostream>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int H[705],X[1405],P[1405],flow[1405],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[705];
int n,z;
string A("A"),Z("Z");
string x,y;
map<string,int> mp;
int num,S,T;
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=H[x];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(f,flow[i]));
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			f-=tmp;
			if(!f) break;
		}
	}
	if(f==a) d[x]=-1;
	return a-f;
}
int Dinic(){
	int f=0,tmp;
	while(bfs()){
		while(tmp=dfs(S,2000),tmp>0) f+=tmp;
	}
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	tot=1;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		if(mp.find(x)==mp.end()) mp[x]=++num;
		if(mp.find(y)==mp.end()) mp[y]=++num;
		int xx=mp[x],yy=mp[y];
		add(xx,yy,z);
		add(yy,xx,z);
	}
	S=mp[A],T=mp[Z];
	printf("%d\n",Dinic());
	return 0;
}
