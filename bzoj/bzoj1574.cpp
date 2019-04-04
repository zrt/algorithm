#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int H[30005],X[210000],P[210000],tot;
int p,c,n;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool mark[30005];
bool vis[30005];
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&p,&c,&n);
	for(int i=0,x,y;i<c;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=0,x;i<n;i++){
		scanf("%d",&x);
		for(int j=H[x];j;j=X[j]){
			mark[P[j]]=1;
		}
	}
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(!mark[P[i]]&&!vis[P[i]]){
				q.push(P[i]);
			}
		}
	}
	int ans=0;
	for(int i=2;i<=p;i++){
		if(!vis[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
