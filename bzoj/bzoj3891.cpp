#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,b,e,p;
int H[40005],X[80005],P[80005],tot;
int d1[40005],d2[40005],d3[40005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
queue<int> q;
int main(){
	scanf("%d%d%d",&b,&e,&p);
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	memset(d1,-1,sizeof d1);
	memset(d2,-1,sizeof d2);
	memset(d3,-1,sizeof d3);
	d1[1]=0;
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d1[P[i]]==-1){
				d1[P[i]]=d1[x]+b;
				q.push(P[i]);
			}
		}
	}
	d2[2]=0;
	q.push(2);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d2[P[i]]==-1){
				d2[P[i]]=d2[x]+e;
				q.push(P[i]);
			}
		}
	}
	d3[n]=0;
	q.push(n);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d3[P[i]]==-1){
				d3[P[i]]=d3[x]+p;
				q.push(P[i]);
			}
		}
	}
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++) ans=min(ans,d1[i]+d2[i]+d3[i]);
	printf("%d\n",ans);
	return 0;
}
