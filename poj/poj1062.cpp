#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int m,n,l,r,x,y;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
vector<N> v[150];
int diwei[150];
int val[150];
int d[150];
priority_queue<N> q;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int P,L,X;
		scanf("%d%d%d",&P,&L,&X);
		diwei[i]=L;
		val[i]=P;
		int T,V;
		v[i].reserve(X);
		for(int j=0;j<X;j++){
			scanf("%d%d",&T,&V);
			v[i].push_back(N(T,V));
		}
	}
	int ans=val[1];
	for(int i=0;i<=m;i++){
		l=diwei[1]-i;r=diwei[1]+m-i;
		memset(d,0x7f,sizeof d);
		d[1]=0;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(t.w!=d[t.x]) continue;
			int siz=v[t.x].size();
			for(int j=0;j<siz;j++){
				if(diwei[v[t.x][j].x]>=l&&diwei[v[t.x][j].x]<=r){
					if(d[v[t.x][j].x]>d[t.x]+v[t.x][j].w){
						d[v[t.x][j].x]=d[t.x]+v[t.x][j].w;
						q.push(N(v[t.x][j].x,d[v[t.x][j].x]));
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(d[j]!=0x7f7f7f7f){
				ans=min(ans,d[j]+val[j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}