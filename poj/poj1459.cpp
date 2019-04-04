/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<cstring>
inline int min(int x,int y){
	return x<y?x:y;
}
//by zrt
//problem:
using namespace std;
int H[105],flow[105][105];
int n,n1,n2,m,S,T;
int q[105],h,t,d[105];
bool bfs(){
	memset(d,-1,sizeof d);
	d[S]=1;h=t=0;
	q[t++]=S;int k;
	while(h!=t){
		k=q[h++];
		if(k==T) return true;
		for(int i=0;i<n+2;i++){
			if(i==k) continue;
			if(flow[k][i]>0&&(!~d[i])){
				d[i]=d[k]+1;
				q[t++]=i;
			}
		}
	}
	return false;
}
int find(int x,int flw){
	if(x==T||flw==0) return flw;
	int ret=0;int f;
	for(int i=0;i<n+2&&ret<flw;i++){
		if(i==x) continue;
		if(d[i]==d[x]+1&&flow[x][i]>0){
			f=find(i,min(flw-ret,flow[x][i]));
			flow[x][i]-=f;
			flow[i][x]+=f;
			ret+=f;
		}
	}
	return ret;
}
int Dinic(){
	int ret=0;
	while(bfs()){
		ret+=find(S,1<<30);
	}
	return ret;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d%d%d%d",&n,&n1,&n2,&m)){
		memset(flow,0,sizeof flow);
		int x,y,z;
		char c;
		for(int i=0;i<m;i++){
			while((c=getchar())!='(');
			scanf("%d,%d)%d",&x,&y,&z);
			flow[x][y]+=z;
		}
		S=n,T=n+1;
		for(int i=0;i<n1;i++){
			while((c=getchar())!='(');
			scanf("%d)%d",&x,&y);
			flow[S][x]+=y;
		}
		for(int i=0;i<n2;i++){
			while((c=getchar())!='(');
			scanf("%d)%d",&x,&y);
			flow[x][T]+=y;
		}
		printf("%d\n",Dinic());
	}
	return 0;
}
