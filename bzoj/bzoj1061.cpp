#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
typedef long long LL;
LL M;
int S=1003,T=1004;
int H[1005],X[30005],P[30005],tot=1,p[30005],from[30005];
LL f[30005],c[30005];
inline void add(int x,int y,LL z,LL k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;f[tot]=z;c[tot]=k;from[tot]=x;
}
LL in[1005];
LL cost;
LL d[1005];
bool inq[1005];
LL a[1005];
queue<int> q;
bool spfa(){
	memset(d,0x3f,sizeof d);
	a[T]=0;int x;d[S]=0,p[S]=-1;a[S]=M;inq[S]=1;q.push(S);
	while(!q.empty()){
		x=q.front();q.pop();inq[x]=0;
		for(int i=H[x];i;i=X[i]){
			if(f[i]>0&&d[P[i]]>d[x]+c[i]){
				d[P[i]]=d[x]+c[i];
				a[P[i]]=min(a[x],f[i]);
				p[P[i]]=i;
				if(!inq[P[i]]) inq[P[i]]=1,q.push(P[i]);
			}
		}
	}
	if(!a[T]) return 0;
	cost+=a[T]*d[T];
	x=T;
	while(x!=S){
		f[p[x]]-=a[T];
		f[p[x]^1]+=a[T];
		x=from[p[x]];
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		in[i]-=a;
		in[i+1]+=a;
		M+=a;
	}
	for(int i=1;i<=n+1;i++){
		if(in[i]>0) add(S,i,in[i],0),add(i,S,0,0);
		else add(i,T,-in[i],0),add(T,i,0,0);
		if(i<=n) add(i,i+1,M,0),add(i+1,i,0,0);
	}
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(y+1,x,M,z);
		add(x,y+1,0,-z);
	}
	while(spfa());
	printf("%lld\n",cost);
	return 0;
}
