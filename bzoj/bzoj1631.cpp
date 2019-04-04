#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int H[1005],X[100005],P[100005],E[100005],tot;
int _H[1005],_X[100005],_P[100005];
int n,m,x,y,z;
int aim;
int d1[1005],d2[1005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
	_P[tot]=x;_X[tot]=_H[y];_H[y]=tot;
}
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
int main(){
	scanf("%d%d%d",&n,&m,&aim);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	memset(d1,0x7f,sizeof d1);
	memset(d2,0x7f,sizeof d2);
	d1[aim]=d2[aim]=0;
	q.push(N(aim,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(d1[t.x]!=t.w) continue;
		for(int i=H[t.x];i;i=X[i]){
			if(d1[P[i]]>d1[t.x]+E[i]){
				d1[P[i]]=d1[t.x]+E[i];
				q.push(N(P[i],d1[P[i]]));
			}
		}
	}
	q.push(N(aim,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(d2[t.x]!=t.w) continue;
		for(int i=_H[t.x];i;i=_X[i]){
			if(d2[_P[i]]>d2[t.x]+E[i]){
				d2[_P[i]]=d2[t.x]+E[i];
				q.push(N(_P[i],d2[_P[i]]));
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=max(sum,d1[i]+d2[i]);
	}
	printf("%d\n",sum);
	return 0;
}
