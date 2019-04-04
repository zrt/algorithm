#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c[105][350][350];
int col[350][350];
int n,m;
inline int lowbit(int x){
	return x&-x;
}
void add(int x,int y,int k,int d){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=m;j+=lowbit(j)){
			c[k][i][j]+=d;
		}
	}
}
int ask(int x,int y,int k){
	int ret=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			ret+=c[k][i][j];
		}
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&col[i][j]),add(i,j,col[i][j],1);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t&1){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,col[x][y],-1);
			col[x][y]=z;
			add(x,y,col[x][y],1);
		}else{
			int x1,x2,y1,y2,k;
			scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&k);
			printf("%d\n",ask(x2,y2,k)-ask(x1-1,y2,k)-ask(x2,y1-1,k)+ask(x1-1,y1-1,k));
		}
	}
	return 0;
}
