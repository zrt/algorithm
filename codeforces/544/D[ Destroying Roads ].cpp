#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
int n,m;
int H[3005],X[6005],P[6005],tot;
int d[3005][3005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;	
}
queue<int> q;
void bfs(int*d,int s){
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+1){
				q.push(P[i]);
				d[P[i]]=d[x]+1;
			}
		}
	}
}
int solve(int s1,int t1,int l1,int s2,int t2,int l2){
	int ret=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[s1][i]+d[i][j]+d[j][t1]<=l1&&d[s2][i]+d[i][j]+d[j][t2]<=l2)
			ret=max(ret,m-d[s1][i]-d[s2][i]-d[i][j]-d[t1][j]-d[t2][j]);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		bfs(d[i],i);
	}
	int s1,t1,l1,s2,t2,l2;
	scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
	if(d[s1][t1]>l1||d[s2][t2]>l2){
		puts("-1");
		return 0;
	}
	int ans=max(solve(s1,t1,l1,s2,t2,l2),solve(s1,t1,l1,t2,s2,l2));
	ans=max(ans,m-d[s1][t1]-d[s2][t2]);
	printf("%d\n",ans);
	return 0;
}