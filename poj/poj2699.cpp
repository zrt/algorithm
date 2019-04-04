#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int s[12],siz;
int m;
int S,T;
string line;
//1...siz // siz+siz*(i-1)+j //S=0 T=siz*siz+1+siz
#define get(x,y) ((x)*siz+(y))
bool vis[12][12];
int H[205],X[80000],P[80000],tot,flow[80000];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[205];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
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
	int f=a,tmp;
	if(x==T||a==0) return a;
	for(int i=H[x];i;i=X[i]){
		if(flow[i]>0&&d[P[i]]==d[x]+1){
			tmp=dfs(P[i],min(a,flow[i]));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
//	printf("%d\n",f-a);
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()) f+=dfs(S,inf);
	return f;
}
bool judge(int lim){
	int k=siz-lim+1;
	memset(vis,0,sizeof vis);
	tot=1;memset(H,0,sizeof H);
	for(int i=1;i<=siz;i++){
		add(S,i,s[i]);
		add(i,S,0);
	}
	for(int i=k;i<=siz;i++){
		for(int j=i+1;j<=siz;j++){
			if(s[i]<s[j]){
				add(i,get(i,j),1);
				add(get(i,j),i,0);
				vis[i][j]=1;
			}
		}
	}
	for(int i=1;i<=siz;i++){
		for(int j=i+1;j<=siz;j++){
			if(!vis[i][j]){
				add(i,get(i,j),1);
				add(get(i,j),i,0);
				add(j,get(i,j),1);
				add(get(i,j),j,0);
			}
			add(get(i,j),T,1);
			add(T,get(i,j),0);
		}
	}
	if(Dinic()==siz*(siz-1)/2) return 1;
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
//	ios::sync_with_stdio(false);
	cin>>m;
	while(m--){
		siz=0;
		scanf("%d",&s[++siz]);
		getline(cin,line);
		istringstream istr(line);
		while(istr>>s[++siz]);
		siz--;
		S=0,T=siz*siz+1+siz;
		int l=1,r=siz+1;
		int M;
		while(r-l>1){
			M=(l+r)>>1;
			if(judge(M)) l=M;
			else r=M;
		}
		printf("%d\n",l);
	}
	return 0 ;
}
