#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int trans[17][17];
int H[70000],X[1400000],P[1400000],E[1400000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[70000],pre[70000],p[70000];
queue<int> q;
void print(int x){
	if(x==(1<<n)-1) return;
	print(pre[x]);
	printf("%01x",p[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) scanf("%d",&trans[i][j]);
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<m;j++){
			int to=0;
			for(int k=0;k<n;k++){
				if(i&(1<<k)){
					to|=(1<<trans[k][j]);
				}
			}
			add(i,to,j);
		}
	}
	d[(1<<n)-1]=1;
	q.push((1<<n)-1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]){
				pre[P[i]]=x;
				p[P[i]]=E[i];
				d[P[i]]=d[x]+1;q.push(P[i]);
			}
		}
	}
	if(!d[1]) puts("*");
	else print(1);
	return 0;
}
