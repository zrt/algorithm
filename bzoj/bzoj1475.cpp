#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
int a[35][35];
int tot=1;
int H[9050],X[9050*10],P[9050*10],flow[9050*10];
int get(int x,int y){
	return (x-1)*n+y;
}
int S=9048,T=9049;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
long long sum=0;
int d[9050];
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
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
		if(d[P[i]]==d[x]+1&&flow[i]>0){
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
long long Dinic(){
	long long ret=0;
	while(bfs()){
		ret+=dfs(S,0x7fffffff);
	}
	return ret;
}
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)&1){
				add(S,get(i,j),a[i][j]);
				add(get(i,j),S,0);
				for(int k=0;k<4;k++){
					int x=dx[k]+i,y=dy[k]+j;
					if(x>0&&x<=n&&y>0&&y<=n){
						add(get(i,j),get(x,y),0x3fffffff);
						add(get(x,y),get(i,j),0);
					}
				}
			}else{
				add(get(i,j),T,a[i][j]);
				add(T,get(i,j),0);
			}
		}
	}
	printf("%lld\n",sum-Dinic());
	return 0;
}
