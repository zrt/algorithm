#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m,k,x,y,z;
typedef long long LL;
LL d[10005][21];
int H[10005],X[100005],P[100005],tot,E[100005];
int ans;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x,k;long long w;
	N(int a=0,long long b=0,int K=0){
		x=a,w=b;k=K;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
int main(){
	memset(d,0x3f,sizeof d);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	d[n][0]=0;
	q.push(N(n,0,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(t.w!=d[t.x][t.k])continue;
		x=t.x;
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]][t.k]>d[x][t.k]+E[i]){
				d[P[i]][t.k]=d[x][t.k]+E[i];
				q.push(N(P[i],d[P[i]][t.k],t.k));
			}
			if(t.k<k){
				if(d[P[i]][t.k+1]>d[x][t.k]){
					d[P[i]][t.k+1]=d[x][t.k];
					q.push(N(P[i],d[P[i]][t.k+1],t.k+1));
				}
			}
		}
	}
	long long sum=~0LLU>>1;
	for(int i=0;i<=k;i++) if(d[1][i]<sum) sum=d[1][i];
	printf("%lld\n",sum);
	return 0;
}
