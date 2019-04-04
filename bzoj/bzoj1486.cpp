#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int H[3005],X[20005],P[20005],tot;
double E[20005];
double e[20005];
inline void add(int x,int y,double z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
double d[3005];
bool vis[3005];
bool dfs(int x){
	if(vis[x]) return 1;
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]>d[x]+e[i]){
			d[P[i]]=d[x]+e[i];
			if(dfs(P[i])) return 1;
		}
	}
	vis[x]=0;
	return 0;
}
bool judge(double ans){
	for(int i=1;i<=tot;i++) e[i]=E[i]-ans;
	for(int i=1;i<=n;i++) {
		memset(d,0,sizeof d);
		memset(vis,0,sizeof vis);
		if(dfs(i)) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	double z;
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d%lf",&x,&y,&z);
		add(x,y,z);
	}
	double l=-1e7-5,r=1e7+5;
	for(int t=0;t<60;t++){
		double mid=(l+r)/2;
		if(judge(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	printf("%.8f\n",r);
	return 0;
}
