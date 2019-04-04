#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<string>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
map<string,int> mp;
int H[1005],X[100005],P[100005],tot,flow[100005],from[100005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z,from[tot]=x;
}
int n,m;
int S,T;
string s;
string sb;
int d[1005];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;int x;q.push(S);
	while(!q.empty()){
		x=q.front();q.pop();
		if(x==T) continue;
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
	int tmp,f=a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			flow[i]-=tmp;
			a-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int ff=0,tmp;
	while(bfs()){
		while((tmp=dfs(S,inf))>0) ff+=tmp;
	}
	return ff;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;S=1004,T=1003;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]=i;
		add(i,T,1);
		add(T,i,0);
	}
	scanf("%d",&m);
	int pp=n;
	for(int i=0;i<m;i++){
		cin>>s>>s;
		if(mp.find(s)==mp.end()) mp[s]=pp++;
		add(S,mp[s],1);
		add(mp[s],S,0);
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		cin>>s>>sb;
		if(mp.find(s)==mp.end()) mp[s]=pp++;
		if(mp.find(sb)==mp.end()) mp[sb]=pp++;
		add(mp[s],mp[sb],inf);
		add(mp[sb],mp[s],0);
	}
	int maxflow=Dinic();
	
	printf("%d\n",m-maxflow);
	return 0;
}
