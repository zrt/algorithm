#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int H[100005],X[1000005],P[1000005],E[1000005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
};
int n,m;
priority_queue<N> q;
int d[100005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	memset(d,0x3f,sizeof d);
	d[1]=0;q.push(N(1,0));
	while(!q.empty()){
		int x=q.top().x;q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(N(P[i],d[P[i]]));
			}
		}
	}
	printf("%d\n",d[n]);
	return 0;
}
