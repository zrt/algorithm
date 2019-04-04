#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int n,m,w;
int H[505],X[6000],P[6000],E[6000];
int d[505],l[505];
int tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int tt;
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		memset(H,0,sizeof H);
		tot=0;
		scanf("%d%d%d",&n,&m,&w);
		for(int i=1,x,y,z;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1,x,y,z;i<=w;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,-z);
		}
		memset(d,0,sizeof d);
		memset(l,0,sizeof l);
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) q.push(i);
		bool have=0;
		while(!q.empty()){
			int x=q.front();q.pop();
	//		printf("%d %d %d\n",x,d[x],l[x]);
			for(int i=H[x];i;i=X[i]){
				if(d[P[i]]>d[x]+E[i]){
					d[P[i]]=d[x]+E[i];
					q.push(P[i]);
					l[P[i]]=l[x]+1;
					if(l[P[i]]>n) {
						have=1;goto ed;
					}
				}
			}
		}
		ed:;
		if(have) puts("YES");
		else puts("NO");
		
	}
	
	return 0;
}
