#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n,m;
int H[20005],P[20005],X[20005],tot,E[20005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[20005];
queue<int> q;
int main(){

	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y,1);
		add(y,x,1);
	}
	d[1]=1;
	q.push(1);
	int ans=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		ans=max(ans,d[x]);
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	
	printf("%d\n",ans-1);
	return 0;
}
