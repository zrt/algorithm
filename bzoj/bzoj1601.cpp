/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<queue>
//by zrt
//problem:
using namespace std;
bool vis[305];
int val;
int sum,n;
struct N{
	int x,w;
	friend bool operator < (N a,N b){
		return a.w>b.w; 
	} 
	N(int a=0,int b=0){
		x=a,w=b;
	}
}t;
priority_queue<N> q;
int w[305][305];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val);
		q.push(N(i,val));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&w[i][j]);
		}
	}
	int k;
	while(!q.empty()){
		t=q.top();q.pop();
		if(vis[t.x]) continue;
		vis[t.x]=1;
		sum+=t.w;
		for(int i=1;i<=n;i++){
			if(i==t.x) continue;
			q.push(N(i,w[t.x][i]));
		}
	}
	printf("%d\n",sum);
	return 0;
}
