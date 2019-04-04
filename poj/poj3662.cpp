#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,p,k;
int H[1005],X[20005],P[20005],E[20005];
bool vis[1005];
int w[20005];
int d[1005];
int tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};
priority_queue<N> q;
bool judge(int lim){
	for(int i=1;i<=tot;i++){
		if(E[i]>lim) w[i]=1;
		else w[i]=0;
	}
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[1]=0;
	q.push(N(1,0));
	int x;
	while(!q.empty()){
		x=q.top().x;q.pop();
		if(vis[x]) continue;
		else vis[x]=1;
		for(int i=H[x];i;i=X[i]){
			if(!vis[P[i]]&&d[P[i]]>d[x]+w[i]){
				d[P[i]]=d[x]+w[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	if(d[n]<=k) return 1;
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0,x,y,z;i<p;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	int l=-1,r=1000000;
	if(!judge(1000000)) {
		puts("-1");
		goto ed;
	}
	
	while(r-l>1){
		int m=(l+r)>>1;
		if(judge(m)){
			r=m;
		}else{
			l=m;
		}
	}
	printf("%d\n",r);
	ed:return 0;
}
