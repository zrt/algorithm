#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,T,rxa,rxc,rya,ryc,rp;
int x,y,z;
int e8=100000000;
int H[1000005],P[10000005],X[10000005],E[10000005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x;unsigned long long w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,unsigned long long b=0){
		x=a,w=b;
	}
}t;
priority_queue<N> q;
long long d[1000005];
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&T,&rxa,&rxc,&rya,&ryc,&rp);
	m-=T;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);add(x,y,z);
	}
	x=y=z=0;
	int a,b;
	/*
	for(int i=0;i<T;i++){
		x=(x*rxa+rxc)%rp;
		y=(y*rya+ryc)%rp;
		a=min(x%n+1,y%n+1);
		b=max(y%n+1,y%n+1);
		add(a,b,e8-100*a);
	}
	*/
	memset(d,0x7f,sizeof d);
	d[1]=0;
	q.push(N(1,0));
	while(!q.empty()){
		t=q.top();q.pop();
		for(int i=H[t.x];i;i=X[i]){
			if(d[P[i]]>d[t.x]+E[i]){
				d[P[i]]=d[t.x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	printf("%lld",d[n]);
	return 0;
}
