#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=1000000+5;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
vector<N> v[MAXN],f[MAXN];
int H[MAXN],P[MAXN],E[MAXN],X[MAXN],tot;
int _H[MAXN],_P[MAXN],_X[MAXN];
int T,n,m,x,y,z;
int d[MAXN];
priority_queue<N> q;
long long ans=0;
void add(int x,int y,int z){
	E[++tot]=z;P[tot]=y;X[tot]=H[x];H[x]=tot;_P[tot]=x;_X[tot]=_H[y];_H[y]=tot;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(H,0,sizeof H);
		memset(_H,0,sizeof _H);
		tot=0;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		ans=0; 
		memset(d,0x7f,sizeof d);
		d[1]=0;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			for(int i=H[t.x];i;i=X[i]){
				if(d[P[i]]>E[i]+d[t.x]){
					d[P[i]]=E[i]+d[t.x];
					q.push(N(P[i],d[P[i]]));
				}
			}
		}
		for(int i=2;i<=n;i++){
			ans+=d[i];
		}
		memset(d,0x7f,sizeof d);
		d[1]=0;
		q.push(N(1,0));
		while(!q.empty()){
			t=q.top();q.pop();
			for(int i=_H[t.x];i;i=_X[i]){
				if(d[_P[i]]>E[i]+d[t.x]){
					d[_P[i]]=E[i]+d[t.x];
					q.push(N(_P[i],d[_P[i]]));
				}
			}
		}
		for(int i=2;i<=n;i++){
			ans+=d[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
