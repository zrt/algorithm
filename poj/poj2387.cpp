#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
//by zrt
//problem:
using namespace std;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}tmp;
vector<N> v[1005];
priority_queue<N> q;
int n,t,x,y,z,d[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&t,&n);
	for(int i=0;i<t;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(N(y,z));
		v[y].push_back(N(x,z));
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		tmp=q.top();q.pop();
		for(int i=0;i<v[tmp.x].size();i++){
			if(d[v[tmp.x][i].x]>d[tmp.x]+v[tmp.x][i].w){
				d[v[tmp.x][i].x]=d[tmp.x]+v[tmp.x][i].w;
				q.push(N(v[tmp.x][i].x,d[v[tmp.x][i].x]));
			}
		}
	}
	printf("%d",d[n]);
	return 0;
}
