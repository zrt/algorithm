#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int list[5005];
int H[5005],X[50005],P[50005],E[50005],tot;
int d[5005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int num;
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof d);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	scanf("%d",&num);
	for(int i=1;i<=num;i++) scanf("%d",&list[i]);
	int S=list[1],T=list[num];
	d[S]=0;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(P[i]);
			}
		}
	}
	for(int i=1;i<num;i++){
		for(int j=H[list[i]];j;j=X[j]){
			if(P[j]==list[i+1]){
				d[T]-=E[j];
			}
		}
	}
	printf("%d\n",-d[T]);
	return 0;
}
