#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
//by zrt
//problem:
using namespace std;
double dist[205][205];
int dx[205],dy[205],n,cnt,m;
bool vis[205];
struct N{
	int x;double w;
	N(int a=0,double b=0.0){
		x=a;w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}tmp; 
priority_queue<N> q;
double d[205];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
int f=1;
	while(scanf("%d",&n)==1&&n){
if(f) f=0; else putchar('\n');
		cnt++;
		for(int i=1;i<=n;i++) scanf("%d%d",&dx[i],&dy[i]);
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			dist[i][j]=dist[j][i]=sqrt((dx[i]-dx[j])*(dx[i]-dx[j])+(dy[i]-dy[j])*(dy[i]-dy[j]));
		}
		d[1]=0.0;
		for(int i=2;i<=n;i++) d[i]=1e10;
		q.push(N(1,0.0));
		while(!q.empty()){
			tmp=q.top();q.pop();
			for(int i=1;i<=n;i++){
				if(i!=tmp.x){
					if(d[i]>max(dist[i][tmp.x],d[tmp.x])){
						d[i]=max(dist[i][tmp.x],d[tmp.x]);
						q.push(N(i,d[i]));
					}
				}
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n",cnt,d[2]);
	}
	return 0;
}
